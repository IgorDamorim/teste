#include "flutuante.hh"

Flutuante::Flutuante(std::string str){
  this->str = str;

  while(this->str.find("flutuante") != std::string::npos)
    this->str.replace(this->str.find("flutuante"), 9, "float");
}

std::string Flutuante::getCode(){
  return this->str;
}
