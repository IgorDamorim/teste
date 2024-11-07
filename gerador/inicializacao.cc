#include "inicializacao.hh"

Inicializacao::Inicializacao(std::string str){
  this->str = str;
}

std::string Inicializacao::getCode(){
  return "\t" + this->str;
}
