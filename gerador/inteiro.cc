#include "inteiro.hh"

Inteiro::Inteiro(std::string str){
  this->str = str;

  while(this->str.find("inteiro") != std::string::npos)
    this->str.replace(this->str.find("inteiro"), 7, "int");
}

std::string Inteiro::getCode(){
  return "\t" + this->str;
}
