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

bool doOperation(Value v1,int op,Value v2){
  if(v1.type==Value::_NULL||v2.type==Value::_NULL)return true;
  if(v1.type==Value::_STRING){
    if(op==WhereItem::_EQUAL)return v1.stringValue==v2.stringValue;
    if(op==WhereItem::_NOT_EQUAL)return v1.stringValue!=v2.stringValue;
    if(op==WhereItem::_LESS_OR_EQUAL)return v1.stringValue<=v2.stringValue;
    if(op==WhereItem::_MORE_OR_EQUAL)return v1.stringValue>=v2.stringValue;
    if(op==WhereItem::_LESS)return v1.stringValue<v2.stringValue;
    if(op==WhereItem::_MORE)return v1.stringValue>v2.stringValue;
    return false;
  }
  if(v1.type==Value::_DATE){
    if(op==WhereItem::_EQUAL)return v1.dateValue==v2.dateValue;
    if(op==WhereItem::_NOT_EQUAL)return v1.dateValue!=v2.dateValue;
    if(op==WhereItem::_LESS_OR_EQUAL)return v1.dateValue<=v2.dateValue;
    if(op==WhereItem::_MORE_OR_EQUAL)return v1.dateValue>=v2.dateValue;
    if(op==WhereItem::_LESS)return v1.dateValue<v2.dateValue;
    if(op==WhereItem::_MORE)return v1.dateValue>v2.dateValue;
    return false;
  }
  if(v1.type==Value::_INT&&v2.type==Value::_INT){
    if(op==WhereItem::_EQUAL)return v1.intValue==v2.intValue;
    if(op==WhereItem::_NOT_EQUAL)return v1.intValue!=v2.intValue;
    if(op==WhereItem::_LESS_OR_EQUAL)return v1.intValue<=v2.intValue;
    if(op==WhereItem::_MORE_OR_EQUAL)return v1.intValue>=v2.intValue;
    if(op==WhereItem::_LESS)return v1.intValue<v2.intValue;
    if(op==WhereItem::_MORE)return v1.intValue>v2.intValue;
    return false;
  }
  if(v1.type==Value::_INT&&v2.type==Value::_FLOAT){
    if(op==WhereItem::_EQUAL)return v1.intValue==v2.floatValue;
    if(op==WhereItem::_NOT_EQUAL)return v1.intValue!=v2.floatValue;
    if(op==WhereItem::_LESS_OR_EQUAL)return v1.intValue<=v2.floatValue;
    if(op==WhereItem::_MORE_OR_EQUAL)return v1.intValue>=v2.floatValue;
    if(op==WhereItem::_LESS)return v1.intValue<v2.floatValue;
    if(op==WhereItem::_MORE)return v1.intValue>v2.floatValue;
    return false;
  }
  if(v1.type==Value::_FLOAT&&v2.type==Value::_INT){
    if(op==WhereItem::_EQUAL)return v1.floatValue==v2.intValue;
    if(op==WhereItem::_NOT_EQUAL)return v1.floatValue!=v2.intValue;
    if(op==WhereItem::_LESS_OR_EQUAL)return v1.floatValue<=v2.intValue;
    if(op==WhereItem::_MORE_OR_EQUAL)return v1.floatValue>=v2.intValue;
    if(op==WhereItem::_LESS)return v1.floatValue<v2.intValue;
    if(op==WhereItem::_MORE)return v1.floatValue>v2.intValue;
    return false;
  }
  if(v1.type==Value::_FLOAT&&v2.type==Value::_FLOAT){
    if(op==WhereItem::_EQUAL)return v1.floatValue==v2.floatValue;
    if(op==WhereItem::_NOT_EQUAL)return v1.floatValue!=v2.floatValue;
    if(op==WhereItem::_LESS_OR_EQUAL)return v1.floatValue<=v2.floatValue;
    if(op==WhereItem::_MORE_OR_EQUAL)return v1.floatValue>=v2.floatValue;
    if(op==WhereItem::_LESS)return v1.floatValue<v2.floatValue;
    if(op==WhereItem::_MORE)return v1.floatValue>v2.floatValue;
    return false;
  }
  return false;
}

int getSizeLength(Type type){
  if(type.typeId==Type::_FLOAT)return 4;
  if(type.typeId==Type::_DATE)return 4;
  if(type.typeId==Type::_INT)return 4;
  if(type.typeId==Type::_CHAR)return 4+type.len/4*4;
  return 0;
}

void printValue(Value value){
  std::string toprint;
  std::ostringstream oss;
  if(value.type==Value::_INT){
    oss<<value.intValue;
  }
  if(value.type==Value::_STRING){
    oss<<value.stringValue;
  }
  if(value.type==Value::_NULL){
    oss<<"NULL";
  }
  if(value.type==Value::_FLOAT){
    oss<<value.floatValue;
  }
  if(value.type==Value::_DATE){
    oss<<value.dateValue/10000<<"-"<<value.dateValue%10000/100<<"-"<<value.dateValue%100;
  }
  toprint=oss.str();
  if(toprint.length()>20){
    toprint.erase(0,toprint.length()-17);
    toprint="..."+toprint;
  }
  while(toprint.length()<20)
    toprint=toprint+" ";
  printf("%s",toprint.c_str());
}

union val{
  unsigned int i;
  float f;
};

Value extractValue(const char* record,int left,int right,Type type){
  Value ret;
  bool isnull=true;
  for(int i=left;i<right;i++)
    if(record[i]!=-1){
      isnull=false;
      break;
    }
  if(isnull){
    ret.type=Value::_NULL;
    return ret;
  }
  val unionvalue;
  unionvalue.i=0;
  for(int i=left;i<left+4;i++)
    unionvalue.i=unionvalue.i*256+(unsigned int)record[i];
  if(type.typeId==Type::_FLOAT){
    ret.type=Value::_FLOAT;
    ret.floatValue=unionvalue.f;
  }
  if(type.typeId==Type::_INT){
    ret.type=Value::_INT;
    ret.intValue=unionvalue.i;
  }
  if(type.typeId==Type::_CHAR){
    ret.type=Value::_STRING;
    char* ch=new char[unionvalue.i+1];
    memcpy(ch,record+left,unionvalue.i);
    ch[unionvalue.i]='\0';
    ret.stringValue=ch;
  }
  if(type.typeId==Type::_DATE){
    ret.type=Value::_DATE;
    ret.dateValue=unionvalue.i;
  }
  return ret;
}

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

std::vector<Field> getColumns(std::string table){
  std::string configfile=database+"/.config";
  std::vector<Field> ret;
  ret.clear();
  for(int i=0;i<tables.size();i++){
    if(tables[i].name==table){
      int theIndex;
      fileManager->openFile(configfile.c_str(),theIndex);
      int pageIndex;
      BufType page0=bufPageManager->getPage(theIndex,tables[i].place,pageIndex);
      for(int j=0;j<page0[0];j++){
        Field field;
        field.colName.erase();
        field.reftable.erase();
        field.refcolumn.erase();
        bool finish=false;
        for(int k=4;k<16;k++){
          int theInt=page0[1024+64*j+k];
          for(int l=0;l<4;l++){
            if(theInt%256==0){
              finish=true;
              break;
            }
            field.colName.append(1,char(theInt%256));
            theInt/=256;
          }
          if(finish)break;
        }
        if(page0[1024+64*j+16]){
          field.type=Field::foreignkey;
          finish=false;
          for(int k=20;k<32;k++){
            int theInt=page0[1024+64*j+k];
            for(int l=0;l<4;l++){
              if(theInt%256==0){
                finish=true;
                break;
              }
              field.reftable.append(1,char(theInt%256));
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
              field.refcolumn.append(1,char(theInt%256));
              theInt/=256;
            }
            if(finish)break;
          }
        }else field.type=Field::column;
        field.left=page0[1024+64*j+17];
        field.right=page0[1024+64*j+18];
        field.isprimarykey=(page0[1024+64*j+3]==1);
        field.Nullable=(page0[1024+64*j+2]==1);
        field.thetype.typeId=page0[1024+64*j];
        field.thetype.len=page0[1024+64*j+1];
        ret.push_back(field);
      }
      fileManager->closeFile(theIndex);
    }
  }
  return ret;
}

bool getColumn(std::string table,std::string column,Field& field){
  std::string configfile=database+"/.config";
  bool found=false;
  for(int i=0;i<tables.size();i++){
    if(tables[i].name==table){
      int theIndex;
      fileManager->openFile(configfile.c_str(),theIndex);
      int pageIndex;
      BufType page0=bufPageManager->getPage(theIndex,tables[i].place,pageIndex);
      for(int j=0;j<page0[0];j++){
        field.colName.erase();
        field.reftable.erase();
        field.refcolumn.erase();
        bool finish=false;
        for(int k=4;k<16;k++){
          int theInt=page0[1024+64*j+k];
          for(int l=0;l<4;l++){
            if(theInt%256==0){
              finish=true;
              break;
            }
            field.colName.append(1,char(theInt%256));
            theInt/=256;
          }
          if(finish)break;
        }
        if(field.colName!=column)continue;
        found=true;
        if(page0[1024+64*j+16]){
          field.type=Field::foreignkey;
          finish=false;
          for(int k=20;k<32;k++){
            int theInt=page0[1024+64*j+k];
            for(int l=0;l<4;l++){
              if(theInt%256==0){
                finish=true;
                break;
              }
              field.reftable.append(1,char(theInt%256));
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
              field.refcolumn.append(1,char(theInt%256));
              theInt/=256;
            }
            if(finish)break;
          }
        }else field.type=Field::column;
        field.left=page0[1024+64*j+17];
        field.right=page0[1024+64*j+18];
        field.isprimarykey=(page0[1024+64*j+3]==1);
        field.Nullable=(page0[1024+64*j+2]==1);
        field.thetype.typeId=page0[1024+64*j];
        field.thetype.len=page0[1024+64*j+1];
      }
      fileManager->closeFile(theIndex);
    }
  }
  if(found==false){
    printf("No such table or column!\n");
  }
  return found;
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
      Field foreigncolumn;
      if(getColumn(fields[i].reftable,fields[i].refcolumn,foreigncolumn)){
        if(!foreigncolumn.isprimarykey){
          printf("Foreign key is not primary key!\n");
          bufPageManager->writeBack(pageIndex);
          fileManager->closeFile(theIndex);
          return;
        }
      }else{
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
        int columnLength=getSizeLength(fields[i].thetype);
        page1[i*64+1024+17]=recordLength;
        recordLength+=getSizeLength(fields[i].thetype);
        page1[i*64+1024+18]=recordLength;
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
    rm->createFile(sqlfile.c_str(),recordLength);
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
  std::vector<Field> columns=getColumns(tbname);
  for(int i=0;i<columns.size();i++){
    printf("%s %s %s %s %s %s %s\n",columns[i].colName.c_str(),getTypeName(columns[i].thetype.typeId,columns[i].thetype.len).c_str(),
          columns[i].Nullable?"NULLABLE":"",columns[i].isprimarykey?"PRIMARY_KEY":"",columns[i].type==Field::foreignkey?"FOREIGN_KEY":"",columns[i].type==Field::foreignkey?columns[i].reftable.c_str():"",columns[i].type==Field::foreignkey?columns[i].refcolumn.c_str():"");
  }
}

bool canassign(int type,int valuetype){
  if(valuetype==Value::_NULL)return true;
  if(type==Type::_FLOAT&&valuetype==Value::_FLOAT)return true;
  if(type==Type::_FLOAT&&valuetype==Value::_INT)return true;
  if(type==Type::_INT&&valuetype==Value::_INT)return true;
  if(type==Type::_CHAR&&valuetype==Value::_STRING)return true;
  if(type==Type::_DATE&&valuetype==Value::_DATE)return true;
  return false;
}

bool cancompare(int type,int type2){
  if(type==Type::_FLOAT&&type2==Type::_FLOAT)return true;
  if(type==Type::_FLOAT&&type2==Type::_INT)return true;
  if(type==Type::_INT&&type2==Type::_FLOAT)return true;
  if(type==Type::_INT&&type2==Type::_INT)return true;
  if(type==Type::_CHAR&&type2==Type::_CHAR)return true;
  if(type==Type::_DATE&&type2==Type::_DATE)return true;
  return false;
}

char* Value::toString(Type type){
  int len=getSizeLength(type);
  char* ret=new char[len];
  if(this->type==_NULL){
    memset(ret,255,len);
    return ret;
  }
  if(type.typeId==Type::_FLOAT){
    float fl=(this->type==_FLOAT)?floatValue:intValue;
    memcpy(ret,&fl,len);
  }
  if(type.typeId==Type::_DATE)
    memcpy(ret,&dateValue,len);
  if(type.typeId==Type::_INT)
    memcpy(ret,&intValue,len);
  if(type.typeId==Type::_CHAR){
    ret[0]=stringValue.length();
    memcpy(ret+1,stringValue.c_str(),ret[0]);
  }
  return ret;
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
        if(values[i].size()!=page0[0]){
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
          Field foreigncolumn;
          if(!getColumn(reftable,refcolumn,foreigncolumn)){
            bufPageManager->writeBack(pageIndex);
            fileManager->closeFile(theIndex);
            printf("Invalid foreign key!\n");
            return;
          }
          std::string foreignfile=database+"/"+tbname;
          int ref=rm->openFile(foreignfile.c_str());
          for(int k=0;k<values.size();k++){
            Type type;
            type.typeId=page0[j*64+1024];
            type.len=page0[j*64+1024+1];
            std::vector<char*> ret=rm->filterRecord(ref,foreigncolumn.left,foreigncolumn.right,values[k][j].toString(type),new EqualFilter());
            if(ret.size()==0){
              printf("Invalid foreign key!\n");
              rm->closeFile(ref);
              fileManager->closeFile(theIndex);
              return;
            }
          }
          rm->closeFile(ref);
        }
        if(page0[64*j+1024+3]!=0){
          std::string thisfile=database+"/"+tbname;
          int ref=rm->openFile(thisfile.c_str());
          for(int k=0;k<values.size();k++){
            Type type;
            type.typeId=page0[j*64+1024];
            type.len=page0[j*64+1024+1];
            std::vector<char*> ret=rm->filterRecord(ref,page0[64*j+1024+17],page0[64*j+1024+18],values[k][j].toString(type),new EqualFilter());
            if(ret.size()!=0){
              printf("Repeated primary key!\n");
              rm->closeFile(ref);
              fileManager->closeFile(theIndex);
              return;
            }
          }
          rm->closeFile(ref);
        }
      }
      std::string thisfile=database+"/"+tbname;
      int ref=rm->openFile(thisfile.c_str());
      int len=rm->getRecordLength(ref);
      for(int j=0;j<values.size();j++){
        char* rc=new char[len];
        for(int k=0;k<page0[0];k++){
          Type type;
          type.typeId=page0[k*64+1024];
          type.len=page0[k*64+1024+1];
          memcpy(rc+page0[k*64+1024+17],values[j][k].toString(type),page0[k*64+1024+18]-page0[k*64+1024+17]);
        }
        rm->insertRecord(ref,rc);
      }
      rm->closeFile(ref);
      fileManager->closeFile(theIndex);
    }
  }
  if(found==false){
    printf("No such table!\n");
  }
}

void DeleteValues::accept(){
  std::vector<>
}

void UpdateValues::accept(){

}

void SelectValues::accept(){
  if(selector.type==Selector::cols){
    for(int i=0;i<selector.columns.size();i++){
      if(tables.size()==1&&selector.columns[i].hastable==false){
        selector.columns[i].hastable=true;
        selector.columns[i].table=tables[0];
      }
      if(selector.columns[i].hastable==false){
        printf("Undetermined selector!\n");
        return;
      }
      bool found=false;
      for(int j=0;j<tables.size();j++){
        if(selector.columns[i].table==tables[j]){
          selector.columns[i].place=j;
          found=true;
        }
      }
      if(found==false){
        printf("Unfound selector column!\n");
        return;
      }
      Field field;
      if(!getColumn(selector.columns[i].table,selector.columns[i].column,field)){
        printf("Unfound selector column!\n");
        return;
      }
      selector.columns[i].left=field.left;
      selector.columns[i].right=field.right;
      selector.columns[i].type=field.thetype;
    }
  }else{
    selector.columns.clear();
    for(int i=0;i<tables.size();i++){
      std::vector<Field> columns=getColumns(tables[i]);
      for(int j=0;j<columns.size();j++){
        Column col;
        col.hastable=true;
        col.table=tables[i];
        col.column=columns[j].colName;
        col.place=i;
        col.left=columns[j].left;
        col.right=columns[j].right;
        col.type=columns[j].thetype;
        selector.columns.push_back(col);
      }
    }
  }
  for(int i=0;i<wheres.size();i++){
    if(tables.size()==1){
      if(wheres[i].left.hastable==false){
        wheres[i].left.hastable=true;
        wheres[i].left.table=tables[0];
      }
      if(wheres[i].type==WhereItem::OPERATION&&wheres[i].expr.type==Expr::COL&&wheres[i].expr.column.hastable==false){
        wheres[i].expr.column.hastable=true;
        wheres[i].expr.column.table=tables[0];
      }
    }
    if(wheres[i].left.hastable==false||(wheres[i].type==WhereItem::OPERATION&&wheres[i].expr.type==Expr::COL&&wheres[i].expr.column.hastable==false)){
      printf("Undetermined column!\n");
      return;
    }
    bool found=false,found2=wheres[i].type!=WhereItem::OPERATION||wheres[i].expr.type!=Expr::COL;
    for(int j=0;j<tables.size();j++){
      if(wheres[i].left.table==tables[j]){
        wheres[i].left.place=j;
        found=true;
      }
      if(wheres[i].type==WhereItem::OPERATION&&wheres[i].expr.type==Expr::COL&&wheres[i].expr.column.table==tables[j]){
        wheres[i].expr.column.place=j;
        found2=true;
      }
    }
    if(found==false||found2==false){
      printf("Unfound column!\n");
      return;
    }
    Field field;
    if(!getColumn(wheres[i].left.table,wheres[i].left.column,field)){
      printf("Unfound column!\n");
      return;
    }
    wheres[i].left.left=field.left;
    wheres[i].left.right=field.right;
    wheres[i].left.type=field.thetype;
    if(wheres[i].type==WhereItem::OPERATION&&wheres[i].expr.type==Expr::COL){
      if(!getColumn(wheres[i].expr.column.table,wheres[i].expr.column.column,field)){
        printf("Unfound column!\n");
        return;
      }
      wheres[i].expr.column.left=field.left;
      wheres[i].expr.column.right=field.right;
      wheres[i].expr.column.type=field.thetype;
      if(!cancompare(wheres[i].left.type.typeId,field.thetype.typeId)){
        printf("Invalid operation!\n");
        return;
      }
    }else if(!canassign(field.thetype.typeId,wheres[i].expr.value.type)){
      printf("Invalid operation!\n");
      return;
    }
  }
  std::vector<std::vector<char*> > cols;
  cols.clear();
  std::vector<int> ns;
  ns.clear();
  std::vector<int> is;
  is.clear();
  for(int i=0;i<tables.size();i++){
    std::string thisfile=database+"/"+tables[i];
    int ref=rm->openFile(thisfile.c_str());
    int len=rm->getRecordLength(ref);
    std::vector<char*> gt=rm->filterRecord(ref,0,0,NULL,new TransparentFilter());
    cols.push_back(gt);
    ns.push_back(gt.size());
    is.push_back(0);
    rm->closeFile(ref);
  }
  for(int i=0;i<selector.columns.size();i++){
    std::string toprint=selector.columns[i].table+"."+selector.columns[i].column;
    if(toprint.length()>20){
      toprint.erase(0,toprint.length()-17);
      toprint="..."+toprint;
    }
    while(toprint.length()<20)
      toprint=toprint+" ";
    printf("%s ",toprint.c_str());
  }
  printf("\n");
  while(true){
    bool tf=false;
    for(int i=0;i<tables.size();i++)
      if(is[i]>=ns[i]){
        tf=true;
        break;
      }
    if(tf)break;
    bool valid=true;
    for(int i=0;i<wheres.size();i++){
      if(wheres[i].type==WhereItem::OPERATION){
        int place=wheres[i].left.place;
        Value left=extractValue(cols[place][is[place]],wheres[i].left.left+4,wheres[i].left.right+4,wheres[i].left.type);
        Value right=wheres[i].expr.value;
        if(wheres[i].expr.type==Expr::COL){
          place=wheres[i].expr.column.place;
          right=extractValue(cols[place][is[place]],wheres[i].expr.column.left+4,wheres[i].expr.column.right+4,wheres[i].expr.column.type);
        }
        if(!doOperation(left,wheres[i].Operator,right)){
          valid=false;
          break;
        }
      }
      if(wheres[i].type==WhereItem::ISNULL){
        int place=wheres[i].left.place;
        Value left=extractValue(cols[place][is[place]],wheres[i].left.left+4,wheres[i].left.right+4,wheres[i].left.type);
        if(left.type!=Value::_NULL){
          valid=false;
          break;
        }
      }
      if(wheres[i].type==WhereItem::ISNOTNULL){
        int place=wheres[i].left.place;
        Value left=extractValue(cols[place][is[place]],wheres[i].left.left+4,wheres[i].left.right+4,wheres[i].left.type);
        if(left.type==Value::_NULL){
          valid=false;
          break;
        }
      }
    }
    if(valid){
      for(int i=0;i<selector.columns.size();i++){
        int place=selector.columns[i].place;
        Value value=extractValue(cols[place][is[place]],selector.columns[i].left+4,selector.columns[i].right+4,selector.columns[i].type);
        printValue(value);printf(" ");
      }
      printf("\n");
    }
    is[tables.size()-1]++;
    int n=tables.size()-1;
    while(n>0&&is[n]>=ns[n]){
      is[n]=0;
      is[--n]++;
    }
  }
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
