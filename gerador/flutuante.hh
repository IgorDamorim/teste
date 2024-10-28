#ifndef FLUTUANTE
#define FLUTUANTE
#include "gerador.hh"

class Flutuante: public Gerador{
  std::string str;
public:
  Flutuante(std::string str);
  std::string getCode() override;
};

#endif
