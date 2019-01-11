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
  void _tobuffers(BTreeNode* root,std::vector<uint*>& buffers){
    buffers.push_back(root->tobuffer());
    if(root->isleaf)return;
    for(int i=0;i<root->len;i++)
      _tobuffers(root->sons[i],buffers);
  }
  std::vector<uint*> tobuffers(){
    time=1;
    doit1(root);
    std::vector<uint*> toreturn;
    toreturn.clear();
    _tobuffers(root,toreturn);
    return toreturn;
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
    int tt=0;
    while(now!=NULL&&now->len==maxsons){
      tt++;
      BTreeNode* nnd=new BTreeNode();
      if(newson==NULL)nnd->isleaf=true;
        else nnd->isleaf=false;
      int offset=0;
      for(int i=0;i<=maxsons;i++)
        if(offset==0&&(i==maxsons||toadd<now->maxvalues[i])){
          tvalues[i]=toadd;
          tsons[i]=newson;
          tdata[i]=data;
          offset++;
        }else{
          tvalues[i]=now->maxvalues[i-offset];
          tsons[i]=now->sons[i-offset];
          tdata[i]=now->data[i-offset];
        }
      nnd->len=maxsons/2+1;
      for(int i=0;i<=maxsons/2;i++){
        nnd->sons[i]=tsons[i];
        nnd->data[i]=tdata[i];
        if(!nnd->isleaf){
          nnd->sons[i]->parent=nnd;
          nnd->maxvalues[i]=nnd->sons[i]->maxvalues[nnd->sons[i]->len-1];
        }else{
          nnd->maxvalues[i]=tvalues[i];
          places[nnd->data[i]].order=i;
          places[nnd->data[i]].place=nnd;
        }
      }
      now->len=maxsons-maxsons/2;
      for(int i=maxsons/2+1;i<=maxsons;i++){
        now->sons[i-maxsons/2-1]=tsons[i];
        now->data[i-maxsons/2-1]=tdata[i];
        if(!now->isleaf){
          now->sons[i-maxsons/2-1]->parent=now;
          now->maxvalues[i-maxsons/2-1]=now->sons[i-maxsons/2-1]->maxvalues[now->sons[i-maxsons/2-1]->len-1];
        }else{
          now->maxvalues[i-maxsons/2-1]=tvalues[i];
          places[now->data[i-maxsons/2-1]].order=i-maxsons/2-1;
          places[now->data[i-maxsons/2-1]].place=now;
        }
      }

      nnd->right=now;
      nnd->left=now->left;
      if(now->left!=NULL)now->left->right=nnd;
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
      newson->left=NULL;
      newson->right=root;
      root->left=newson;
      root->right=NULL;
      newson->parent=nroot;
      root->parent=nroot;
      root=nroot;
    }else{//normal add
      int offset=0;
      for(int i=0;i<now->len+1;i++)
        if(offset==0&&(i==now->len||toadd<now->maxvalues[i])){
          tvalues[i]=toadd;
          tsons[i]=newson;
          tdata[i]=data;
          if(newson!=NULL){
            newson->parent=now;
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
        now->data[i]=tdata[i];
        if(!now->isleaf)now->maxvalues[i]=now->sons[i]->maxvalues[now->sons[i]->len-1];
        else{
          now->maxvalues[i]=tvalues[i];
          places[now->data[i]].order=i;
          places[now->data[i]].place=now;
        }
      }
    }
    while(now!=NULL&&now->parent!=NULL){
      now=now->parent;
      for(int i=0;i<now->len;i++)
        now->maxvalues[i]=now->sons[i]->maxvalues[now->sons[i]->len-1];
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
        if(now->maxvalues[mid]>=left)t2=mid;
          else t1=mid+1;
      }
      now=now->sons[t1];
    }
    int t1=0,t2=now->len-1;
    while(t1<t2){
      int mid=(t1+t2)/2;
      if(now->maxvalues[mid]>=left)t2=mid;
        else t1=mid+1;
    }
    //printf("%d\n",now->maxvalues[t1]);
    BTreeNode* now2=now;
    while(now->maxvalues[t1]>=left&&now->maxvalues[t1]<right){
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
    while(now2->maxvalues[t2]<right&&now2->maxvalues[t2]>=left){
      ret.push_back(now2->data[t2]);
      t2++;
      //printf("%d\n",t2);
      if(t2==now2->len){
        now2=now2->right;
        if(now2==NULL)break;
        t2=0;
      }
    }
    return ret;
  }
  int findexact(int value){//return data
    BTreeNode* now=root;
    while(now->isleaf==false){
      int t1=0,t2=now->len-1;
      while(t1<t2){
        int mid=(t1+t2)/2;
        if(now->maxvalues[mid]>=value)t2=mid;
          else t1=mid+1;
      }
      now=now->sons[t1];
    }
    int t1=0,t2=now->len-1;
    while(t1<t2){
      int mid=(t1+t2)/2;
      if(now->maxvalues[mid]>=value)t2=mid;
        else t1=mid+1;
    }
    if(now->maxvalues[t1]!=value)return -1;
    return now->data[t1];
  }
  void deletedata(int data){
    //printf("%d %d\n",data,places.size());
    BTreeNode* now=places[data].place;
    int order=places[data].order;
    //printf("%d\n",now->maxvalues[order]);
    while(true){
      //printf("123\n");
      for(int i=order;i<now->len-1;i++){
        //printf("%d\n",i);
        now->sons[i]=now->sons[i+1];
        now->maxvalues[i]=now->maxvalues[i+1];
        now->data[i]=now->data[i+1];
        if(now->isleaf){
          places[now->data[i]].order=i;
          places[now->data[i]].place=now;
        }else{
          now->maxvalues[i]=now->sons[i]->maxvalues[now->sons[i]->len-1];
        }
      }
      //printf("after\n");
      now->len--;
      if(now->len>=maxsons/2)break;
      if(now==root&&now->isleaf==false&&now->len<=1){
        root=root->sons[0];
        root->parent=NULL;
        delete now;
        break;
      }
      BTreeNode* merge1;
      BTreeNode* merge2;
      //printf("in\n");
      //printf("%d\n",now->parent->len);
      if(now->left!=NULL&&now->left->parent==now->parent){
        //printf("mergeleft");
        BTreeNode* helper=now->left;
        if(helper->len>maxsons/2){
          for(int i=now->len;i>0;i--){
            now->sons[i]=now->sons[i-1];
            now->maxvalues[i]=now->maxvalues[i-1];
            now->data[i]=now->data[i-1];
            if(now->isleaf){
              places[now->data[i]].order=i;
              places[now->data[i]].place=now;
            }
          }
          now->len++;
          now->sons[0]=helper->sons[helper->len-1];
          now->maxvalues[0]=helper->maxvalues[helper->len-1];
          now->data[0]=helper->data[helper->len-1];
          if(!now->isleaf)
            now->sons[0]->parent=now;
          if(now->isleaf){
            places[now->data[0]].order=0;
            places[now->data[0]].place=now;
          }
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
              //printf("mergeright");

        BTreeNode* helper=now->right;
        if(helper->len>maxsons/2){
          now->sons[now->len]=helper->sons[0];
          now->maxvalues[now->len]=helper->maxvalues[0];
          now->data[now->len]=helper->data[0];
          if(!now->isleaf)
            now->sons[now->len]->parent=now;
          if(now->isleaf){
            places[now->data[now->len]].order=now->len;
            places[now->data[now->len]].place=now;
          }
          now->len++;
          for(int i=0;i<helper->len-1;i++){
            helper->sons[i]=helper->sons[i+1];
            helper->maxvalues[i]=helper->maxvalues[i+1];
            helper->data[i]=helper->data[i+1];
            if(helper->isleaf){
              places[helper->data[i]].order=i;
              places[helper->data[i]].place=helper;
            }
          }
          helper->len--;
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
      if(merge2->isleaf)
        for(int i=0;i<merge2->len;i++){
          //printf("placealter: %d %d\n",merge2->data[i],i);
          places[merge2->data[i]].order=i;
          places[merge2->data[i]].place=merge2;
        }
      delete merge1;
    }
    //printf("Afterwards..\n");
    while(now!=NULL&&now->parent!=NULL){
      now=now->parent;
      for(int i=0;i<now->len;i++)
        now->maxvalues[i]=now->sons[i]->maxvalues[now->sons[i]->len-1];
    }
  }
  void doit1(BTreeNode* root){
    root->iden=time++;
    if(root->isleaf)return;
    for(int i=0;i<root->len;i++)
      doit1(root->sons[i]);
  }
  void doit2(BTreeNode* root){
    printf("%d left:",root->iden);
    if(root->left==NULL)printf("NULL right:");
      else printf("%d right:",root->left->iden);
    if(root->right==NULL)printf("NULL\n");
      else printf("%d\n",root->right->iden);
    printf("Values: ");
    for(int i=0;i<root->len;i++)
      printf("%d ",root->maxvalues[i]);
    printf("\n");
    if(root->isleaf){
        printf("Datas: ");

      for(int i=0;i<root->len;i++)
      printf("%d ",root->data[i]);
    printf("\n");
      printf("\n");
    return;}
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
  void buildtree(std::vector<uint*>& inp){
    BTreeNode* buf=new BTreeNode[inp.size()+1];
    //printf("%d\n",inp.size());
    int maxdata=0;
    for(int i=0;i<inp.size();i++)
      if(inp[i][0]==1){
        //printf("%d\n",inp[i][2]);
        for(int j=0;j<inp[i][2];j++){
          if(inp[i][6+j+2*inp[i][2]]>maxdata)maxdata=inp[i][6+j+2*inp[i][2]];
         // printf("%d %d %d\n",inp[i][6+j],inp[i][6+j+inp[i][2]],inp[i][6+j+2*inp[i][2]]);
        }
      }
    //printf("  %d\n",maxdata);
    places.resize(maxdata+1);
    for(int i=0;i<inp.size();i++){
      int u=inp[i][1];
      buf[u].iden=u;
      buf[u].isleaf=inp[i][0]==1;
      buf[u].len=inp[i][2];
      if(inp[i][3]==0)buf[u].left=NULL;
      else buf[u].left=&buf[inp[i][3]];
      if(inp[i][4]==0)buf[u].right=NULL;
      else buf[u].right=&buf[inp[i][4]];
      if(inp[i][5]==0)buf[u].parent=NULL;
      else buf[u].parent=&buf[inp[i][5]];
      if(buf[u].parent==NULL)root=&buf[u];
      for(int j=0;j<buf[u].len;j++){
        if(inp[i][6+j]==0)buf[u].sons[j]=NULL;
        else buf[u].sons[j]=&buf[inp[i][6+j]];
        buf[u].maxvalues[j]=inp[i][6+j+buf[u].len];
        buf[u].data[j]=inp[i][6+j+2*buf[u].len];
        int dt=buf[u].data[j];
        places[dt].order=j;
        places[dt].place=&buf[u];
      }
    }
  }
};

#endif
