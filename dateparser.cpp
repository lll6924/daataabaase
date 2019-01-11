
#include <string>
#include <iostream>
#include <fstream>

void prhex(unsigned char c){
  if(c==0)printf("0");
  if(c==1)printf("1");
  if(c==2)printf("2");
  if(c==3)printf("3");
  if(c==4)printf("4");
  if(c==5)printf("5");
  if(c==6)printf("6");
  if(c==7)printf("7");
  if(c==8)printf("8");
  if(c==9)printf("9");
  if(c==10)printf("A");
  if(c==11)printf("B");
  if(c==12)printf("C");
  if(c==13)printf("D");
  if(c==14)printf("E");
  if(c==15)printf("F");
}

int main() {
  std::string st;
  std::cin>>st;
  FILE* f=fopen(st.c_str(),"r");
  while(true){
    unsigned char cc;
    for(int i=0;i<1024;i++){
      fscanf(f,"%c",&cc);
      prhex(cc%16);
      prhex(cc/16);
    }
    char c;
    while((c=getchar())!='\n');
  }
  fclose(f);
	return 0;
}
