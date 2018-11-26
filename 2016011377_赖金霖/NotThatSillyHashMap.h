#ifndef NOT_THAT_SILLY_HASH_MAP
#define NOT_THAT_SILLY_HASH_MAP

#include <vector>

const int MODH=989381;

struct node{
  int index,data;
  node* nxt;
};

class NotThatSillyHashMap{
node** nodes;
public:
  NotThatSillyHashMap(){
    nodes=new node*[MODH];
    for(int i=0;i<MODH;i++)
      nodes[i]=NULL;
  }
  bool insert(int index,int data){
    int theIndex=index%MODH;
    node* newnode=new node();
    newnode->index=index;
    newnode->data=data;
    newnode->nxt=nodes[theIndex];
    nodes[theIndex]=newnode;
    return true;
  }
  bool find(int index){
    int theIndex=index%MODH;
    for(node* head=nodes[theIndex];head!=NULL;head=head->nxt)
      if(head->index==index)return true;
    return false;
  }
  int getdata(int index){
    int theIndex=index%MODH;
    for(node* head=nodes[theIndex];head!=NULL;head=head->nxt)
      if(head->index==index)return head->data;
    return 0;
  }
  void replace(int index,int data){
    int theIndex=index%MODH;
    for(node* head=nodes[theIndex];head!=NULL;head=head->nxt)
      if(head->index==index)head->data=data;
  }
  void deleteit(int index){
    int theIndex=index%MODH;
    node* head=nodes[theIndex];
    if(head==NULL)return;
    if(head->index==index){
      nodes[theIndex]=head->nxt;
      delete head;
      return;
    }
    node* last=head;
    for(head=head->nxt;head!=NULL;head=head->nxt){
      if(head->index==index){
        last->nxt=head->nxt;
        delete head;
        return;
      }
      last=head;
    }
  }
};

#endif
