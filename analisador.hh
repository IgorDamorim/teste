#ifndef ANALISADOR
#define ANALISADOR
#include "gerador/gerador.hh"
#include "gerador/inteiro.hh"
#include "gerador/flutuante.hh"
#include "gerador/sesenao.hh"
#include "gerador/enquanto.hh"
#include "gerador/digitar.hh"
#include "gerador/imprimir.hh"
#include "gerador/inicializacao.hh"

class Analisador{
  std::smatch m;
public:
  Gerador* gerador = NULL; 
  Analisador(std::string str);
  std::string getCode();
};

#endif
