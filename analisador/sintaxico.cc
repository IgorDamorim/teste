#include "sintaxico.hh"

void Sintaxico::check(std::string str){
  if (std::regex_search(str, m, std::regex ("inteiro\\s+[A-Za-z]+\\s+=\\s+[0-9]+\\;|inteiro\\s+[A-Za-z]+\\;"))){
    //
  } else if (std::regex_search(str, m, std::regex("flutuante\\s+[A-Za-z]\\s+=\\s+[0-9]*\\.[0-9]+;|flutuante\\s+[A-Za-z];|flutuante\\s+[A-Za-z]\\s+=\\s+[0-9]+;"))){
    //
  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}"))){
    //
  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){
    //
  } else if (std::regex_search(str, m, std::regex("enquanto\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){
    // 
  } else if (std::regex_search(str, m, std::regex("digitar\\s+\\([A-Za-z0-9]+\\)\\;"))){
    //
  } else if (std::regex_search(str, m, std::regex("imprimir\\s+\\([^)]*\\)\\;"))){
    //
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[A-Za-z0-9]+;"))){
    //
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]*\\.[0-9]+;"))){
    //
  } else if (str == ""){
    //
  } else {
    this->b = false;
    std::cout << "\nErro de sintáxe" << std::endl;
  }
}

Sintaxico::Sintaxico(){
  std::ifstream file("test.txt");
  
  std::string line;
  
  while(getline(file, line)){
    check(line);
  }

  if(this->b){
    semantico = new Semantico();
  }
}

Sintaxico::Sintaxico(std::string str){
  check(str);

  if(this->b){
    semantico = new Semantico(str);
  }
}

std::string Sintaxico::getCode(){
  return semantico->getCode();
}
