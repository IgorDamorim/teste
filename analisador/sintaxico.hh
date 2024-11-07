#ifndef SINTAXICO
#define SINTAXICO
#include "lexico.hh"
#include "semantico.hh"
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

class Semantico;

class Sintaxico{
  std::smatch m;
  bool b = true;
public:
  Semantico* semantico = NULL; 
  Sintaxico();
  Sintaxico(std::string str);
  std::string getCode();
  void check(std::string str);
};

#endif
