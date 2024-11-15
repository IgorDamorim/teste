#include "semantico.hh"

void Semantico::check(std::string str){

  std::string line;
  
  std::ifstream fileInteiro("tabeladeSimbolosInteiro.txt");
  
  while(getline(fileInteiro, line)){
    line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); 
    if(!count(inteiro.begin(), inteiro.end(), line)){
      inteiro.push_back(line);
    }
  }

  std::ifstream fileFlutuante("tabeladeSimbolosFlutuante.txt");
  
  while(getline(fileFlutuante, line)){
    line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); 
    if(!count(flutuante.begin(), flutuante.end(), line)){
      flutuante.push_back(line);
    }
  }

  std::ifstream fileBanana("tabeladeSimbolosBanana.txt");
  
  while(getline(fileBanana, line)){
    line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); 
    if(!count(banana.begin(), banana.end(), line)){
      banana.push_back(line);
    }
  }
  
  if (std::regex_search(str, m, std::regex("^para\\s+\\(inteiro\\s+[A-Za-z]+\\s+=\\s+[0-9]+;\\s+[A-Za-z]+\\s+<\\s+[0-9]+;\\s+[A-Za-z]+\\+\\+\\)\\s+\\{[^}]*\\}$"))){

    gerador = new Para(str);

    std::string tmp0 = str;

    while(std::regex_search(str, m, std::regex("inteiro\\s+[A-Za-z]+\\s+=\\s+[0-9]+;"))){
      tmp0 = tmp0 + m.str(0) + "\n";
      str = m.suffix().str();
    }

    tmp0.erase(0, 14);
    
    for(int i = 0; i < tmp0.length(); i++){
      if(tmp0[i] == '='){
	tmp0.erase(i, tmp0.length());
	break;
      }
    }
    tmp0.erase(remove_if(tmp0.begin(), tmp0.end(), isspace), tmp0.end()); 

    std::string tmp1;
    
    while(std::regex_search(str, m, std::regex("[A-Za-z]+\\s+<\\s+[0-9]+;"))){
	tmp1 = tmp1 + m.str(0) + "\n";
	str = m.suffix().str();
    }

    for(int i = 0; i < tmp1.length(); i++){
      if(tmp1[i] == '<'){
	tmp1.erase(i, tmp1.length());
	break;
      }
    }
    tmp1.erase(remove_if(tmp1.begin(), tmp1.end(), isspace), tmp1.end());

    std::string tmp2;
    
    while(std::regex_search(str, m, std::regex("[A-Za-z]+\\+\\+"))){
	tmp2 = tmp2 + m.str(0) + "\n";
	str = m.suffix().str();
    }

    for(int i = 0; i < tmp2.length(); i++){
      if(tmp2[i] == '+'){
	tmp2.erase(i, tmp2.length());
	break;
      }
    }
    tmp2.erase(remove_if(tmp2.begin(), tmp2.end(), isspace), tmp2.end());
    
    if(tmp0 == tmp1){
      if(tmp1 == tmp2){
	this->str = this->str + gerador->getCode() + "\n";
      } else {
	std::cout << "Erro no para" << std::endl;
      }
    } else {
      std::cout << "Erro no para" << std::endl;
    }
  
  } else if (std::regex_search(str, m, std::regex ("inteiro\\s+[A-Za-z]+\\s+=\\s+[0-9]+\\;|inteiro\\s+[A-Za-z]+\\;"))){

    gerador = new Inteiro(str);

    str.erase(0, 7);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
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

    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
      std::cout << "Variável já foi declarada" << std::endl;
    } else {
      flutuante.push_back(str);
      this->str = this->str + gerador->getCode() + "\n";
    }

  } else if (std::regex_search(str, m, std::regex("banana\\s+[A-Za-z]+;|banana\\s+[A-Za-z]+\\s+=\\s+\"[^\"]*\";"))){

    gerador = new Banana(str);

    str.erase(0, 6);
    for(int i = 0; i < str.length(); i++){
      if(str[i] == ';' || str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
      std::cout << "Variável já foi declarada" << std::endl;
    } else {
      banana.push_back(str);
      this->str = this->str + gerador->getCode() + "\n";
    }

  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}"))){

    gerador = new Sesenao(str);
    
    for(int i = 0; i < str.length(); i++){
      if(str[i] == '('){
	str.erase(0, i+1);
      } else if (str[i] == ')'){
	str.erase(i);
      }
    }

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<'){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
      this->str = this->str + gerador->getCode() + "\n";
    } else {
      std::cout << "A variável de se não foi declarada" << std::endl;
    }

    
  } else if (std::regex_search(str, m, std::regex("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){

    gerador = new Sesenao(str);
        
    for(int i = 0; i < str.length(); i++){
      if(str[i] == '('){
	str.erase(0, i+1);
      } else if (str[i] == ')'){
	str.erase(i);
      }
    }

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<'){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
      this->str = this->str + gerador->getCode() + "\n";
    } else {
      std::cout << "A variável de se não foi declarada" << std::endl;
    }   
    
  } else if (std::regex_search(str, m, std::regex("enquanto\\s+\\([^)]*\\)\\s+\\{[^}]*\\}"))){

    gerador = new Enquanto(str);

    int start, end;
    
    for(int i = 0; i < str.length(); i++){
      if(str[i] == '('){
	start = i + 1;
	//str.erase(0, i + 1);
      } else if(str[i] == ')'){
	end = i;
	//str.erase(i, str.length());
	break;
      }
    }

    str.erase(end, str.length());
    str.erase(0, start);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<'){
	str.erase(i, str.length());
      }
    }
    
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    
    if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
      this->str = this->str + gerador->getCode() + "\n";
    } else {
      std::cout << "Variável de enquanto não foi declarada" << str << std::endl;
    }

    
  } else if (std::regex_search(str, m, std::regex("digitar\\s+\\([A-Za-z0-9]+\\)\\;"))){

    gerador = new Digitar(str);

      int start, end; 
      for(int i = 0; i < str.length(); i++){
	if(str[i] == '('){
	  start = i+1;
	}
	if (str[i] == ')'){
	  end = i;
	}
      }
      str.erase(end, str.length());
      str.erase(0, start);
      str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
      if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
	this->str = this->str + gerador->getCode() + "\n";
      } else {
	std::cout << "Variável de digitar não foi declarada" << std::endl;
      }   
      
  } else if (std::regex_search(str, m, std::regex("imprimir\\s+\\([^)]*\\)\\;"))){

    gerador = new Imprimir(str);

    if(std::regex_search(str, m, std::regex("imprimir\\s+\\(\"[^\"]*\"\\)"))){
      this->str = this->str + gerador->getCode() + "\n";
    } else {
      int start, end; 
      for(int i = 0; i < str.length(); i++){
	if(str[i] == '('){
	  start = i+1;
	}
	if (str[i] == ')'){
	  end = i;
	}
      }
      str.erase(end, str.length());
      str.erase(0, start);
      str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
      if(count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str) || count(banana.begin(), banana.end(), str)){
	this->str = this->str + gerador->getCode() + "\n";
      } else {
	std::cout << "Variável de imprimir não foi declarada" << std::endl;
      }   
    }
    
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
    } else if (count(banana.begin(), banana.end(), str)){
      std::cout << "A variável é uma banana, deve receber string" << std::endl;
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
    } else if (count(banana.begin(), banana.end(), str)){
      std::cout << "A variável é uma banana, deve receber string" << std::endl;
    } else { 
      std::cout << "A variável não foi declarada" << std::endl;
    }

  } else if (std::regex_search(str, m, std::regex("[A-Za-z]+\\s+=\\s+\"[^\"]*\""))){

    gerador = new Inicializacao(str);

    for(int i = 0; i < str.length(); i++){
      if(str[i] == '='){
	str.erase(i, str.length());
      }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    if(count(banana.begin(), banana.end(), str)){
      this->str = this->str + gerador->getCode() + "\n";
    } else if (count(inteiro.begin(), inteiro.end(), str) || count(flutuante.begin(), flutuante.end(), str)){
      std::cout << "A variável não aceita banana (string)" << std::endl;
    } else { 
      std::cout << "A variável não foi declarada" << std::endl;
    }
    
  } else if (str == ""){
    //
  } else {
    std::cout << "\nErro" << std::endl;
  }

  std::ofstream ofsInteiro ("tabeladeSimbolosInteiro.txt", std::ofstream::out);

  for (int i = 0; i < inteiro.size(); i++){
    ofsInteiro << inteiro[i] << "\n"; 
  }

  std::ofstream ofsFlutuante ("tabeladeSimbolosFlutuante.txt", std::ofstream::out);

  for (int i = 0; i < flutuante.size(); i++){
    ofsFlutuante << flutuante[i] << "\n"; 
  }

  std::ofstream ofsBanana ("tabeladeSimbolosBanana.txt", std::ofstream::out);

  for (int i = 0; i < banana.size(); i++){
    ofsBanana << banana[i] << "\n"; 
  }
  
}

Semantico::Semantico(){
  std::ifstream file("input.txt");
  
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
