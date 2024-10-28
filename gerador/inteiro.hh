#ifndef INTEIRO
#define INTEIRO
#include "gerador.hh"

class Inteiro: public Gerador{
  std::string str;
public:
  Inteiro(std::string str);
  std::string getCode() override;
};

#endif
