#include <iostream>
#include <cstring>
#include <fstream>
#include "analisador.hh"

int main(){
  std::ifstream file("test.txt");
  std::string line;

  while(getline(file, line)){
    Analisador analisador(line);
    std::cout << analisador.getCode() << std::endl;
  }
}
