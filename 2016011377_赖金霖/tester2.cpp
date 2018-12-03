#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "RecordManager.h"
#include "BPlusTree.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <memory.h>

using namespace std;

int sums[10000000],data[10000000];

int main() {
  srand(time(0));
  //while(1){
  memset(sums,0,sizeof(sums));
	BTree* bt=new BTree();
  //printf("---------------------------------\n");
  for(int i=0;i<1000000;i++){
    int t1=rand()%10000000;
    int t2=i;
    data[i]=t1;
    sums[t1]++;
    //printf("%d %d %d\n",i,t1,t2);
    bt->insertdata(t1,t2);
    //bt->print();
  }
  //bt->print();
  for(int i=0;i<990000;i++){
    int tt=rand()%1000000;
    while(data[tt]==-1)
      tt=rand()%1000000;
    //printf("%d\n",data[tt]);
    sums[data[tt]]--;
    data[tt]=-1;
    bt->deletedata(tt);
    //bt->print();
    /*for(int j=0;j<20;j++)
      if(data[j]!=-1){
        printf("%d %d %d\n",j,data[j],bt->places[j].order);
      }*/
  }
  for(int i=0;i<900000;i++){
    int tt=rand()%1000000;
    while(data[tt]==-1)
      tt=rand()%1000000;
    int t1=rand()%10000000;
    int t2=tt;
    data[t2]=t1;
    sums[t1]++;
    //printf("%d %d %d\n",i,t1,t2);
    bt->insertdata(t1,t2);
    //bt->print();
  }
  printf("done\n");
  //for(int i=0;i<10000000;i++)
    //if(sums[i]>0)printf("%d %d\n",i,sums[i]);
  /*for(int i=0;i<100000;i++){
    int t1=rand()%10000000;
    int t2=rand()%10000000;
    if(t1>t2)std::swap(t1,t2);
    int anss=0;
    for(int j=t1;j<t2;j++)
      anss+=sums[j];
    std::vector<int> got=bt->finddata(t1,t2);
    if(got.size()!=anss){
      printf("wrong! %d %d\n",got.size(),anss);
      printf("%d %d %d\n",t1,t2,data[got[0]]);
    }
    else printf("%d %d\n",got.size(),anss);
  }*/
	return 0;
}
