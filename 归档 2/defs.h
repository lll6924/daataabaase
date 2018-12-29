#ifndef DEFS
#define DEFS

#include <string>
#include <vector>
#include "handler.h"
#define YYSTYPE semvalue

class semvalue{
public:
  static const int identifier=0;
  static const int intConstant=1;
  static const int stringConstant=2;
  static const int floatConstant=3;
  static const int dateConstant=4;
  Handler* handler;
  int code;
  int type;
  std::string iden;
  int intValue;
  std::string stringValue;
  float floatValue;
  int dateValue;
  std::vector<Field> fields;
  Field fielditem;
  Type colType;
  bool Nullable;
  std::vector<std::vector<Value> > values;
  std::vector<Value> valuelist;
  Value value;
  WhereItem whereitem;
  std::vector<WhereItem> wheres;
  Column column;
  Expr expr;
  int Operator;
  std::vector<Set> sets;
  Set set;
  std::vector<Column> columns;
  std::vector<std::string> tables;
  std::vector<std::string> columnlist;
  Selector selector;
};

void identifier(const char* c,semvalue& ss);

void intConstant(const char* c,semvalue& ss);

void stringConstant(const char* c,semvalue& ss);

#endif
