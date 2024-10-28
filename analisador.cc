#include "analisador.hh"

Analisador::Analisador(std::string str){
  if (std::regex_search(str, m, std::regex ("inteiro\\s+[A-Za-z]+\\s+=\\s+[0-9]+\\;|inteiro\\s+[A-Za-z]+\\;"))){
    gerador = new Inteiro(str);
  } else if (std::regex_search(str, m, std::regex("flutuante\\s+[A-Za-z]\\s+=\\s+[0-9]*\\.[0-9]+;|flutuante\\s+[A-Za-z];|flutuante\\s+[A-Za-z]\\s+=\\s+[0-9]+;"))){
    gerador = new Flutuante(str);
  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}"))){
    gerador = new Sesenao(str);
  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){
    gerador = new Sesenao(str);
  } else if (std::regex_search(str, m, std::regex("enquanto\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){
    gerador = new Enquanto(str); 
  } else if (std::regex_search(str, m, std::regex("digitar\\s+\\([A-Za-z0-9]+\\)\\;"))){
    gerador = new Digitar(str);
  } else if (std::regex_search(str, m, std::regex("imprimir\\s+\\([^)]*\\)\\;"))){
    gerador = new Imprimir(str);
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[A-Za-z0-9]+;"))){
    gerador = new Inicializacao(str);
  } else {
    std::cout << "\nErro léxico ou de sintáxe" << std::endl;
  } 
}

std::string Analisador::getCode(){
  return gerador->getCode();
}
