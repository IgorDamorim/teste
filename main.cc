#include <iostream>
#include <cstring>
#include <fstream>
#include <iterator>
#include <string>
#include "analisador/lexico.hh"
#include "analisador/sintaxico.hh"
#include "analisador/semantico.hh"

int main(){
  Lexico lexico;
  std::cout << lexico.getCode() << std::endl;

}
