
extern "C"
{
  extern int yyparse(void);
}

void init();

int main() {
  init();
  while(1){
    printf("%s->",database.length()?database.c_str():"NULL");
    yyparse();
  }
	return 0;
}
