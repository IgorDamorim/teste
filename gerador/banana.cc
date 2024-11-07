#include "banana.hh"

Banana::Banana(std::string str){
  this->str = str;

  while(this->str.find("banana") != std::string::npos)
    this->str.replace(this->str.find("banana"), 6, "std::string");
}

std::string Banana::getCode(){
  return "\t" + this->str; 
}
