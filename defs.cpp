
#include "defs.h"
#include <vector>
#include <cstdlib>

void identifier(const char* c,semvalue& ss){
  ss.type=semvalue::identifier;
  ss.iden=std::string(c);
}

void intConstant(const char* c,semvalue& ss){
  ss.type=semvalue::intConstant;
  ss.intValue=std::atoi(c);
}

void stringConstant(const char* c,semvalue& ss){
  ss.type=semvalue::stringConstant;
  ss.stringValue=std::string(c);
}
