//
//  handler.cpp
//  
//
//  Created by 赖金霖 on 2018/12/27.
//

#include "handler.h"
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "RecordManager.h"
#include "BPlusTree.h"

std::string database;
RecordManager* rm;
FileManager* fileManager;
BufPageManager* bufPageManager;

struct table{
  int place;
  std::string name;
};

std::vector<table> tables;

void init(){
  rm=new RecordManager();
  fileManager=rm->getFileManager();
  bufPageManager=rm->getBufPageManager();
  srand(time(0));
  std::string rd;
  instruction.erase();
  database.erase();
}

void Handler::accept(){
  
}

void ShowDatabases::accept(){
  
}

void CreateDatabase::accept(){
  std::string command = "mkdir -p " + dbname;
  system(command.c_str());
  std::string configfile=dbname + "/.config";
  printf("%s\n",configfile.c_str());
  fileManager->createFile(configfile.c_str());
  int theIndex;
  fileManager->openFile(configfile.c_str(),theIndex);
  int pageIndex;
  BufType page0=bufPageManager->allocPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  page0[0]=0;
  page0[1]=1;
  bufPageManager->writeBack(pageIndex);
  fileManager->closeFile(theIndex);
}

void DropDatabase::accept(){
  std::string command = "rm -r " + dbname;
  system(command.c_str());
}

void UseDatabase::accept(){
  database=dbname;
  tables.clear();
  std::string configfile=database + "/.config";
  int theIndex;
  fileManager->openFile(configfile.c_str(),theIndex);
  int pageIndex;
  BufType page0=bufPageManager->allocPage(theIndex,0,pageIndex);
  table tb;
  for(int i=0;i<page0[0];i++){
    tb.place=page0[i*64+64];
    bool finish=false;
    for(int j=1;j<128;j++){
      int theInt=page0[i*64+64+j];
      tb.name.erase();
      for(int k=0;k<4;k++){
        if(theInt%256==0){
          finish=true;
          break;
        }
        tb.name.append(1,char(theInt%256));
        theInt/=256;
      }
      if(finish)break;
    }
    tables.push_back(tb);
  }
  fileManager->closeFile(theIndex);
}

void ShowTables::accept(){
  std::string configfile=database + "/.config";
  int theIndex;
  fileManager->openFile(configfile.c_str(),theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  std::string tablename;
  for(int i=0;i<page0[0];i++){
    bool finish=false;
    for(int j=1;j<128;j++){
      int theInt=page0[i*64+64+j];
      tablename.erase();
      for(int k=0;k<4;k++){
        if(theInt%256==0){
          finish=true;
          break;
        }
        tablename.append(1,char(theInt%256));
        theInt/=256;
      }
      if(finish)break;
    }
    printf("%s\n",tablename.c_str());
  }
  fileManager->closeFile(theIndex);
}

void CreateTable::accept(){
  std::string configfile=database + "/.config";
  int theIndex;
  fileManager->openFile(configfile.c_str(),theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  if(page0[0]==64){
    printf("Too many tables!\n");
  }else{
    table tb;
    tb.name=tbname;
    tb.place=page0[0]+1;
    tables.push_back(tb);
    page0[64*tables.size()]=tb.place;
    for(int i=0;i<tableName.length()+4;i++){
      if(i%4==3){
        int toins=0;
        for(int k=0;k<4;k++)
          toins=toins*256+(i-k<tableName.length()?tableName[i-k]:0);
        page0[tables.size()*64+1+i/4]=toins;
      }
    }
    int pageIndex;
    if(page0[0]+1>=page0[1]){
      BufType page1=bufPageManager->allocPage(theIndex,page0[1],pageIndex);
      page0[1]++;
      bufPageManager->markDirty(pageIndex);
    }
    BufType page1=bufPageManager->allocPage(theIndex,page0[0]+1,pageIndex);
    bufPageManager->markDirty(pageIndex);
    for(int i=0;i<fields.size();i--){
      if(fields[i].type==Field::primarykey){
      
      }
    }
    page0[0]++;
    page1[0]=fields.size();
    for(int i=0;i<vs.size();i++){
      //printf("%d\n",i);
      page1[i*16+1024]=vs[i].typeId;
      page1[i*16+1024+1]=vs[i].len;
      page1[i*16+1024+2]=int(vs[i].nullable);
      page1[i*16+1024+3]=int(vs[i].isprimarykey);
      for(int j=0;j<vs[i].name.length()+4;j++){
        //printf("%d\n",j);
        if(j%4==3){
          int toins=0;
          for(int k=0;k<4;k++)
            toins=toins*256+(j-k<vs[i].name.length()?vs[i].name[j-k]:0);
          page1[i*16+1024+4+j/4]=toins;
        }
      }
    }
    bufPageManager->writeBack(pageIndex);
  }
  bufPageManager->writeBack(pageIndex);
  fileManager->closeFile(theIndex);
}

void DropTable::accept(){
  bool found=false;
  for(int i=0;i<tables.size();i++){
    if(tables[i].name==tbname){
      found=true;
      std::string configfile=database + "/.config";
      int theIndex;
      fileManager->openFile(configfile.c_str(),theIndex);
      int pageIndex,pageIndex1,pageIndex2;
      BufType page00=bufPageManager->getPage(theIndex,0,pageIndex);
      bufPageManager->markDirty(pageIndex);
      BufType page0=bufPageManager->getPage(theIndex,tables[i].place,pageIndex1);
      bufPageManager->markDirty(pageIndex1);
      BufType page1=bufPageManager->getPage(theIndex,tables.size(),pageIndex2);
      bufPageManager->markDirty(pageIndex2);

      memcpy(page0,page1,PAGE_SIZE);
      tables[tables.size()-1].place=tables[i].place;
      tables[i]=tables[tables.size()-1];
      tables.pop_back();
      page00[0]--;
      bufPageManager->writeBack(pageIndex1);
      bufPageManager->writeBack(pageIndex);
      fileManager->closeFile(theIndex);
    }
  }
  if(found==false){
    printf("No such table!\n");
  }
}

void DescTable::accept(){

}

void InsertValue::accept(){

}

void DeleteValues::accept(){

}

void UpdateValues::accept(){

}

void SelectValues::accept(){

}

void CreateIndex::accept(){

}

void DropIndex::accept(){

}

CreateDatabase::CreateDatabase(std::string dbname){
  this->dbname=dbname;
}

DropDatabase::DropDatabase(std::string dbname){
  this->dbname=dbname;
}

UseDatabase::UseDatabase(std::string dbname){
  this->dbname=dbname;
}

CreateTable::CreateTable(std::string tbname, std::vector<Field> fields){
  this->tbname=tbname;
  this->fields=fields;
}

DropTable::DropTable(std::string tbname){
  this->tbname=tbname;
}

DescTable::DescTable(std::string tbname){
  this->tbname=tbname;
}

InsertValue::InsertValue(std::string tbname, std::vector<std::vector<Value> > values){
  this->tbname=tbname;
  this->values=values;
}

DeleteValues::DeleteValues(std::string tbname, std::vector<WhereItem> wheres){
  this->tbname=tbname;
  this->wheres=wheres;
}

UpdateValues::UpdateValues(std::string tbname, std::vector<Set> sets, std::vector<WhereItem> wheres){
  this->tbname=tbname;
  this->sets=sets;
  this->wheres=wheres;
}

SelectValues::SelectValues(Selector selector, std::vector<std::string> tables, std::vector<WhereItem> wheres){
  this->selector=selector;
  this->tables=tables;
  this->wheres=wheres;
}

CreateIndex::CreateIndex(std::string tbname, std::string colname){
  this->tbname=tbname;
  this->colname=colname;
}

DropIndex::DropIndex(std::string tbname, std::string colname){
  this->tbname=tbname;
  this->colname=colname;
}
