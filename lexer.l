%{
#include "defs.h"
#include "y.tab.h"
int mylineno = 0;


extern "C"
{
  int yylex(void);
}
//%option caseless

%}

%option noyywrap

NEWLINE (\r|\n|\r\n)
SIMPLE_OPERATOR (";"|"("|")"|","|"."|"="|"<"|">"|"*"|"-")
WHITESPACE ([ \t]+)

IDENTIFIER [A-Za-z][_0-9A-Za-z]*
VALUE_INT [0-9]+
VALUE_STRING '(\\'|[^'])*'

%%

{WHITESPACE}
{NEWLINE} {mylineno++;}

"DATABASE" {return DATABASE;}
"DATABASES" {return DATABASES;}
"TABLE" {return TABLE;}
"TABLES" {return TABLES;}
"SHOW" {return SHOW;}
"CREATE" {return CREATE;}
"DROP" {return DROP;}
"USE" {return USE;}
"PRIMARY" {return PRIMARY;}
"KEY" {return KEY;}
"NOT" {return NOT;}
"NULL" {return NULL_;}
"INSERT" {return INSERT;}
"INTO" {return INTO;}
"VALUES" {return VALUES;}
"DELETE" {return DELETE;}
"FROM" {return FROM;}
"WHERE" {return WHERE;}
"UPDATE" {return UPDATE;}
"SET" {return SET;}
"SELECT" {return SELECT;}
"IS" {return IS;}
"INT" {return INT;}
"CHAR" {return VARCHAR;}
"DESC" {return DESC;}
"REFERENCES" {return REFERENCES;}
"INDEX" {return INDEX;}
"AND" {return AND;}
"DATE" {return DATE;}
"FLOAT" {return FLOAT;}
"FOREIGN" {return FOREIGN;}
"EXIT" {return EXIT;}

"<>" {return NOT_EQUAL;}
"<=" {return LESS_OR_EQUAL;}
">=" {return MORE_OR_EQUAL;}

{IDENTIFIER}  {yylval=new semvalue();identifier(yytext,yylval);return IDENTIFIER;}

{VALUE_INT} {yylval=new semvalue();intConstant(yytext,yylval);return VALUE_INT;}

{VALUE_STRING} {yylval=new semvalue();stringConstant(yytext,yylval);return VALUE_STRING;}

{SIMPLE_OPERATOR} {return yytext[0];}

%%

