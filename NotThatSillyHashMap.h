#ifndef NOT_THAT_SILLY_HASH_MAP
#define NOT_THAT_SILLY_HASH_MAP

#include <vector>

const int MOD=989381;

struct node{
  int index,data;
  node* nxt;
};

class NotThatSillyHashMap{
node** nodes;
public:
  NotThatSillyHashMap(){
    nodes=new node*[MOD];
    for(int i=0;i<MOD;i++)
      nodes[i]=NULL;
  }
  bool insert(int index,int data){
    int theIndex=index%MOD;
    node* newnode=new node();
    newnode->index=index;
    newnode->data=data;
    newnode->nxt=nodes[theIndex];
    nodes[theIndex]=newnode;
    return true;
  }
  bool find(int index){
    int theIndex=index%MOD;
    for(node* head=nodes[theIndex];head!=NULL;head=head->nxt)
      if(head->index==index)return true;
    return false;
  }
  int getdata(int index){
    int theIndex=index%MOD;
    for(node* head=nodes[theIndex];head!=NULL;head=head->nxt)
      if(head->index==index)return head->data;
    return 0;
  }
};

#endif
