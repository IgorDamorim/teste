#ifndef SESENAO
#define SESENAO
#include "gerador.hh"
#include "../analisador.hh"
#include <regex>
#include <iostream>

class Sesenao: public Gerador{
  std::string tmp, x, y, z;
  std::smatch m;
  bool b = true;
public:
  Sesenao(std::string str);
  std::string getCode() override;
};

#endif
