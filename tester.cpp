#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "RecordManager.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	RecordManager* rm=new RecordManager();

  if(false){
    rm->createFile("file1",32);
  int file1=rm->openFile("file1");
  for(int i=0;i<500;i++){
    //printf("%d ",i);
    stringstream stream;
    stream<<i;
    std::string string_temp=stream.str();
    while(string_temp.length()<4)
      string_temp="0"+string_temp;
    string_temp.append("0000000000000000000000000000");
    
    //printf("%s\n",string_temp.c_str());
    int rec=rm->insertRecord(file1,string_temp.c_str());
    //rm->deleteRecord(file1,rec);

  }



        rm->closeFile(file1);

  }else{
    int file1=rm->openFile("file1");
  rm->renewRecord(file1,496,"00000000000000000000000000000000");
    rm->deleteRecord(file1,494);
    std::vector<char*> getter=rm->filterRecord(file1,0,4,"04..",new RegexFilter());
  printf("%d\n",getter.size());
  for(int i=0;i<getter.size();i++)
    printf("%d\n",rm->parseIndex(getter[i]));
  for(int i=0;i<getter.size();i++)
    printf("%s\n",getter[i]+4);
      rm->closeFile(file1);

  }
	return 0;
}
