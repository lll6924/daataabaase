#ifndef RECORD_MANAGER
#define RECORD_MANAGER
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "NotThatSillyHashMap.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <regex>
#include <string>

struct FileInfo{
  int pageNumber,recordLength,recordNumber,index,recordIndex;
  char* name;
};

class RecordFilter{
public:
  virtual bool check(uint* tocheck,char* provided,int len1,int len2);
};

class EqualFilter: RecordFilter{
  bool check(char* tocheck,char* provided,int len1,int len2){
    if(len1!=len2)return false;
    for(int i=0;i<len2;i++)
    if(*(provided+i)!=*(tocheck+i))
      return false;
    return true;
  }
};

class GreaterFilter: RecordFilter{
  bool check(char* tocheck,char* provided,int len1,int len2){
    if(len1!=len2)return false;
    for(int i=0;i<len2;i++)
      if(*(provided+i)>*(tocheck+i))return false;
      else if(*(provided+i)<*(tocheck+i))return true;
    return false;
  }
};

class LowerFilter: RecordFilter{
  bool check(char* tocheck,char* provided,int len1,int len2){
    if(len1!=len2)return false;
    for(int i=0;i<len2;i++)
      if(*(provided+i)<*(tocheck+i))return false;
      else if(*(provided+i)>*(tocheck+i))return true;
    return false;
  }
};

class RegexFilter: RecordFilter{
  bool check(char* tocheck,char* provided,int len1,int len2){
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

class RecordManager{
private:
  RecordManager(){
  }
  FileManager* fileManager;
  BufPageManager* bufPageManager;
  std::vector<FileInfo> fileInfo;
  NotThatSillyHashMap* ntshm;
public:
  RecordManager(FileManager* fm,BufPageManager* bpm){
    fileManager=fm;
    bufPageManager=bpm;
    fileInfo.clear();
  }
  void createFile(char* name,int recordLength){
    recordLength+=4;
    if(recordLength%4!=0){
      printf("Invalid record length!(check if length mod 4 equals to 0)\n");
      return;
    }
    if(recordLength>PAGE_SIZE){
      printf("Invalid record length!(should be smaller than %d)\n",PAGE_SIZE);
      return;
    }
    ntshm=new NotThatSillyHashMap();
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
    bufPageManager->writeBack(pageIndex);
    fileManager->closeFile(theIndex);
  }
  bool deleteFile(char* name){
    return remove(name)==0;
  }
  int openFile(char* name){
    int ret,pageIndex;
    fileManager->openFile(name,ret);
    BufType page0=bufPageManager->getPage(ret,0,pageIndex);
    FileInfo theFileInfo;
    theFileInfo.pageNumber=page0[0];
    theFileInfo.recordLength=page0[1];
    theFileInfo.recordNumber=page0[2];
    theFileInfo.recordIndex=page0[3];
    theFileInfo.index=ret;
    theFileInfo.name=name;
    fileInfo.push_back(theFileInfo);
    ntshm->insert(ret,fileInfo.size()-1);
    return ret;
  }
  void saveFile(int index){
    int theIndex=ntshm->getdata(index);
    FileInfo info=fileInfo[theIndex];
    int pageIndex;
    BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
    bufPageManager->markDirty(pageIndex);
    info=fileInfo[theIndex];
    page0[0]=info.pageNumber;
    page0[1]=info.recordLength;
    page0[2]=info.recordNumber;
    page0[3]=info.recordIndex;
    for(int i=0;i<info.pageNumber;i++){
      int pageIndex;
      bufPageManager->getPage(index,i,pageIndex);
      bufPageManager->writeBack(pageIndex);
    }
  }
  bool closeFile(int index){
    saveFile(index);
    int theIndex=ntshm->getdata(index);
    fileInfo[theIndex]=*fileInfo.end();
    ntshm->replace(fileInfo[theIndex].index,theIndex);
    fileInfo.pop_back();
    ntshm->deleteit(index);
    fileManager->closeFile(index);
    return true;
  }
  int insertRecord(int fileIndex,char* record){
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo info=fileInfo[theIndex];
    int recordLength=strlen(record);
    if(recordLength!=info.recordLength-4){
      printf("Invalid record length!");
      return -1;
    }
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int page=(info.recordNumber+1)/recordsPerPage;
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
    memcpy(page1+place+4,record,strlen(record));
    info.recordNumber++;
    page1[place/4]=info.recordIndex;
    return info.recordIndex++;
  }
  int findRecord(int fileIndex,int recordIndex){
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo info=fileInfo[theIndex];
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int find=-1;
    for(int i=0;i<info.recordNumber;i++){
      int page=(i+1)/recordsPerPage;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=i%recordsPerPage*info.recordLength;
      if(page1[place/4]==recordIndex){
        find=i;
        break;
      }
    }
    return find;
  }
  bool deleteRecord(int fileIndex,int recordIndex){
    int theIndex=ntshm->getdata(fileIndex);
    int find=findRecord(fileIndex,recordIndex);
    FileInfo info=fileInfo[theIndex];
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    if(find!=-1){
      int pageIndex1;
      int pageIndex2;
      BufType todelete=bufPageManager->getPage(fileIndex,(find+1)/recordsPerPage,pageIndex1);
      BufType tail=bufPageManager->getPage(fileIndex,info.recordNumber/recordsPerPage,pageIndex2);
      bufPageManager->markDirty(pageIndex1);
      bufPageManager->markDirty(pageIndex2);
      int todeleteplace=find%recordsPerPage*info.recordLength;
      int tailplace=(info.recordNumber-1)%recordsPerPage*info.recordLength;
      memcpy(todelete+todeleteplace,tail+tailplace,info.recordLength);
      info.recordNumber--;
      return true;
    }else{
      printf("Cannot find record %d!\n",recordIndex);
      return false;
    }
  }
  bool renewRecord(int fileIndex,int recordIndex,char* newrecord){
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo info=fileInfo[theIndex];
    if(strlen(newrecord)!=info.recordLength-4){
      printf("Invalid record length!\n");
      return false;
    }
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int find=-1;
    for(int i=0;i<info.recordNumber;i++){
      int page=(i+1)/recordsPerPage;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=i%recordsPerPage*info.recordLength;
      if(page1[place/4]==recordIndex){
        memcpy(page1+place+4,newrecord,strlen(newrecord));
        return true;
      }
    }
    return false;
  }
  std::vector<char*> filterRecord(int fileIndex,int begin,int end,char* provided,RecordFilter* checker){
    std::vector<char*> ret;
    ret.clear();
    int len=strlen(provided);
    int theIndex=ntshm->getdata(fileIndex);
    FileInfo info=fileInfo[theIndex];
    if(begin<0||end>info.recordLength)return ret;
    int recordsPerPage=PAGE_SIZE/info.recordLength;
    int find=-1;
    for(int i=0;i<info.recordNumber;i++){
      int page=(i+1)/recordsPerPage;
      int pageIndex;
      BufType page1=bufPageManager->getPage(fileIndex,page,pageIndex);
      int place=i%recordsPerPage*info.recordLength;
      if(checker->check(page1+place+4+begin,provided,end-begin,len)){
        char* cpout=new char[info.recordLength];
        memcpy(cpout,page1+place,info.recordLength);
        ret.push_back(cpout);
      }
    }
    return ret;
  }
  ~RecordManager(){
  }
};

#endif
