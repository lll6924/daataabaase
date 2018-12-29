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

std::string getdatabase(){
  return database;
}

struct table{
  int place;
  std::string name;
};

std::vector<table> tables;

std::string getTypeName(int typeId,int len){
  if(typeId==Type::_FLOAT)return "FLOAT";
  if(typeId==Type::_DATE)return "DATE";
  char s[20];
  if(typeId==Type::_INT){
    sprintf(s,"INT(%d)",len);
    return s;
  }
  if(typeId==Type::_CHAR){
    sprintf(s,"CHAR(%d)",len);
    return s;
  }
  return "UNKNOWN";
}

void init(){
  rm=new RecordManager();
  fileManager=rm->getFileManager();
  bufPageManager=rm->getBufPageManager();
  srand(time(0));
  std::string rd;
  database.erase();
}

void Handler::accept(){
  
}

void checkglobalconfig(){
  FILE* file;
  if((file=fopen(".config","rb"))==NULL){
    fileManager->createFile(".config");
    int theIndex;
    fileManager->openFile(".config",theIndex);
    int pageIndex;
    BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
    bufPageManager->markDirty(pageIndex);
    page0[0]=0;
    bufPageManager->writeBack(pageIndex);
    fileManager->closeFile(theIndex);
  }else fclose(file);
}

void ShowDatabases::accept(){
  checkglobalconfig();
  int theIndex;
  fileManager->openFile(".config",theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  printf("%d\n",page0[0]);
  for(int i=0;i<page0[0];i++){
    std::string name;
    name.erase();
    bool finish=false;
    for(int k=0;k<8;k++){
      int theInt=page0[256+16*i+k];
      for(int l=0;l<4;l++){
        if(theInt%256==0){
          finish=true;
          break;
        }
        name.append(1,char(theInt%256));
        theInt/=256;
      }
      if(finish)break;
    }
    printf("%s\n",name.c_str());
  }
  bufPageManager->writeBack(pageIndex);
  fileManager->closeFile(theIndex);
}

void CreateDatabase::accept(){
  checkglobalconfig();
  if(dbname.length()>32){
    printf("Too long database name\n");
    return;
  }
  
  int theIndex;
  fileManager->openFile(".config",theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  page0[0]++;
  for(int j=0;j<dbname.length()+4;j++){
    if(j%4==3){
      int toins=0;
      for(int k=0;k<4;k++)
        toins=toins*256+(j-k<dbname.length()?dbname[j-k]:0);
      page0[(page0[0]-1)*16+256+j/4]=toins;
    }
  }
  bufPageManager->writeBack(pageIndex);
  fileManager->closeFile(theIndex);
  
  std::string command = "mkdir -p " + dbname;
  system(command.c_str());
  std::string configfile=dbname + "/.config";
  fileManager->createFile(configfile.c_str());
  fileManager->openFile(configfile.c_str(),theIndex);
  page0=bufPageManager->getPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  page0[0]=0;
  page0[1]=1;
  bufPageManager->writeBack(pageIndex);
  fileManager->closeFile(theIndex);
}

void DropDatabase::accept(){
  checkglobalconfig();
  int theIndex;
  fileManager->openFile(".config",theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  bool found=false;
  for(int i=0;i<page0[0];i++){
    std::string name;
    name.erase();
    bool finish=false;
    for(int k=0;k<8;k++){
      int theInt=page0[256+16*i+k];
      for(int l=0;l<4;l++){
        if(theInt%256==0){
          finish=true;
          break;
        }
        name.append(1,char(theInt%256));
        theInt/=256;
      }
      if(finish)break;
    }
    if(name==dbname){
      found=true;
      memcpy(page0+256+i*16,page0+256+(page0[0]-1)*16,16);
      break;
    }
  }
  if(found==false){
    printf("No such database!\n");
    bufPageManager->writeBack(pageIndex);
    fileManager->closeFile(theIndex);
    return;
  }
  page0[0]--;
  bufPageManager->writeBack(pageIndex);
  fileManager->closeFile(theIndex);
  std::string command = "rm -r " + dbname;
  system(command.c_str());
}

void UseDatabase::accept(){
  checkglobalconfig();
  database=dbname;
  tables.clear();
  std::string configfile=database + "/.config";
  int theIndex;
  fileManager->openFile(configfile.c_str(),theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  table tb;
  for(int i=0;i<page0[0];i++){
    tb.place=page0[i*64+64];
    bool finish=false;
    tb.name.erase();
    for(int j=1;j<64;j++){
      int theInt=page0[i*64+64+j];
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
  for(int i=0;i<tables.size();i++)
    printf("%s\n",tables[i].name.c_str());
}

void CreateTable::accept(){
  for(int i=0;i<tables.size();i++)
    if(tbname==tables[i].name){
      printf("Repeated table name!\n");
      return;
    }
  std::string configfile=database + "/.config";
  int theIndex;
  fileManager->openFile(configfile.c_str(),theIndex);
  int pageIndex;
  BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
  bufPageManager->markDirty(pageIndex);
  for(int j=0;j<fields.size();j++){
    fields[j].isprimarykey=false;
    if(fields[j].type!=Field::primarykey&&fields[j].colName.length()>32){
      bufPageManager->writeBack(pageIndex);
      fileManager->closeFile(theIndex);
      printf("Column name too long!\n");
      return;
    }
    for(int i=j+1;i<fields.size();i++)
      if(fields[j].type==Field::column&&fields[i].type==Field::column&&fields[j].colName==fields[i].colName){
        bufPageManager->writeBack(pageIndex);
        fileManager->closeFile(theIndex);
        printf("Repeated column name!\n");
        return;
      }
  }
  int columncnt=fields.size();
  for(int i=0;i<fields.size();i++){
    if(fields[i].type==Field::primarykey){
      columncnt--;
      for(int j=0;j<fields[i].columns.size();j++)
        for(int k=j+1;k<fields[i].columns.size();k++)
          if(fields[i].columns[j]==fields[i].columns[k]){
            bufPageManager->writeBack(pageIndex);
            fileManager->closeFile(theIndex);
            printf("Repeated primary keys!\n");
            return;
          }
      for(int j=0;j<fields[i].columns.size();j++){
        bool found=false;
        for(int k=0;k<fields.size();k++)
          if(fields[k].type==Field::column&&fields[k].colName==fields[i].columns[j]){
            found=true;
            fields[k].isprimarykey=true;
            break;
          }
        if(!found){
          bufPageManager->writeBack(pageIndex);
          fileManager->closeFile(theIndex);
          printf("Invalid primary key!\n");
          return;
        }
      }
    }else if(fields[i].type==Field::foreignkey){
      bool found=false;
      for(int i2=0;i2<tables.size();i2++){
        if(tables[i2].name==fields[i].reftable){
          int pageIndex;
          BufType page0=bufPageManager->getPage(theIndex,tables[i2].place,pageIndex);
          for(int j=0;j<page0[0];j++){
            std::string name;
            name.erase();
            bool finish=false;
            for(int k=4;k<16;k++){
              int theInt=page0[1024+64*j+k];
              for(int l=0;l<4;l++){
                if(theInt%256==0){
                  finish=true;
                  break;
                }
                name.append(1,char(theInt%256));
                theInt/=256;
              }
              if(finish)break;
            }
            if(name==fields[i].refcolumn){
              if(page0[1024+64*j+3]==0){
                printf("Foreign key is not primary key!\n");
                bufPageManager->writeBack(pageIndex);
                fileManager->closeFile(theIndex);
                return;
              }
              found=true;
              fields[i].thetype.typeId=page0[1024+64*j];
              fields[i].thetype.len=page0[1024+64*j+1];
            }
          }
        }
      }
      if(found==false){
        bufPageManager->writeBack(pageIndex);
        fileManager->closeFile(theIndex);
        printf("Invalid foreign key!\n");
        return;
      }
    }
  }
  if(page0[0]==16){
    printf("Too many tables!\n");
  }else{
    table tb;
    tb.name=tbname;
    tb.place=page0[0]+1;
    tables.push_back(tb);
    page0[64*tables.size()]=tb.place;
    for(int i=0;i<tbname.length()+4;i++){
      if(i%4==3){
        int toins=0;
        for(int k=0;k<4;k++)
          toins=toins*256+(i-k<tbname.length()?tbname[i-k]:0);
        page0[tables.size()*64+1+i/4]=toins;
      }
    }
    int pageIndex;
    if(page0[0]+1>=page0[1]){
      BufType page1=bufPageManager->getPage(theIndex,page0[1],pageIndex);
      page0[1]++;
      bufPageManager->markDirty(pageIndex);
    }
    BufType page1=bufPageManager->getPage(theIndex,page0[0]+1,pageIndex);
    bufPageManager->markDirty(pageIndex);
    page0[0]++;
    page1[0]=columncnt;
    int recordLength=0;
    for(int i=0;i<fields.size();i++)
      if(fields[i].type!=Field::primarykey){
        recordLength+=getSizeLength(fields[i].thetype);
        //printf("%d\n",i);
        page1[i*64+1024]=fields[i].thetype.typeId;
        page1[i*64+1024+1]=fields[i].thetype.len;
        page1[i*64+1024+2]=int(fields[i].Nullable);
        page1[i*64+1024+3]=int(fields[i].isprimarykey);
        for(int j=0;j<fields[i].colName.length()+4;j++){
          //printf("%d\n",j);
          if(j%4==3){
            int toins=0;
            for(int k=0;k<4;k++)
              toins=toins*256+(j-k<fields[i].colName.length()?fields[i].colName[j-k]:0);
            page1[i*64+1024+4+j/4]=toins;
          }
        }
        page1[i*64+1024+16]=int(fields[i].type==Field::foreignkey);
        if(fields[i].type==Field::foreignkey){
          for(int j=0;j<fields[i].reftable.length()+4;j++){
            if(j%4==3){
              int toins=0;
              for(int k=0;k<4;k++)
                toins=toins*256+(j-k<fields[i].reftable.length()?fields[i].reftable[j-k]:0);
              page1[i*64+1024+20+j/4]=toins;
            }
          }
          for(int j=0;j<fields[i].refcolumn.length()+4;j++){
            if(j%4==3){
              int toins=0;
              for(int k=0;k<4;k++)
                toins=toins*256+(j-k<fields[i].refcolumn.length()?fields[i].refcolumn[j-k]:0);
              page1[i*64+1024+32+j/4]=toins;
            }
          }
        }
      }
    bufPageManager->writeBack(pageIndex);
    std::string sqlfile=database+"/"+tbname;
    rm->createFile(sqlfile,recordLength);
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
      memcpy(page00+1+64+i*64,page00+1+64+(tables.size()-1)*64,64);
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
  std::string configfile=database + "/.config";
  bool found=false;
  for(int i=0;i<tables.size();i++){
    if(tables[i].name==tbname){
      found=true;
      int theIndex;
      fileManager->openFile(configfile.c_str(),theIndex);
      int pageIndex;
      BufType page0=bufPageManager->getPage(theIndex,tables[i].place,pageIndex);
      for(int j=0;j<page0[0];j++){
        std::string name;
        std::string reftable;
        std::string refcolumn;
        name.erase();
        reftable.erase();
        refcolumn.erase();
        bool finish=false;
        for(int k=4;k<16;k++){
          int theInt=page0[1024+64*j+k];
          for(int l=0;l<4;l++){
            if(theInt%256==0){
              finish=true;
              break;
            }
            name.append(1,char(theInt%256));
            theInt/=256;
          }
          if(finish)break;
        }
        finish=false;
        for(int k=20;k<32;k++){
          int theInt=page0[1024+64*j+k];
          for(int l=0;l<4;l++){
            if(theInt%256==0){
              finish=true;
              break;
            }
            reftable.append(1,char(theInt%256));
            theInt/=256;
          }
          if(finish)break;
        }
        finish=false;
        for(int k=32;k<48;k++){
          int theInt=page0[1024+64*j+k];
          for(int l=0;l<4;l++){
            if(theInt%256==0){
              finish=true;
              break;
            }
            refcolumn.append(1,char(theInt%256));
            theInt/=256;
          }
          if(finish)break;
        }
        printf("%s %s %s %s %s %s %s\n",name.c_str(),getTypeName(page0[1024+64*j],page0[1024+64*j+1]).c_str(),
          page0[1024+64*j+2]==1?"NULLABLE":"",page0[1024+64*j+3]==1?"PRIMARY_KEY":"",page0[1024+64*j+16]==1?"FOREIGN_KEY":"",page0[1024+64*j+16]==1?reftable.c_str():"",page0[1024+64*j+16]==1?refcolumn.c_str():"");
      }
      fileManager->closeFile(theIndex);
    }
  }
}

bool canassign(int type,int valuetype){
  if(valuetype==Value::_NULL)return true;
  if(type==Type::_FLOAT&&valuetype==Value::_FLOAT)return true;
  if(type==Type::_FLOAT&&valuetype==Value::_INT)return true;
  if(type==Type::_INT&&valuetype==Value::_INT)return true;
  if(type==Type::_STRING&&valuetype==Value::_STRING)return true;
  if(type==Type::_DATE&&valuetype==Value::_DATE)return true;
  return false;
}

void getColumnRange(std::string table,std::string column,int& l,int& r){

}

char* Value::toString(){
  
}

void InsertValue::accept(){
  bool found=false;
  for(int i=0;i<tables.size();i++){
    if(tables[i].name==tbname){
      found=true;
      std::string configfile=database + "/.config";
      int theIndex;
      fileManager->openFile(configfile.c_str(),theIndex);
      int pageIndex;
      BufType page0=bufPageManager->getPage(theIndex,tables[i].place,pageIndex);
      for(int i=0;i<values.size();i++)
        if(values[i].size!=page0[0]){
          printf("Incompatible value list!\n");
          bufPageManager->writeBack(pageIndex);
          fileManager->closeFile(theIndex);
          return;
        }
      for(int j=0;j<page0[0];j++){
        for(int k=0;k<values.size();k++){
          if((page0[j*64+1024+2]==0&&values[k][j].type==Value::_NULL)||!canassign(page0[j*64+1024],values[k][j].type)){
            printf("Incompatible value list!\n");
            bufPageManager->writeBack(pageIndex);
            fileManager->closeFile(theIndex);
            return;
          }
        }
        if(page0[64*j+1024+16]!=0){
          std::string reftable;
          std::string refcolumn;
          reftable.erase();
          refcolumn.erase();
          bool finish=false;
          for(int k=20;k<32;k++){
            int theInt=page0[1024+64*j+k];
            for(int l=0;l<4;l++){
              if(theInt%256==0){
                finish=true;
                break;
              }
              reftable.append(1,char(theInt%256));
              theInt/=256;
            }
            if(finish)break;
          }
          finish=false;
          for(int k=32;k<48;k++){
            int theInt=page0[1024+64*j+k];
            for(int l=0;l<4;l++){
              if(theInt%256==0){
                finish=true;
                break;
              }
              refcolumn.append(1,char(theInt%256));
              theInt/=256;
            }
            if(finish)break;
          }
          std::string reffile=database+"/"+reftable;
          int ref=rm->openFile(reffile),l,r;
          getColumnRange(reftable,refcolumn,l,r);
          for(int k=0;k<values.size();k++){
            std::vector<char*> ret=rm->filterRecord(ref,l,r,values[k][j].toString(),new EqualFilter());
            if(ret.size()==0){
              printf("Invalid foreign key!\n");
              rm->closeFile(ref);
              fileManager->closeFile(theIndex);
              return;
            }
          }
          rm->closeFile(ref);
        }
      }
      fileManager->closeFile(theIndex);
    }
  }
  if(found==false){
    printf("No such table!\n");
  }
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
