%{

#include <iostream>
#include <string>
#include <stdio.h>
#include "defs.h"

using namespace std;


extern "C"
{
  void yyerror(const char *s);
  int yyparse();
  extern int yylex(void);
}
%}
%token DATABASE DATABASES TABLE TABLES SHOW CREATE DROP USE PRIMARY KEY NOT NULL_ INSERT INTO VALUES DELETE FROM WHERE UPDATE SET SELECT IS INT VARCHAR DESC REFERENCES INDEX AND DATE FLOAT FOREIGN
%token ';' '(' ')' ',' '.' '='  '<' '>' '*'
%token NOT_EQUAL MORE_OR_EQUAL LESS_OR_EQUAL
%token VALUE_STRING VALUE_INT IDENTIFIER

%%
program  :
         | program stmt
         ;

stmt  : sysStmt ';'
      {
        $1.handler->accept();
      }
      | dbStmt ';'
      {
        $1.handler->accept();
      }
      | tbStmt ';'
      {
        $1.handler->accept();
      }
      | idxStmt ';'
      {
        $1.handler->accept();
      }
      ;

sysStmt  : SHOW DATABASES
      {
        $$.handler=new ShowDatabases();
      }
         ;

dbStmt  : CREATE DATABASE dbName
      {
        $$.handler=new CreateDatabase($3.iden);
      }
        | DROP DATABASE dbName
      {
        $$.handler=new DropDatabase($3.iden);
      }
        | USE dbName
      {
        $$.handler=new UseDatabase($2.iden);
      }
        | SHOW TABLES
      {
        $$.handler=new ShowTables();
      }
        ;

tbStmt  : CREATE TABLE tbName '(' fieldList ')'
      {
        $$.handler=new CreateTable($3.iden,$5.fields);
      }
        | DROP TABLE tbName
      {
        $$.handler=new DropTable($3.iden);
      }
        | DESC tbName
      {
        $$.handler=new DescTable($2.iden);
      }
        | INSERT INTO tbName VALUES valueLists
      {
        $$.handler=new InsertValue($3.iden,$5.values);
      }
        | DELETE FROM tbName WHERE whereClause
      {
        $$.handler=new DeleteValues($3.iden,$5.wheres);
      }
        | UPDATE tbName SET setClause WHERE whereClause
      {
        $$.handler=new UpdateValues($2.iden,$4.sets,$6.wheres);
      }
        | SELECT selector FROM tableList WHERE whereClause
      {
        $$.handler=new SelectValues($2.selector,$4.tables,$6.wheres);
      }
        ;

idxStmt  : CREATE INDEX tbName '(' colName ')'
      {
        $$.handler=new CreateIndex($3.iden,$5.iden);
      }
         | DROP INDEX tbName '(' colName ')'
      {
        $$.handler=new DropIndex($3.iden,$5.iden);
      }
         ;

fieldList  : field
      {
        $$.fields.clear();
        $$.fields.push_back($1.fielditem);
      }
           | fieldList ',' field
      {
        $$.fields.clear();
        $$.fields.swap($1.fields);
        $$.fields.push_back($3.fielditem);
      }
           ;

field  : colName type notNullOrEmpty
        {
          $$.fielditem.type=Field::column;
          $$.fielditem.Nullable=$3.Nullable;
          $$.fielditem.thetype=$2.colType;
          $$.fielditem.colName=$1.iden;
        }
       | PRIMARY KEY '(' columnList ')'
        {
          $$.fielditem.type=Field::primarykey;
          $$.fielditem.columns.swap($4.columnlist);
        }
       | FOREIGN KEY '(' colName ')' REFERENCES tbName '(' colName ')'
        {
          $$.fielditem.type=Field::foreignkey;
          $$.fielditem.colName=$4.iden;
          $$.fielditem.reftable=$7.iden;
          $$.fielditem.refcolumn=$9.iden;
        }
       ;

notNullOrEmpty : NOT NULL_
                  {
                    $$.Nullable=false;
                  }
               |
                  {
                    $$.Nullable=true;
                  }
               ;

type  : INT valueIntOrEmpty
        {
          $$.colType.typeId=Type::_INT;
          $$.colType.len=$2.intValue;
        }
      | VARCHAR valueIntOrEmpty
        {
          $$.colType.typeId=Type::_CHAR;
          $$.colType.len=$2.intValue;
        }
      | DATE
        {
          $$.colType.typeId=Type::_DATE;
        }
      | FLOAT
        {
          $$.colType.typeId=Type::_FLOAT;
        }
      ;

valueIntOrEmpty : VALUE_INT
                  {
                    $$.intValue=$1.intValue;
                  }
                |
                  {
                    $$.intValue=0;
                  }
                ;

valueLists  : '(' valueList ')'
              {
                $$.values.clear();
                $$.values.push_back($2.valuelist);
              }
            | valueLists ',' '(' valueList ')'
              {
                $$.values.swap($1.values);
                $$.values.push_back($4.valuelist);
              }
            ;

valueList  : value
            {
              $$.valuelist.clear();
              $$.valuelist.push_back($1.value);
            }
           | valueList ',' value
            {
              $$.valuelist.swap($1.valuelist);
              $$.valuelist.push_back($3.value);
            }
           ;

value  : VALUE_INT
        {
          $$.value.type=Value::_INT;
          $$.value.intValue=$1.intValue;
        }
       | VALUE_STRING
        {
          $$.value.type=Value::_STRING;
          $$.value.stringValue=$1.stringValue;
        }
       | NULL_
        {
          $$.value.type=Value::_NULL;
        }
       ;

whereClause  : whereClauseItem
              {
                $$.wheres.clear();
                $$.wheres.push_back($1.whereitem);
              }
             | whereClauseItem AND whereClause
              {
                $$.wheres.swap($3.wheres);
                $$.wheres.push_back($1.whereitem);
              }
             ;

whereClauseItem: col op expr
                {
                  $$.whereitem.type=WhereItem::OPERATION;
                  $$.whereitem.left=$1.column;
                  $$.whereitem.Operator=$2.Operator;
                  $$.whereitem.expr=$3.expr;
                }
              | col IS NULL_
                {
                  $$.whereitem.type=WhereItem::ISNULL;
                  $$.whereitem.left=$1.column;
                }
              | col IS NOT NULL_
                {
                  $$.whereitem.type=WhereItem::ISNOTNULL;
                  $$.whereitem.left=$1.column;
                }
              ;


col  : colName
      {
        $$.column.hastable=false;
        $$.column.column=$1.iden;
      }
     | tbName '.' colName
      {
        $$.column.hastable=true;
        $$.column.table=$1.iden;
        $$.column.column=$3.iden;
      }
     ;

op  : '='
      {
        $$.Operator=WhereItem::_EQUAL;
      }
    | NOT_EQUAL
      {
        $$.Operator=WhereItem::_NOT_EQUAL;
      }
    | LESS_OR_EQUAL
      {
        $$.Operator=WhereItem::_LESS_OR_EQUAL;
      }
    | MORE_OR_EQUAL
      {
        $$.Operator=WhereItem::_MORE_OR_EQUAL;
      }
    | '<'
      {
        $$.Operator=WhereItem::_LESS;
      }
    | '>'
      {
        $$.Operator=WhereItem::_MORE;
      }
    ;

expr  : value
        {
          $$.expr.type=Expr::VALUE;
          $$.expr.value=$1.value;
        }
      | col
        {
          $$.expr.type=Expr::COL;
          $$.expr.column=$1.column;
        }
      ;

setClause  : colName '=' value
            {
              $$.set.column=$1.iden;
              $$.set.value=$3.value;
              $$.sets.clear();
              $$.sets.push_back($$.set);
            }
           | setClause ',' colName '=' value
            {
              $$.set.column=$3.iden;
              $$.set.value=$5.value;
              $$.sets.swap($1.sets);
              $$.sets.push_back($$.set);
            }
           ;

selector  : '*'
            {
              $$.selector.type=Selector::star;
            }
          | cols
            {
              $$.selector.type=Selector::cols;
              $$.selector.columns=$1.columns;
            }
          ;

cols : col
      {
        $$.columns.clear();
        $$.columns.push_back($1.column);
      }
     | cols ',' col
      {
        $$.columns.swap($1.columns);
        $$.columns.push_back($1.column);
      }
     ;



tableList  : tbName
            {
              $$.tables.clear();
              $$.tables.push_back($1.iden);
            }
           | tableList ',' tbName
            {
              $$.tables.swap($1.tables);
              $$.tables.push_back($3.iden);
            }
           ;

columnList  : colName
              {
                $$.columnlist.clear();
                $$.columnlist.push_back($1.iden);
              }
            | columnList ',' colName
              {
                $$.columnlist.swap($1.columnlist);
                $$.columnlist.push_back($3.iden);
              }
            ;

dbName  : IDENTIFIER
        {
          $$.iden=$1.iden;
        }
        ;

tbName  : IDENTIFIER
        {
          $$.iden=$1.iden;
        }
        ;

colName : IDENTIFIER
        {
          $$.iden=$1.iden;
        }
        ;

%%

void yyerror(const char *s)
{
  cerr<<s<<endl;
}
