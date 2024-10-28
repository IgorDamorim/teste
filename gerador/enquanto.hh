#ifndef ENQUANTO
#define ENQUANTO
#include "gerador.hh"
#include "../analisador.hh"
//#include <regex>
//#include <iostream>

class Enquanto: public Gerador{
  std::string str, x, y;
  std::smatch m;
public:
  Enquanto(std::string str);
  std::string getCode() override;
};

#endif
