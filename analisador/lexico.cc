#include "lexico.hh"

void Lexico::check(std::string str){ 
  if (std::regex_search(str, m, std::regex ("inteiro\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("flutuante\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("banana\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("se\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("enquanto\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("para\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("digitar\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("imprimir\\s+"))){
    //
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[A-Za-z0-9]+;"))){
    //
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]*\\.[0-9]+;"))){
    //
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+\"[^\"]*\""))){
    //
  } else if (str == ""){
    //
  } else {
    this->b = false;
    std::cout << "\nErro de léxico" << std::endl;
  } 
}

Lexico::Lexico(){
  std::ifstream file("input.txt");
  std::string line;

  while(getline(file, line)){
    check(line);
  }

  if(this->b){
    sintaxico = new Sintaxico();
  }
}

Lexico::Lexico(std::string str){
  check(str);

  if(this->b){
    sintaxico = new Sintaxico(str);
  }
}


std::string Lexico::getCode(){
  return sintaxico->getCode();
}
