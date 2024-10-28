#ifndef INICIALIZACAO
#define INICIALIZACAO
#include "gerador.hh"

class Inicializacao: public Gerador{
  std::string str;
public:
  Inicializacao(std::string str);
  std::string getCode();
};

#endif
