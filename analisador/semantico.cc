#include "semantico.hh"

void Semantico::check(std::string str){
  if (std::regex_search(str, m, std::regex ("inteiro\\s+[A-Za-z]+\\s+=\\s+[0-9]+\\;|inteiro\\s+[A-Za-z]+\\;"))){

    gerador = new Inteiro(str);

    str.erase(0, 7);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str)){
      std::cout << "Variável já foi declarada" << std::endl;
    } else {
      inteiro.push_back(str);
      this->str = this->str + gerador->getCode() + "\n";
    }
       
  } else if (std::regex_search(str, m, std::regex("flutuante\\s+[A-Za-z]\\s+=\\s+[0-9]*\\.[0-9]+;|flutuante\\s+[A-Za-z];|flutuante\\s+[A-Za-z]\\s+=\\s+[0-9]+;"))){

    gerador = new Flutuante(str);

    str.erase(0, 9);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str)){
      std::cout << "Variável já foi declarada" << std::endl;
    } else {
      flutuante.push_back(str);
      this->str = this->str + gerador->getCode() + "\n";
    }

  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}"))){

    gerador = new Sesenao(str);
    this->str = this->str + gerador->getCode() + "\n";

  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){

    gerador = new Sesenao(str);
    this->str = this->str + gerador->getCode() + "\n";

  } else if (std::regex_search(str, m, std::regex("enquanto\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){

    gerador = new Enquanto(str);
    this->str = this->str + gerador->getCode() + "\n";

  } else if (std::regex_search(str, m, std::regex("digitar\\s+\\([A-Za-z0-9]+\\)\\;"))){

    gerador = new Digitar(str);
    this->str = this->str + gerador->getCode() + "\n";

  } else if (std::regex_search(str, m, std::regex("imprimir\\s+\\([^)]*\\)\\;"))){

    gerador = new Imprimir(str);
    this->str = this->str + gerador->getCode() + "\n";
      
  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[A-Za-z0-9]+;"))){

    gerador = new Inicializacao(str);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str)){
      this->str = this->str + gerador->getCode() + "\n";
    } else { 
      std::cout << "A variável não foi declarada" << std::endl;
    }

  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+[0-9]*\\.[0-9]+;"))){

    gerador = new Inicializacao(str);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    if(count(flutuante.begin(), flutuante.end(), str)){
      this->str = this->str + gerador->getCode() + "\n";
    } else if (count(inteiro.begin(), inteiro.end(), str)){
      std::cout << "A variável é um inteiro, não pode receber número decimal" << std::endl;
    } else { 
      std::cout << "A variável não foi declarada" << std::endl;
    }
    
  } else if (str == ""){
    //
  } else {
    std::cout << "\nErro" << std::endl;
  }

}

Semantico::Semantico(){
  std::ifstream file("test.txt");
  
  std::string line;

  while(getline(file, line)){
    check(line);
  }
  
}

Semantico::Semantico(std::string str){
  check(str);
}

std::string Semantico::getCode(){
  return this->str;
}
