#ifndef RECORD_MANAGER
#define RECORD_MANAGER
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include <iostream>
#include <cstdio>
#include <vector>

struct FileInfo{
  int pageNumber,recordLength,recordNumber,index;
  char* name;
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
    fileInfos.clear();
  }
  void createFile(char* name,int recordLength){
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
    bufPageManager->writeBack(pageIndex);
    fileManager->closeFile(theIndex);
  }
  bool deleteFile(char* name){
    return remove(name)==0;
  }
  int openFile(char* name){
    int ret;
    fileManager->openFile(name,ret);
    BufType page0=bufPageManager->getPage(theIndex,0,pageIndex);
    FileInfo theFileInfo;
    theFileInfo.pageNumber=page0[0];
    theFileInfo.recordLength=page0[1];
    theFileInfo.recordNumber=page0[2];
    theFileInfo.index=ret;
    theFileInfo.name=name;
    fileInfo.push_back(theFileInfo);
    ntshm->insert(ret,fileInfo.size()-1);
    return ret;
  }
  bool closeFile(int index){
  }
  int insertRecord(int fileIndex,char* record){
  }
  bool deleteRecord(int fileIndex,int recordIndex){
  }
  bool renewRecord(int fileIndex,int recordIndex,char* newrecord){
  }
  std::vector<int> findEqualRecord(int fileIndex,int begin,int end,char* equal){
  }
  std::vector<int> findGreaterRecord(int fileIndex,int begin,int end,char* Greater){
  }
  std::vector<int> findLowerRecord(int fileIndex,int begin,int end,char* Lower){
  }
  std::vector<int> findRegexRecord(int fileIndex,int begin,int end,char* Regex){
  
  }
  ~RecordManager(){
  }
}

#endif
