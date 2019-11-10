%{

#include <iostream>
#include <string>
#include <stdio.h>
#include "defs.h"

using namespace std;

#define YYMAXDEPTH 1000000
#define YYINITDEPTH 800000

extern "C"
{
  void yyerror(const char *s);
  int yyparse();
  extern int yylex(void);
}
std::string getdatabase();

%}
%token DATABASE DATABASES TABLE TABLES SHOW CREATE DROP USE PRIMARY KEY NOT NULL_ INSERT INTO VALUES DELETE FROM WHERE UPDATE SET SELECT IS INT VARCHAR DESC REFERENCES INDEX AND DATE FLOAT FOREIGN EXIT
%token ';' '(' ')' ',' '.' '='  '<' '>' '*' '-'
%token NOT_EQUAL MORE_OR_EQUAL LESS_OR_EQUAL
%token VALUE_STRING VALUE_INT IDENTIFIER


%%
program  :
         | program stmt
         ;

stmt  : sysStmt ';'
      {
        $1->handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
      | dbStmt ';'
      {
        $1->handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
      | tbStmt ';'
      {
        $1->handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
      | idxStmt ';'
      {
        $1->handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
      ;

sysStmt  : SHOW DATABASES
      {
        $$=new semvalue();
        $$->handler=new ShowDatabases();
      }
         | EXIT
      {
        $$=new semvalue();
        $$->handler=new Exiter();
      }
         ;

dbStmt  : CREATE DATABASE dbName
      {
        $$=new semvalue();
        $$->handler=new CreateDatabase($3->iden);
      }
        | DROP DATABASE dbName
      {
        $$=new semvalue();
        $$->handler=new DropDatabase($3->iden);
      }
        | USE dbName
      {
        $$=new semvalue();
        $$->handler=new UseDatabase($2->iden);
      }
        | SHOW TABLES
      {
        $$=new semvalue();
        $$->handler=new ShowTables();
      }
        ;

tbStmt  : CREATE TABLE tbName '(' fieldList ')'
      {
        $$=new semvalue();
        $$->handler=new CreateTable($3->iden,$5->fields);
      }
        | DROP TABLE tbName
      {
        $$=new semvalue();
        $$->handler=new DropTable($3->iden);
      }
        | DESC tbName
      {
        $$=new semvalue();
        $$->handler=new DescTable($2->iden);
      }
        | INSERT INTO tbName VALUES valueLists
      {
        $$=new semvalue();
        $$->handler=new InsertValue($3->iden,$5->values);
      }
        | DELETE FROM tbName WHERE whereClause
      {
        $$=new semvalue();
        $$->handler=new DeleteValues($3->iden,$5->wheres);
      }
        | UPDATE tbName SET setClause WHERE whereClause
      {
        $$=new semvalue();
        $$->handler=new UpdateValues($2->iden,$4->sets,$6->wheres);
      }
        | SELECT selector FROM tableList WHERE whereClause
      {
        $$=new semvalue();
        $$->handler=new SelectValues($2->selector,$4->tables,$6->wheres);
      }
        ;

idxStmt  : CREATE INDEX tbName '(' colName ')'
      {
        $$=new semvalue();
        $$->handler=new CreateIndex($3->iden,$5->iden);
      }
         | DROP INDEX tbName '(' colName ')'
      {
        $$=new semvalue();
        $$->handler=new DropIndex($3->iden,$5->iden);
      }
         ;

fieldList  : field
      {
        $$=new semvalue();
        $$->fields.clear();
        $$->fields.push_back($1->fielditem);
      }
           | fieldList ',' field
      {
        $$=new semvalue();
        $$->fields.clear();
        $$->fields.swap($1->fields);
        $$->fields.push_back($3->fielditem);
      }
           ;

field  : colName type notNullOrEmpty
        {
          $$=new semvalue();
          $$->fielditem.type=Field::column;
          $$->fielditem.Nullable=$3->Nullable;
          $$->fielditem.thetype=$2->colType;
          $$->fielditem.colName=$1->iden;
        }
       | PRIMARY KEY '(' columnList ')'
        {
          $$=new semvalue();
          $$->fielditem.type=Field::primarykey;
          $$->fielditem.columns.swap($4->columnlist);
        }
       | FOREIGN KEY '(' colName ')' REFERENCES tbName '(' colName ')'
        {
          $$=new semvalue();
          $$->fielditem.type=Field::foreignkey;
          $$->fielditem.colName=$4->iden;
          $$->fielditem.reftable=$7->iden;
          $$->fielditem.refcolumn=$9->iden;
        }
       ;

notNullOrEmpty : NOT NULL_
                  {
                    $$=new semvalue();
                    $$->Nullable=false;
                  }
               |
                  {
                    $$=new semvalue();
                    $$->Nullable=true;
                  }
               ;

type  : INT valueIntOrEmpty
        {
          $$=new semvalue();
          $$->colType.typeId=Type::_INT;
          $$->colType.len=$2->intValue;
        }
      | VARCHAR valueIntOrEmpty
        {
          $$=new semvalue();
          $$->colType.typeId=Type::_CHAR;
          $$->colType.len=$2->intValue;
        }
      | DATE
        {
          $$=new semvalue();
          $$->colType.typeId=Type::_DATE;
        }
      | FLOAT
        {
          $$=new semvalue();
          $$->colType.typeId=Type::_FLOAT;
        }
      ;

valueIntOrEmpty : '(' VALUE_INT ')'
                  {
                    $$=new semvalue();
                    $$->intValue=$2->intValue;
                  }
                |
                  {
                    $$=new semvalue();
                    $$->intValue=0;
                  }
                ;

valueLists  : '(' valueList ')' ',' valueLists
              {
                $$=new semvalue();
                $$->values.swap($5->values);
                $$->values.push_back($2->valuelist);
              }
              | '(' valueList ')'
              {
                $$=new semvalue();
                $$->values.clear();
                $$->values.push_back($2->valuelist);
              }
            ;


valueList  : value
            {
              $$=new semvalue();
              $$->valuelist.clear();
              $$->valuelist.push_back($1->value);
            }
           | valueList ',' value
            {
              $$=new semvalue();
              $$->valuelist.swap($1->valuelist);
              $$->valuelist.push_back($3->value);
            }
           ;

value  : VALUE_INT
        {
          $$=new semvalue();
          $$->value.type=Value::_INT;
          $$->value.intValue=$1->intValue;
        }
       | VALUE_STRING
        {
          $$=new semvalue();
          $$->value.type=Value::_STRING;
          $$->value.stringValue=$1->stringValue;
        }
      | VALUE_FLOAT
        {
          $$=new semvalue();
          $$->value.type=Value::_FLOAT;
          $$->value.floatValue=$1->floatValue;
        }
      | VALUE_DATE
        {
          $$=new semvalue();
          $$->value.type=Value::_DATE;
          $$->value.dateValue=$1->dateValue;
        }
       | NULL_
        {
          $$=new semvalue();
          $$->value.type=Value::_NULL;
        }
       ;

VALUE_FLOAT : VALUE_INT '.' VALUE_INT
              {
                $$=new semvalue();
                float fl=$3->intValue;
                while(fl>=1)fl/=10.0;
                $$->floatValue=$1->intValue+fl;
              }
            ;

VALUE_DATE : VALUE_INT '-' VALUE_INT '-' VALUE_INT
            {
              $$=new semvalue();
              $$->dateValue=$1->intValue*10000+$3->intValue*100+$5->intValue;
            }
           ;

whereClause  : whereClauseItem
              {
                $$=new semvalue();
                $$->wheres.clear();
                $$->wheres.push_back($1->whereitem);
              }
             | whereClauseItem AND whereClause
              {
                $$=new semvalue();
                $$->wheres.swap($3->wheres);
                $$->wheres.push_back($1->whereitem);
              }
             ;

whereClauseItem: col op expr
                {
                  $$=new semvalue();
                  $$->whereitem.type=WhereItem::OPERATION;
                  $$->whereitem.left=$1->column;
                  $$->whereitem.Operator=$2->Operator;
                  $$->whereitem.expr=$3->expr;
                }
              | col IS NULL_
                {
                  $$=new semvalue();
                  $$->whereitem.type=WhereItem::ISNULL;
                  $$->whereitem.left=$1->column;
                }
              | col IS NOT NULL_
                {
                  $$=new semvalue();
                  $$->whereitem.type=WhereItem::ISNOTNULL;
                  $$->whereitem.left=$1->column;
                }
              ;


col  : colName
      {
        $$=new semvalue();
        $$->column.hastable=false;
        $$->column.column=$1->iden;
      }
     | tbName '.' colName
      {
        $$=new semvalue();
        $$->column.hastable=true;
        $$->column.table=$1->iden;
        $$->column.column=$3->iden;
      }
     ;

op  : '='
      {
        $$=new semvalue();
        $$->Operator=WhereItem::_EQUAL;
      }
    | NOT_EQUAL
      {
        $$=new semvalue();
        $$->Operator=WhereItem::_NOT_EQUAL;
      }
    | LESS_OR_EQUAL
      {
        $$=new semvalue();
        $$->Operator=WhereItem::_LESS_OR_EQUAL;
      }
    | MORE_OR_EQUAL
      {
        $$=new semvalue();
        $$->Operator=WhereItem::_MORE_OR_EQUAL;
      }
    | '<'
      {
       $$=new semvalue();
       $$->Operator=WhereItem::_LESS;
      }
    | '>'
      {
        $$=new semvalue();
        $$->Operator=WhereItem::_MORE;
      }
    ;

expr  : value
        {
          $$=new semvalue();
          $$->expr.type=Expr::VALUE;
          $$->expr.value=$1->value;
        }
      | col
        {
          $$=new semvalue();
          $$->expr.type=Expr::COL;
          $$->expr.column=$1->column;
        }
      ;

setClause  : colName '=' value
            {
              $$=new semvalue();
              $$->set.column=$1->iden;
              $$->set.value=$3->value;
              $$->sets.clear();
              $$->sets.push_back($$->set);
            }
           | setClause ',' colName '=' value
            {
              $$=new semvalue();
              $$->set.column=$3->iden;
              $$->set.value=$5->value;
              $$->sets.swap($1->sets);
              $$->sets.push_back($$->set);
            }
           ;

selector  : '*'
            {
              $$=new semvalue();
              $$->selector.type=Selector::star;
            }
          | cols
            {
              $$=new semvalue();
              $$->selector.type=Selector::cols;
              $$->selector.columns=$1->columns;
            }
          ;

cols : col
      {
        $$=new semvalue();
        $$->columns.clear();
        $$->columns.push_back($1->column);
      }
     | cols ',' col
      {
        $$=new semvalue();
        $$->columns.swap($1->columns);
        $$->columns.push_back($3->column);
      }
     ;



tableList  : tbName
            {
              $$=new semvalue();
              $$->tables.clear();
              $$->tables.push_back($1->iden);
            }
           | tableList ',' tbName
            {
              $$=new semvalue();
              $$->tables.swap($1->tables);
              $$->tables.push_back($3->iden);
            }
           ;

columnList  : colName
              {
                $$=new semvalue();
                $$->columnlist.clear();
                $$->columnlist.push_back($1->iden);
              }
            | columnList ',' colName
              {
                $$=new semvalue();
                $$->columnlist.swap($1->columnlist);
                $$->columnlist.push_back($3->iden);
              }
            ;

dbName  : IDENTIFIER
        {
          $$=new semvalue();
          $$->iden=$1->iden;
        }
        ;

tbName  : IDENTIFIER
        {
          $$=new semvalue();
          $$->iden=$1->iden;
        }
        ;

colName : IDENTIFIER
        {
          $$=new semvalue();
          $$->iden=$1->iden;
        }
        ;

%%

void yyerror(const char *s)
{
  cerr<<s<<endl;
}
