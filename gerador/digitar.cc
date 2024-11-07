#include "digitar.hh"

Digitar::Digitar(std::string str){
  this->str = str;

  char c0[] = "()";
  for(unsigned i = 0; i < strlen(c0); ++i)
    this->str.erase(std::remove(this->str.begin(), this->str.end(), c0[i]), this->str.end());

  while(this->str.find("digitar") != std::string::npos)
    this->str.replace(this->str.find("digitar"), 7, "std::cin >>");
}

std::string Digitar::getCode(){
  return "\t" + this->str;
}
