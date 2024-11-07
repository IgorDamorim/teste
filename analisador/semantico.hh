#ifndef SEMANTICO
#define SEMANTICO
#include "lexico.hh"
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

class Semantico{
  std::string str;
  std::smatch m;
  std::vector<std::string> inteiro;
  std::vector<std::string> flutuante;
  std::vector<std::string> banana;
public:
  Gerador* gerador = NULL; 
  Semantico();
  Semantico(std::string str);
  std::string getCode();
  void check(std::string str);
};

#endif
