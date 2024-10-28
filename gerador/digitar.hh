#ifndef DIGITAR
#define DIGITAR
#include "gerador.hh"

class Digitar: public Gerador{
  std::string str;
public:
  Digitar(std::string str);
  std::string getCode() override;
};

#endif
