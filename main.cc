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

  std::string out = "#include <iostream>\n\nint main(){\n" + lexico.getCode() + "}"; 
  
  std::ofstream ofs ("output.cc", std::ofstream::out);
  ofs << out;

  remove("tabeladeSimbolosInteiro.txt");
  remove("tabeladeSimbolosFlutuante.txt");
  remove("tabeladeSimbolosBanana.txt");
}
