#ifndef B_PLUS_TREE
#define B_PLUS_TREE

#include <vector>
#include "utils/pagedef.h"

const int maxsons=160;

struct BTreeNode{
  BTreeNode* left;
  BTreeNode* right;
  BTreeNode* parent;
  BTreeNode* sons[maxsons];
  int maxvalues[maxsons],data[maxsons],iden,len;
  bool isleaf;
  uint* tobuffer(){
    uint* ret=new uint[512];
    if(isleaf)ret[0]=1;
      else ret[0]=0;
    ret[1]=iden;
    ret[2]=len;
    if(left==NULL)ret[3]=0;
      else ret[3]=left->iden;
    if(right==NULL)ret[4]=0;
      else ret[4]=right->iden;
    if(parent==NULL)ret[5]=0;
      else ret[5]=parent->iden;
    for(int i=0;i<len;i++){
      if(!isleaf)ret[6+i]=sons[i]->iden;
      ret[6+len+i]=maxvalues[i];
      ret[6+len+len+i]=data[i];
    }
    return ret;
  }
};

struct Record{
  BTreeNode* place;
  int order;
};

struct BTree{
  std::vector<Record> places;
  BTreeNode* root;
  BTreeNode* tsons[maxsons+1];
  int tvalues[maxsons+1],tdata[maxsons+1],time;
  BTree(){
    root=new BTreeNode();
    root->isleaf=true;
    root->left=root->right=NULL;
    root->parent=NULL;
    root->len=0;
  }
  void insertdata(int place,int data){
    while(places.size()<data+1){
      Record r;
      places.push_back(r);
    }
    BTreeNode* now=root;
    while(now->isleaf==false){
      int t1=0,t2=now->len-1;
      while(t1<t2){
        int mid=(t1+t2)/2;
        if(now->maxvalues[mid]>place)t2=mid;
          else t1=mid+1;
      }
      now=now->sons[t1];
    }
    int toadd=place;
    BTreeNode* newson=NULL;
    while(now!=NULL&&now->len==maxsons-1){
      BTreeNode* nnd=new BTreeNode();
      if(newson==NULL)nnd->isleaf=true;
        else nnd->isleaf=false;
      int offset=0;
      for(int i=0;i<=maxsons;i++)
        if(offset==0&&toadd<now->maxvalues[i]){
          tvalues[i]=toadd;
          tsons[i]=newson;
          tdata[i]=data;
          if(newson!=NULL){
            if(i<maxsons&&i>0){
              newson->left=now->sons[i]->left;
              if(now->sons[i]->left!=NULL)now->sons[i]->left->right=newson;
              newson->right=now->sons[i-1]->right;
              if(now->sons[i-1]->right!=NULL)now->sons[i-1]->right->left=newson;
            }else if(i==maxsons){
              newson->right=now->sons[i-1]->right;
              if(now->sons[i-1]->right!=NULL)now->sons[i-1]->right->left=newson;
              newson->left=now->sons[i-1];
              now->sons[i-1]->right=newson;
            }else{
              newson->left=now->sons[i]->left;
              if(now->sons[i]->left!=NULL)now->sons[i]->left->right=newson;
              newson->right=now->sons[i];
              now->sons[i]->left=newson;
            }
            if(i<=maxsons/2){
              newson->parent=nnd;
            }else {
              newson->parent=now;
            }
          }
          if(nnd->isleaf){
            if(i<=maxsons/2){
              places[data].order=i;
              places[data].place=nnd;
            }else {
              places[data].order=i-maxsons/2-1;
              places[data].place=now;
            }
          }
          offset++;
        }else{
          tvalues[i]=now->maxvalues[i-offset];
          tsons[i]=now->sons[i-offset];
          tdata[i]=now->data[i-offset];
        }
      nnd->len=maxsons/2+1;
      for(int i=0;i<=maxsons/2;i++){
        nnd->sons[i]=tsons[i];
        nnd->maxvalues[i]=tvalues[i];
        nnd->data[i]=tdata[i];
      }
      now->len=maxsons/2;
      for(int i=maxsons/2+1;i<=maxsons;i++){
        now->sons[i-maxsons/2-1]=tsons[i];
        now->maxvalues[i-maxsons/2-1]=tvalues[i];
        now->data[i-maxsons/2-1]=tdata[i];
      }
      nnd->right=now;
      nnd->left=now->left;
      now->left->right=nnd;
      now->left=nnd;
      toadd=nnd->maxvalues[nnd->len-1];
      newson=nnd;
      now=now->parent;
    }
    if(now==NULL){//newroot
      BTreeNode* nroot=new BTreeNode();
      nroot->left=nroot->right=nroot->parent=NULL;
      nroot->len=2;
      nroot->sons[0]=newson;
      nroot->sons[1]=root;
      nroot->maxvalues[0]=newson->maxvalues[newson->len-1];
      nroot->maxvalues[1]=root->maxvalues[root->len-1];
      newson->left=root->left;
      root->left->right=newson;
      root->left=newson;
      newson->right=root;
      newson->parent=nroot;
      root->parent=nroot;
      root=nroot;
    }else{//normal add
      int offset=0;
      for(int i=0;i<now->len+1;i++)
        if(offset==0&&toadd<now->maxvalues[i]){
          tvalues[i]=toadd;
          tsons[i]=newson;
          tdata[i]=data;
          if(newson!=NULL){
            newson->parent=now;
            if(i<now->len&&i>0){
              newson->left=now->sons[i]->left;
              if(now->sons[i]->left!=NULL)now->sons[i]->left->right=newson;
              newson->right=now->sons[i-1]->right;
              if(now->sons[i-1]->right!=NULL)now->sons[i-1]->right->left=newson;
            }else if(i==now->len){
              newson->right=now->sons[i-1]->right;
              if(now->sons[i-1]->right!=NULL)now->sons[i-1]->right->left=newson;
              newson->left=now->sons[i-1];
              now->sons[i-1]->right=newson;
            }else{
              newson->left=now->sons[i]->left;
              if(now->sons[i]->left!=NULL)now->sons[i]->left->right=newson;
              newson->right=now->sons[i];
              now->sons[i]->left=newson;
            }
          }
          if(now->isleaf){
            places[data].order=i;
            places[data].place=now;
          }
          offset++;
        }else{
          tvalues[i]=now->maxvalues[i-offset];
          tsons[i]=now->sons[i-offset];
          tdata[i]=now->data[i-offset];
        }
      now->len++;
      for(int i=0;i<now->len;i++){
        now->sons[i]=tsons[i];
        now->maxvalues[i]=tvalues[i];
        now->data[i]=tdata[i];
      }
    }
  }
  void changedata(int olddata,int newdata){
    places[olddata].place->data[places[olddata].order]=newdata;
    places[newdata]=places[olddata];
  }
  std::vector<int> finddata(int left,int right){
    std::vector<int> ret;
    ret.clear();
    BTreeNode* now=root;
    while(now->isleaf==false){
      int t1=0,t2=now->len-1;
      while(t1<t2){
        int mid=(t1+t2)/2;
        if(now->maxvalues[mid]>left)t2=mid;
          else t1=mid+1;
      }
      now=now->sons[t1];
    }
    int t1=0,t2=now->len-1;
    while(t1<t2){
      int mid=(t1+t2)/2;
      if(now->maxvalues[mid]>left)t2=mid;
        else t1=mid+1;
    }
    BTreeNode* now2=now;
    while(now->maxvalues[t1]>=left){
      ret.push_back(now->data[t1]);
      t1--;
      if(t1<0){
        now=now->left;
        if(now==NULL)break;
        t1=now->len-1;
      }
    }
    t2++;
    if(t2==now2->len){
      now2=now2->right;
      if(now2==NULL)return ret;
      t2=0;
    }
    while(now2->maxvalues[t2]<right){
      ret.push_back(now2->data[t2]);
      t2++;
      if(t2==now2->len){
        now2=now2->right;
        if(now2==NULL)break;
        t2=0;
      }
    }
    return ret;
  }
  void deletedata(int data){
    BTreeNode* now=places[data].place;
    int order=places[data].order;
    while(true){
      for(int i=order;i<now->len-1;i++){
        now->sons[i]=now->sons[i+1];
        now->maxvalues[i]=now->maxvalues[i+1];
        now->data[i]=now->data[i+1];
      }
      if(now->len>=maxsons/2)break;
      if(now==root&&now->isleaf==false&&now->len<=1){
        root=root->sons[0];
        root->parent=NULL;
        delete now;
        break;
      }
      BTreeNode* merge1;
      BTreeNode* merge2;
      if(now->left!=NULL&&now->left->parent==now->parent){
        BTreeNode* helper=now->left;
        if(helper->len>maxsons/2){
          for(int i=now->len;i>0;i--){
            now->sons[i]=now->sons[i-1];
            now->maxvalues[i]=now->maxvalues[i-1];
            now->data[i]=now->data[i-1];
          }
          now->len++;
          now->sons[0]=helper->sons[helper->len-1];
          now->maxvalues[0]=helper->maxvalues[helper->len-1];
          now->data[0]=helper->data[helper->len-1];
          helper->len--;
          for(int i=0;i<now->parent->len;i++)
            if(now->parent->sons[i]==helper){
              now->parent->maxvalues[i]=helper->maxvalues[helper->len-1];
              break;
            }
          break;
        }else{
          merge1=helper;
          merge2=now;
        }
      }else if(now->right!=NULL&&now->right->parent==now->parent){
        BTreeNode* helper=now->right;
        if(helper->len>maxsons/2){
          now->sons[now->len]=helper->sons[0];
          now->maxvalues[now->len]=helper->maxvalues[0];
          now->data[now->len]=helper->data[0];
          now->len++;
          for(int i=0;i<helper->len-1;i++){
            helper->sons[i]=helper->sons[i+1];
            helper->maxvalues[i]=helper->maxvalues[i+1];
            helper->data[i]=helper->data[i+1];
          }
          for(int i=0;i<now->parent->len;i++)
            if(now->parent->sons[i]==now){
              now->parent->maxvalues[i]=now->maxvalues[now->len-1];
              break;
            }
          break;
        }else{
          merge1=now;
          merge2=helper;
        }
      }else break;
      for(int i=0;i<merge1->parent->len;i++)
        if(merge1->parent->sons[i]==merge1){
          order=i;
          break;
        }
      now=now->parent;
      merge2->left=merge1->left;
      if(merge1->left!=NULL){
        merge1->left->right=merge2;
      }
      for(int i=merge2->len-1;i>=0;i--){
        merge2->sons[i+merge1->len]=merge2->sons[i];
        merge2->maxvalues[i+merge1->len]=merge2->maxvalues[i];
        merge2->data[i+merge1->len]=merge2->data[i];
      }
      for(int i=0;i<merge1->len;i++){
        merge2->sons[i]=merge1->sons[i];
        if(!merge2->isleaf)merge2->sons[i]->parent=merge2;
        merge2->maxvalues[i]=merge1->maxvalues[i];
        merge2->data[i]=merge1->data[i];
      }
      merge2->len+=merge1->len;
      delete merge1;
    }
  }
  void doit1(BTreeNode* root){
    root->iden=time++;
    if(root->isleaf)return;
    for(int i=0;i<root->len;i++)
      doit1(root->sons[i]);
  }
  void doit2(BTreeNode* root){
    printf("Values: ");
    for(int i=0;i<root->len;i++)
      printf("%d",root->maxvalues[i]);
    if(root->isleaf)return;
    printf("Sons: ");
    for(int i=0;i<root->len;i++)
      printf("%d ",root->sons[i]->iden);
    printf("\n\n");
    for(int i=0;i<root->len;i++)
      doit2(root->sons[i]);
  }
  void print(){
    time=1;
    doit1(root);
    doit2(root);
  }
  void buildtree(std::vector<uint*>){
    
  }
};

#endif
