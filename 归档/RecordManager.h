#ifndef RECORD_MANAGER
#define RECORD_MANAGER
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "NotThatSillyHashMap.h"
#include "BPlusTree.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <regex>
#include <string>

struct FileInfo{
  int pageNumber,recordLength,recordNumber,index,recordIndex;
  std::vector<BTree*> indexes;
  char* name;
};

char getintchar(uint ui,int offset){
  if(offset==0)return ui&255;
  if(offset==1)return (ui>>8)&255;
  if(offset==2)return (ui>>16)&255;
  if(offset==3)return (ui>>24);
  return 0;
}

class RecordFilter{
public:
  virtual bool check(uint* tocheck,const char* provided,int len1,int len2)=0;
};

class EqualFilter:public RecordFilter{
  bool check(uint* tocheck,const char* provided,int len1,int len2){
    if(len1!=len2)return false;
    for(int i=0;i<len2;i++){
      uint tmp=*(tocheck+i/4);
      char tocomp=getintchar(tmp,i%4);
      //printf("%u %u\n",tocomp,*(provided+i));
      if(*(provided+i)!=tocomp)
        return false;
    }
    return true;
  }
};

class GreaterFilter:public RecordFilter{
  bool check(uint* tocheck,const char* provided,int len1,int len2){
    if(len1!=len2)return false;
    for(int i=0;i<len2;i++){
      uint tmp=*(tocheck+i/4);
      char tocomp=getintchar(tmp,i%4);
      if(tocomp<*(provided+i))return false;
        else if(tocomp>*(provided+i))return true;

    }
    return false;
  }
};

class LowerFilter:public RecordFilter{
  bool check(uint* tocheck,const char* provided,int len1,int len2){
    if(len1!=len2)return false;
    for(int i=0;i<len2;i++){
      uint tmp=*(tocheck+i/4);
      char tocomp=getintchar(tmp,i%4);
      if(tocomp>*(provided+i))return false;
        else if(tocomp<*(provided+i))return true;

    }
    return false;
  }
};

class RegexFilter:public RecordFilter{
  bool check(uint* tocheck,const char* provided,int len1,int len2){
    char* now=new char[len1+1];
    memcpy(now,tocheck,len1);
    now[len1]='\0';
    std::regex rgx(provided);
    std::string st(now);
    bool ans=std::regex_match(st,rgx);
    delete[] now;
    return ans;
  }
};

class TransparentFilter:public RecordFilter{
  bool check(uint* tocheck,const char* provided,int len1,int len2){
    return true;
  }
};

class RecordManager{
private:
  FileManager* fileManager;
  BufPageManager* bufPageManager;
  std::vector<FileInfo> fileInfo;
  NotThatSillyHashMap* ntshm;
public:
  FileManager* getFileManager(){
    return fileManager;
  }
  BufPageManager* getBufPageManager(){
    return bufPageManager;
  }
  RecordManager(){
  	MyBitMap::initConst();
  	fileManager = new FileManager();
    bufPageManager = new BufPageManager(fileManager);
    fileInfo.clear();
    ntshm=new NotThatSillyHashMap();
  }
  void createFile(const char* name,int recordLength){
    recordLength+=4;
    if(recordLength%4!=0){
      printf("Invalid record length!(check if length mod 4 equals to 0)\n");
      return;
    }
    if(recordLength>PAGE_SIZE){
      printf("Invalid record length!(should be smaller than %d)\n",PAGE_SIZE);
      return;
    }
    fileManager->createFile(name);
    int theIndex;
    fileManager->openFile(name,theIndex);
    int pageIndex;
    BufType page0=bufPageManager->allocPage(theIndex,0,pageIndex);
    bufPageManager->markDirty(pageIndex);
    page0[0]=1;
    page0[1]=recordLength;
    page0[2]=0;
    page0[3]=0;
    //printf("%d %d %d %d\n",page0[0],page0[1],page0[2],page0[3]);

    bufPageManager->writeBack(pageIndex);
    fileManager->closeFile(theIndex);
    std::string rmname=name;
    rmname.append(".*");
    std::string command = "rm " + rmname;
    system(command.c_str());
  }
  bool deleteFile(const char* name){
    return remove(name)==0;
  }
  int openFile(const char* name){
    int ret,pageIndex;
    fileManager->openFile(name,ret);
    BufType page0=bufPageManager->getPage(ret,0,pageIndex);
    FileInfo theFileInfo;
    theFileInfo.pageNumber=page0[0];
    theFileInfo.recordLength=page0[1];
    theFileInfo.recordNumber=page0[2];
    theFileInfo.recordIndex=page0[3];
    theFileInfo.index=ret;
    theFileInfo.name=new char[strlen(name)+1];
    strcpy(theFileInfo.name,name);
    ntshm->insert(ret,fileInfo.size());
   // printf("%d %u %u %u %u\n",ret,page0[0],page0[1],page0[2],page0[3]);
    //for(int i=0;i<100;i++)
      //printf("%d %u\n",i,*(((unsigned char*)page0)+i));
    bufPageManager->release(pageIndex);
    //printf("%d\n",ret);
    for(int i=0;i<theFileInfo.recordLength/4;i++){
      //printf("%d\n",i);
      theFileInfo.indexes.push_back(NULL);
      fstream file;
      std::string name=theFileInfo.name;
      name.append(".index");
      name.append(std::to_string(i));
      file.open(name, ios::in);
      if (file){
        //printf("%s\n",name.c_str());
        file.close();
        theFileInfo.indexes[i]=new BTree();
        std::vector<uint*> rd;
        rd.clear();
        int fileIndex,pageIndex;
        fileManager->openFile(name.c_str(),fileIndex);
        //printf("%d\n",fileIndex);
        BufType page0=bufPageManager->getPage(fileIndex,0,pageIndex);
        int llen=page0[0];
        //printf("%d\n",llen);
        bufPageManager->release(pageIndex);
        for(int j=0;j<llen;j++){
          BufType page=bufPageManager->getPage(fileIndex,j/4+1,pageIndex);
          //printf("%d\n",pageIndex);
          uint* thisnode=new uint[512];
          memcpy(thisnode,page+(j%4)*512,2048);
          rd.push_back(thisnode);
          bufPageManager->release(pageIndex);

        }
        //printf("123\n");
        fileManager->closeFile(fileIndex);
        //printf("123\n");
        theFileInfo.indexes[i]->buildtree(rd);
        //printf("123\n");
      }
    }
    fileInfo.push_back(theFileInfo);
    //  printf("%d %d\n",ret,theFileInfo.recordLength);
    if(theFileInfo.indexes[0]==NULL)createIndex(ret,0,4);
    return ret;
  }
  void saveFile(int index){
    int theIndex=ntshm->getdata(index);
    FileInfo& info=fileInfo[theIndex];
    int pageIndex;
    BufType page0=bufPageManager->getPage(index,0,pageIndex);
    bufPageManager->markDirty(pageIndex);
    info=fileInfo[theIndex];
    page0[0]=info.pageNumber;
    page0[1]=info.recordLength;
    page0[2]=info.recordNumber;
    page0[3]=info.recordIndex;
    bufPageManager->writeBack(pageIndex);
    //printf("saved %d %d %d %d\n",page0[0],page0[1],page0[2],page0[3]);
    for(int i=1;i<info.pageNumber;i++){
      //printf("saving page %d\n",i);
      int pageIndex;
      bufPageManager->getPage(index,i,pageIndex);
      bufPageManager->markDirty(pageIndex);
      bufPageManager->writeBack(pageIndex);
    }
    for(int i=0;i<info.indexes.size();i++)
      if(info.indexes[i]!=NULL){
        std::string name=info.name;
        name.append(".index");
        name.append(std::to_string(i));
        fileManager->createFile(name.c_str());
        int theIndex;
        fileManager->openFile(name.c_str(),theIndex);
        int pageIndex;
        std::vector<uint*> buffers=info.indexes[i]->tobuffers();
        //printf("%d\n",buffers.size());
        BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
        bufPageManager->markDirty(pageIndex);
        page0[0]=buffers.size();
        //printf("%d\n",pageIndex);
        bufPageManager->writeBack(pageIndex);
        //printf("%d\n",buffers.size());
        for(int j=0;j<(buffers.size()-1)/4+1;j++){
          //printf("%d\n",j);
          BufType page=bufPageManager->getPage(theIndex,j+1,pageIndex);
          bufPageManager->markDirty(pageIndex);
          //printf("%d %d %u\n",j+1,pageIndex,page[0]);

          memcpy(page,buffers[j*4],2048);
          if(j*4+1<buffers.size())memcpy(page+512,buffers[j*4+1],2048);
          if(j*4+2<buffers.size())memcpy(page+1024,buffers[j*4+2],2048);
          if(j*4+3<buffers.size())memcpy(page+1536,buffers[j*4+3],2048);
          bufPageManager->writeBack(pageIndex);
        }
        fileManager->closeFile(theIndex);
      }
  }
  bool closeFile(int index){
    saveFile(index);
    int theIndex=ntshm->getdata(index);
    //printf("%d %d %d %d %d\n",fileInfo[theIndex].pageNumber,fileInfo[theIndex].recordLength,fileInfo[theIndex].recordNumber,fileInfo[theIndex].index,fileInfo[theIndex].recordIndex);
    fileInfo[theIndex]=*(fileInfo.end()-1);
    ntshm->replace(fileInfo[theIndex].index,theIndex);
    fileInfo.pop_back();
    ntshm->deleteit(index);
    fileManager->closeFile(index);
    return true;
  }
  void closeAll(){
    while(fileInfo.size())
      closeFile(fileInfo[0].index);
  }
  int insertRecord(int fileIndex,const char* record){
    int theIndex=ntshm->getdata(fileIndex);
    //printf("%s\n",record);
    FileInfo& info=fileInfo[theIndex];
    int recordLength=strlen(record);
    //printf("%d %d\n",recordLength,info.recordLength-4);
    /*if(recordLength!=info.recordLength-4){
      printf("Invalid record length!\n");
      return -1;
    }*/
    for(int i=0;i<info.indexes.size();i++){
      //printf("%d %d\n",i,(int)(info.indexes[i]==NULL));
      if(info.indexes[i]!=NULL){
        if(i==0)info.indexes[i]->insertdata(info.recordIndex,info.recordNumber);
          else info.indexes[i]->insertdata(*((int*)(record+i*4-4)),info.recordNumber);
      }
    }
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int page=(info.recordNumber)/recordsPerPage+1;
    if(info.recordNumber>=(info.pageNumber-1)*recordsPerPage){
      int pageIndex;

      BufType page1=bufPageManager->allocPage(fileIndex,info.pageNumber,pageIndex);
      bufPageManager->markDirty(pageIndex);
      info.pageNumber++;
    }
    int pageIndex;
    BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
    bufPageManager->markDirty(pageIndex);
    int place=info.recordNumber%recordsPerPage*info.recordLength;
    //printf("%d %d ",page,place);
    memcpy(page1+place/4+1,record,info.recordLength-4);
    //printf("%d\n",page1+place/4+1);
    //printf("%s\n",page1+place/4+1);

    info.recordNumber++;
    page1[place/4]=info.recordIndex;
    //bufPageManager->release(pageIndex);
    return info.recordIndex++;
  }
  int findRecord(int fileIndex,int recordIndex){
    int theIndex=ntshm->getdata(fileIndex);
    return fileInfo[theIndex].indexes[0]->findexact(recordIndex);
    /*FileInfo& info=fileInfo[theIndex];
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int find=-1;
    for(int i=0;i<info.recordNumber;i++){
      int page=i/recordsPerPage+1;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=i%recordsPerPage*info.recordLength;
      if(page1[place/4]==recordIndex){
        find=i;
        bufPageManager->release(pageIndex);
        break;
      }
      bufPageManager->release(pageIndex);
    }
    return find;*/
  }
  bool deleteRecord(int fileIndex,int recordIndex){
    int theIndex=ntshm->getdata(fileIndex);
    int find=findRecord(fileIndex,recordIndex);
    //printf("%d\n",find);
    FileInfo& info=fileInfo[theIndex];
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    if(find!=-1){
      int pageIndex1;
      int pageIndex2;
      BufType todelete=bufPageManager->getPage(fileIndex,find/recordsPerPage+1,pageIndex1);
      BufType tail=bufPageManager->getPage(fileIndex,(info.recordNumber-1)/recordsPerPage+1,pageIndex2);
      bufPageManager->markDirty(pageIndex1);
      bufPageManager->markDirty(pageIndex2);
      int todeleteplace=find%recordsPerPage*info.recordLength;
      int tailplace=(info.recordNumber-1)%recordsPerPage*info.recordLength;
      memcpy(todelete+todeleteplace/4,tail+tailplace/4,info.recordLength);
      //bufPageManager->release(pageIndex1);
      //bufPageManager->release(pageIndex2);
      for(int i=0;i<info.indexes.size();i++){
        if(info.indexes[i]!=NULL){
          info.indexes[i]->deletedata(find);
          info.indexes[i]->changedata(info.recordNumber-1,find);
        }
      }
      info.recordNumber--;
      return true;
    }else{
      printf("Cannot find record %d!\n",recordIndex);
      return false;
    }
  }
  bool renewRecord(int fileIndex,int recordIndex,char* newrecord){
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo& info=fileInfo[theIndex];
    /*if(strlen(newrecord)!=info.recordLength-4){
      printf("Invalid record length!\n");
      return false;
    }*/
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int find=findRecord(fileIndex,recordIndex);
    //printf("%d\n",find);
    if(find!=-1){
      int page=find/recordsPerPage+1;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=find%recordsPerPage*info.recordLength;
      memcpy(page1+place/4+1,newrecord,info.recordLength-4);
     // bufPageManager->release(pageIndex);
        //printf("%s\n",page1+place/4+1);
      for(int i=0;i<info.indexes.size();i++){
        if(info.indexes[i]!=NULL){
         // printf("%d %d\n",find,i);
          info.indexes[i]->deletedata(find);
          //printf("%d\n",*((int*)(newrecord+i*4)));
          if(i==0)info.indexes[i]->insertdata(recordIndex,find);
            else info.indexes[i]->insertdata(*((int*)(newrecord+i*4-4)),find);
        }
      }
    }
    return find!=-1;
  }
  std::vector<char*> filterRecord(int fileIndex,int begin,int end,const char* provided,RecordFilter* checker){

    std::vector<char*> ret;
    ret.clear();
    if(begin%4!=0||end%4!=0){
      printf("Invalid place!");
      return ret;
    }
    int len=0;
    if(provided!=NULL)len=strlen(provided);
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo& info=fileInfo[theIndex];
    if(begin<0||end>info.recordLength)return ret;
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int find=-1;
    //printf("%d\n",info.recordNumber);
    for(int i=0;i<info.recordNumber;i++){
      int page=i/recordsPerPage+1;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=i%recordsPerPage*info.recordLength;
      //printf("%d %d %d\n",i,page,place);
      //printf("%d\n",page1+place/4+1);
      //printf("%s\n",page1+place/4+1);

      if(checker->check(page1+place/4+1+begin/4,provided,end-begin,end-begin)){
        char* cpout=new char[info.recordLength+1];
        cpout[info.recordLength]='\0';
        memcpy(cpout,page1+place/4,info.recordLength);
        //printf("%s\n",cpout);
        ret.push_back(cpout);
      }
      bufPageManager->release(pageIndex);
    }
    return ret;
  }
  
  int getRecordLength(int fileIndex){
    int theIndex=ntshm->getdata(fileIndex);
    return fileInfo[theIndex].recordLength-4;
  }
  bool hasIndex(int fileIndex,int indexIndex){
    int theIndex=ntshm->getdata(fileIndex);
    return fileInfo[theIndex].indexes[indexIndex]!=NULL;
  }
  uint parseIndex(const char* ch){//不是索引
    uint ans=0;
    for(int i=0;i<4;i++){
      ans=ans*256+(unsigned char)ch[3-i];
    }
    return ans;
  }
  void outpmsgs(){
    printf("%d\n",fileInfo.size());
    for(int i=0;i<fileInfo.size();i++){
      printf("%d %d %d %d %d\n",fileInfo[i].pageNumber,fileInfo[i].recordLength,fileInfo[i].recordNumber,fileInfo[i].index,fileInfo[i].recordIndex);

    }
  }
  int createIndex(int fileIndex, int begin, int end){//INSERT INTO `orders` VALUES (100001,301743,260874,'2017-09-14',5);
    if(begin%4!=0||end%4!=0||end-begin!=4){
      printf("Invalid place!");
      return -1;
    }
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo& info=fileInfo[theIndex];
    int indexIndex=begin/4;
    //printf("123 %d %u\n",indexIndex,info.indexes.size());
    info.indexes[indexIndex]=new BTree();
    //printf("123\n");
    printf("%d\n",indexIndex);
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    for(int i=0;i<info.recordNumber;i++){
      //printf("%d\n",i);
      int page=i/recordsPerPage+1;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=i%recordsPerPage*info.recordLength;
      uint toinsert=*(page1+place/4+begin/4);
      bufPageManager->release(pageIndex);
      //printf("%u %d %d\n",toinsert,i,begin);
      info.indexes[indexIndex]->insertdata(toinsert,i);
    }
    return indexIndex;
  }
  void deleteIndex(int fileIndex, int indexIndex){
    int theIndex=ntshm->getdata(fileIndex);
    if(fileInfo[theIndex].indexes[indexIndex]!=NULL){
      delete fileInfo[theIndex].indexes[indexIndex];
      fileInfo[theIndex].indexes[indexIndex]=NULL;
      std::string name=fileInfo[theIndex].name;
      name.append(".index");
      name.append(std::to_string(indexIndex));
      std::string command = "rm " + name;
      system(command.c_str());
    }
  }
  std::vector<char*> findbyIndex(int fileIndex, int indexIndex, int begin, int end){
    //printf("%d %d %d\n",begin,end,indexIndex);
    std::vector<char*> ret;
    ret.clear();
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo& info=fileInfo[theIndex];
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    if(indexIndex<0||indexIndex>=fileInfo[theIndex].indexes.size()||fileInfo[theIndex].indexes[indexIndex]==NULL){
      printf("Invalid indexId!");
      return ret;
    }
    std::vector<int> indexes=fileInfo[theIndex].indexes[indexIndex]->finddata(begin,end);
    for(int i=0;i<indexes.size();i++){
      int page=indexes[i]/recordsPerPage+1;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=indexes[i]%recordsPerPage*info.recordLength;
      char* cpout=new char[info.recordLength+1];
      cpout[info.recordLength]='\0';
      memcpy(cpout,page1+place/4,info.recordLength);
      bufPageManager->release(pageIndex);
      ret.push_back(cpout);
    }
    return ret;
  }
  ~RecordManager(){
      //printf("%d\n",fileInfo.size());

    while(fileInfo.size()>0){
      closeFile(fileInfo[0].index);
    }
  }
};

#endif
