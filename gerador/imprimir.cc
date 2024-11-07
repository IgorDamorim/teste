#include "imprimir.hh"

Imprimir::Imprimir(std::string str){
  this->str = str;
  
  char c0[] = "()";
  for(unsigned i = 0; i < strlen(c0); ++i)
    this->str.erase(std::remove(this->str.begin(), this->str.end(), c0[i]), this->str.end());

  while(this->str.find("imprimir") != std::string::npos)
    this->str.replace(this->str.find("imprimir"), 8, "std::cout <<");
}

std::string Imprimir::getCode(){
  return "\t" + this->str;
}
