#ifndef IMPRIMIR
#define IMPRIMIR
#include "gerador.hh"

class Imprimir: public Gerador{
  std::string str;
public:
  Imprimir(std::string str);
  std::string getCode();
};


#endif
