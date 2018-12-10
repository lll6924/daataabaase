#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "RecordManager.h"
#include "BPlusTree.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <string>
#include <vector>
#include <memory.h>

std::string database,instruction;
std::vector<std::string> words;
bool error;
RecordManager* rm;
FileManager* fileManager;
BufPageManager* bufPageManager;

struct table{
  int place;
  std::string name;
};

std::vector<table> tables;

struct variable{
  std::string name;
  std::string type;
  int typeId,len;
  bool nullable=true;
  bool isprimarykey=false;
};

int getTypeId(std::string st){
  if(st=="float")return 1;
  if(st=="date")return 2;
  if(st=="int")return 3;
  if(st=="char")return 4;
  return 0;
}

std::string getTypeName(int typeId,int len){
  if(typeId==1)return "FLOAT";
  if(typeId==2)return "DATE";
  char s[20];
  if(typeId==3){
    sprintf(s,"INT(%d)",len);
    return s;
  }
  if(typeId==4){
    sprintf(s,"CHAR(%d)",len);
    return s;
  }
  return "UNKNOWN";
}

variable createVariable(std::string name, std::string type, int len, bool nullable=true){
  variable v;
  v.name=name;
  v.type=type;
  v.nullable=nullable;
  v.len=len;
  return v;
}

void squeeze(std::vector<std::string>& nw,std::vector<variable>& vs,int len){
  if(nw.size()==2){
    if(nw[0]!="primary"||nw[1]!="key"){
      vs.push_back(createVariable(nw[0],nw[1],len,true));
    }
  }else if(nw.size()==4){
    if(nw[2]=="not"&&nw[3]=="null"){
      vs.push_back(createVariable(nw[0],nw[1],len,false));
    }else if(error==false){
      printf("Syntax error!\n");
      error=true;
    }
  }else if(error==false){
    printf("Syntax error!\n");
    error=true;
  }
}

void inst(){
  std::transform(instruction.begin(), instruction.end(), instruction.begin(), ::tolower);
  words.clear();
  std::string now;
  now.clear();
  for(int i=0;i<instruction.length();i++){
    if(instruction[i]==' '){
      if(now.length()>0)words.push_back(now);
      now.clear();
    }else now.append(1,instruction[i]);
  }
  if(now.length()>0)words.push_back(now);
  do{
    if(words.size()==3){
      if(words[0]=="create"&&words[1]=="database"){
        std::string command = "mkdir -p " + words[2];
        system(command.c_str());
        std::string configfile=words[2] + "/.config";
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
        break;
      }
      if(words[0]=="drop"&&words[1]=="database"){
        std::string command = "rm -r " + words[2];
        system(command.c_str());
        break;
      }
      if(words[0]=="use"&&words[1]=="database"){
        database=words[2];
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
        break;
      }
      if(words[0]=="drop"&&words[1]=="table"){
        bool found=false;
        for(int i=0;i<tables.size();i++){
          if(tables[i].name==words[2]){
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
        break;
      }
      if(words[0]=="show"&&words[1]=="database"){
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
        break;
      }
      if(words[0]=="show"&&words[1]=="table"){
        std::string configfile=database + "/.config";
        bool found=false;
        for(int i=0;i<tables.size();i++){
          if(tables[i].name==words[2]){
            found=true;
            int theIndex;
            fileManager->openFile(configfile.c_str(),theIndex);
            int pageIndex;
            BufType page0=bufPageManager->getPage(theIndex,tables[i].place,pageIndex);
            for(int j=0;j<page0[0];j++){
              std::string name;
              name.erase();
              bool finish=false;
              for(int k=4;k<16;k++){
                int theInt=page0[1024+16*j+k];
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
              printf("%s %s %s %s\n",name.c_str(),getTypeName(page0[1024+16*j],page0[1024+16*j+1]).c_str(),
                page0[1024+16*j+2]==1?"NULLABLE":"",page0[1024+16*j+3]==1?"PRIMARY_KEY":"");
            }
            fileManager->closeFile(theIndex);
          }
        }
        if(found==false){
          printf("No such table!\n");
        }
        break;
      }
    }
    if(words.size()>2&&words[0]=="create"&&words[1]=="table"){
      std::string tableName;
      tableName.erase();
      for(int i=0;i<words[2].length();i++){
        if(words[2][i]=='(')break;
        tableName.append(1,words[2][i]);
      }
      int stage=0;
      error=false;
      std::string primarykey,nst;
      primarykey.erase();
      nst.erase();
      std::vector<std::string> nw;
      std::vector<variable> vs;
      vs.clear();
      nw.clear();
      bool entered=false;
      int len=0,lastkind;
      for(int i=2;i<words.size();i++){
        for(int j=0;j<words[i].length();j++){
          char c=words[i][j];
          if(c=='('){
            stage++;
            if(stage==1){
              if(error==false&&entered){
                printf("Syntax error!\n");
                error=true;
              }else entered=true;
            }
            if(stage==2){
              if(nst.length()>0)nw.push_back(nst);
              nst.erase();
              lastkind=-1;
              if(nw.size()==2&&nw[0]=="primary"&&nw[1]=="key")lastkind=0;
              if(nw.size()==2&&nw[1]=="int")lastkind=1;
              if(nw.size()==2&&nw[1]=="char")lastkind=2;
              if(lastkind==-1&&error==false){
                printf("Syntax error!\n");
                error=true;
              }
            }

          }
          else if(c==')'){
            stage--;
            if(stage==1){
              if(error==false&&lastkind==0&&nst.length()==0){
                printf("Empty primary key!\n");
                error=true;
              }
             if(error==false&&lastkind==0&&primarykey.length()!=0){
                printf("More than one primary key!\n");
                error=true;
              }
              if(lastkind==1||lastkind==2){
                len=0;
                for(int k=0;k<nst.length();k++){
                  char c=nst[k];
                  if((c>'9'||c<'0')&&error==false){
                    error=true;
                    printf("Invalid number!\n");
                  }
                  len=len*10+(c-'0');
                }
              }
              if(lastkind==0){
                primarykey=nst;
              }
              nst.erase();
            }
            if(stage==0){
              if(nst.length()>0)nw.push_back(nst);
              squeeze(nw,vs,len);
              len=0;
              nw.clear();
              nst.erase();
            }
          }
          else if(c==','){
            if(nst.length()>0)nw.push_back(nst);
            squeeze(nw,vs,len);
            len=0;
            nw.clear();
            nst.erase();
          }
          else{
            if(stage==0){
              if(entered&&error==false){
                printf("Syntax error!\n");
                error=true;
              }
            }else nst.append(1,c);
          }
        }
        if(nst.length()>0)nw.push_back(nst);
        nst.erase();
      }
      if(error==false&&vs.size()>64){
        printf("Too many variables!\n");
        error=true;
      }
      if(stage!=0&&error==false){
        printf("Syntax error!\n");
        error=true;
      }
      if(error==false){
        for(int i=0;i<vs.size();i++){
          vs[i].typeId=getTypeId(vs[i].type);
          vs[i].isprimarykey=false;
          if(vs[i].name==primarykey)vs[i].isprimarykey=true;
          if(error==false&&vs[i].typeId==0){
            printf("Invalid type!\n");
            error=true;
          }
          for(int j=i+1;j<vs.size();j++)
            if(error==false&&vs[i].name==vs[j].name){
              printf("Name conflict!\n");
              error=true;
            }
        }
        if(error==false){
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
            tb.name=tableName;
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
            page0[0]++;
            page1[0]=vs.size();
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
          /*for(int i=0;i<vs.size();i++){
            printf("%s %d %d %d %d\n",vs[i].name.c_str(),vs[i].typeId,vs[i].len,int(vs[i].nullable),int(vs[i].isprimarykey));
          }*/
          break;
        }
      }
    }
    printf("Invalid instruction!\n");
  }while(0);
}

int main() {
  rm=new RecordManager();
  fileManager=rm->getFileManager();
  bufPageManager=rm->getBufPageManager();
  srand(time(0));
  std::string rd;
  instruction.erase();
  database.erase();
  while(true){
    printf("%s->",database.length()?database.c_str():"NULL");
    std::getline(std::cin,rd);
    for(int i=0;i<rd.length();i++)
      if(rd[i]==';'){
        inst();
        instruction.erase();
      }else instruction.append(1,rd[i]);
    instruction.append(" ");
  }
	return 0;
}
