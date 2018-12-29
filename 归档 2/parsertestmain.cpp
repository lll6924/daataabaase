
#include <string>

extern "C"
{
  extern int yyparse(void);
}

void init();
std::string getdatabase();

int main() {
  init();
  while(1){
    printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
    yyparse();
  }
	return 0;
}
