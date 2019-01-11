//
//  handler.h
//  
//
//  Created by 赖金霖 on 2018/12/27.
//

#ifndef handler_h
#define handler_h

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

struct Type{
  static const int _FLOAT=0;
  static const int _DATE=1;
  static const int _INT=2;
  static const int _CHAR=3;
  int typeId;
  int len;
};

class Value{
public:
  static const int _INT=0;
  static const int _STRING=1;
  static const int _NULL=2;
  static const int _FLOAT=3;
  static const int _DATE=4;
  int type;
  int intValue;
  std::string stringValue;
  float floatValue;
  int dateValue;
  char* toString(Type);
  int toInt(Type);
};

struct Set{
  std::string column;
  Value value;
  int left,right;
  Type type;
};

struct Column{
  bool hastable;
  std::string table;
  std::string column;
  int place,left,right;
  Type type;
};

struct Selector{
  static const int star=0;
  static const int cols=1;
  int type;
  std::vector<Column> columns;
};

struct Expr{
  static const int VALUE=0;
  static const int COL=1;
  int type;
  Column column;
  Value value;
};

struct WhereItem{
public:
  static const int OPERATION=0;
  static const int ISNULL=1;
  static const int ISNOTNULL=2;
  
  static const int _EQUAL=0;
  static const int _NOT_EQUAL=1;
  static const int _LESS_OR_EQUAL=2;
  static const int _MORE_OR_EQUAL=3;
  static const int _LESS=4;
  static const int _MORE=5;
  
  int type;
  Column left;
  int Operator;
  Expr expr;
  bool used;
};

class Field{
public:
  static const int column=0;
  static const int primarykey=1;
  static const int foreignkey=2;
  static const int skip=3;
  int type,left,right;
  bool isprimarykey;
  //type=column
  bool Nullable;
  std::string colName;
  Type thetype;
  //type=primarykey
  std::vector<std::string> columns;
  //type=foreignkey
  std::string reftable;
  std::string refcolumn;
};

class Handler{
public:
  virtual void accept();
};

class ShowDatabases:public Handler{
public:
  virtual void accept();
};

class CreateDatabase:public Handler{
  std::string dbname;
public:
  virtual void accept();
  CreateDatabase(std::string dbname);
};

class DropDatabase:public Handler{
  std::string dbname;
public:
  virtual void accept();
  DropDatabase(std::string dbname);
};

class UseDatabase:public Handler{
  std::string dbname;
public:
  virtual void accept();
  UseDatabase(std::string dbname);
};

class ShowTables:public Handler{
public:
  virtual void accept();
};

class CreateTable:public Handler{
  std::vector<Field> fields;
  std::string tbname;
public:
  virtual void accept();
  CreateTable(std::string tbname, std::vector<Field> fields);
};

class DropTable:public Handler{
  std::string tbname;
public:
  virtual void accept();
  DropTable(std::string tbname);
};

class DescTable:public Handler{
  std::string tbname;
public:
  virtual void accept();
  DescTable(std::string tbname);
};

class InsertValue:public Handler{
  std::string tbname;
  std::vector<std::vector<Value> > values;
public:
  virtual void accept();
  InsertValue(std::string tbname, std::vector<std::vector<Value> > values);
};

class DeleteValues:public Handler{
  std::string tbname;
  std::vector<WhereItem> wheres;
public:
  virtual void accept();
  DeleteValues(std::string tbname, std::vector<WhereItem> wheres);
};

class UpdateValues:public Handler{
  std::string tbname;
  std::vector<WhereItem> wheres;
  std::vector<Set> sets;
public:
  virtual void accept();
  UpdateValues(std::string tbname, std::vector<Set> sets, std::vector<WhereItem> wheres);
};

class SelectValues:public Handler{
  Selector selector;
  std::vector<std::string> tables;
  std::vector<WhereItem> wheres;
public:
  virtual void accept();
  SelectValues(Selector selector, std::vector<std::string> tables, std::vector<WhereItem> wheres);
};

class CreateIndex:public Handler{
  std::string tbname;
  std::string colname;
public:
  virtual void accept();
  CreateIndex(std::string tbname, std::string colname);
};

class DropIndex:public Handler{
  std::string tbname;
  std::string colname;
public:
  virtual void accept();
  DropIndex(std::string tbname, std::string colname);
};

class Exiter:public Handler{
public:
  virtual void accept();
  Exiter();
};

#endif /* handler_h */
