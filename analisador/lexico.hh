#ifndef LEXICO
#define LEXICO
#include "sintaxico.hh"
#include "../gerador/gerador.hh"
#include "../gerador/inteiro.hh"
#include "../gerador/flutuante.hh"
#include "../gerador/sesenao.hh"
#include "../gerador/enquanto.hh"
#include "../gerador/digitar.hh"
#include "../gerador/imprimir.hh"
#include "../gerador/inicializacao.hh"
#include "../gerador/banana.hh"
#include "../gerador/para.hh"
#include <cstring>
#include <fstream>
#include <string>

class Sintaxico;

class Lexico{
  std::smatch m;
  bool b = true;
public: 
  Sintaxico* sintaxico = NULL;
  Lexico();
  Lexico(std::string str);
  std::string getCode();
  void check(std::string str);
};

#endif
