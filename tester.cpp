#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "RecordManager.h"
#include "BPlusTree.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

int order[1000];

int main() {
  srand(time(0));
	RecordManager* rm=new RecordManager();
  int k=1;
  if(k==3){
    rm->createFile("file1",32);
    rm->createFile("file2",48);
    rm->createFile("file3",64);
    int f1=rm->openFile("file1");
    int f2=rm->openFile("file2");
    int f3=rm->openFile("file3");
    rm->closeFile(f1);
    rm->outpmsgs();
  }else if(k==2){
    rm->createFile("file1",32);
  int file1=rm->openFile("file1");
  for(int i=0;i<500;i++){
    //int t=rand()%(i+1);
    //order[i]=order[t];
    order[i]=i;
  }
  for(int i=0;i<500;i++){
    //printf("%d ",i);
    stringstream stream;
    stream<<order[i];
    std::string string_temp;//=stream.str();
    string_temp.erase();
    string_temp.append(to_string(order[i]%10));
    string_temp.append(to_string(order[i]/10%10));
    string_temp.append(to_string(order[i]/100%10));
    string_temp.append(to_string(order[i]/1000%10));
    while(string_temp.length()<4)
      string_temp=string_temp+"0";
    string_temp.append("0000000000000000000000000000");
    printf("%s\n",string_temp.c_str());
    int rec=rm->insertRecord(file1,string_temp.c_str());
    //rm->deleteRecord(file1,rec);

  }
  int index=rm->createIndex(file1,0,4);
  //printf("123\n");
  int l=(('0'*256+'3')*256+'5')*256+'0';
  int r=(('0'*256+'3')*256+'6')*256+'0';
  printf("%d %d\n",l,r);
  std::vector<char*> getter=rm->findbyIndex(file1,index,l,r);

    //std::vector<char*> getter=rm->filterRecord(file1,0,4,"04..",new RegexFilter());
  printf("resultsize:%d\n",getter.size());
  for(int i=0;i<getter.size();i++)
    printf("%d %s\n",rm->parseIndex(getter[i]),getter[i]+4);


        rm->closeFile(file1);

  }else{
    int file1=rm->openFile("file1");
    printf("123\n");
  rm->renewRecord(file1,355,"00000000000000000000000000000000");
    printf("123\n");
    rm->deleteRecord(file1,356);
    printf("123\n");
      int l=(('0'*256+'3')*256+'5')*256+'0';
  int r=(('0'*256+'3')*256+'6')*256+'0';
      std::vector<char*> getter=rm->findbyIndex(file1,0,l,r);

    //std::vector<char*> getter=rm->filterRecord(file1,0,4,"00..",new RegexFilter());
  printf("%d\n",getter.size());
  for(int i=0;i<getter.size();i++)
    printf("%d %s\n",rm->parseIndex(getter[i]),getter[i]+4);
      rm->closeFile(file1);

  }
  delete(rm);
	return 0;
}
