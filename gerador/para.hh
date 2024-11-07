#ifndef PARA
#define PARA
#include "gerador.hh"
#include "../analisador/lexico.hh"

class Para: public Gerador{
  std::string str;
public:
  Para(std::string str);
  std::string getCode() override;
};

#endif
