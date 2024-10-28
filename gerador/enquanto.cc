#include "enquanto.hh"

Enquanto::Enquanto(std::string str){
  std::string tmp = str; 
  int start, end;

  for(unsigned i = 0; i < tmp.length(); i++){
    if(tmp[i] == '('){
      start = i + 1;
    }
    if(tmp[i] == ')'){
      end = i;
      break; 
    }
  }

  tmp.erase(end, tmp.length());
  tmp.erase(0, start);

  this->str = "while (" + tmp + ") {\n";

  tmp = str;

  for(unsigned i = 0; i < tmp.length(); i++){
    if(tmp[i] == '{'){
      start = i + 1;
    }
    if(tmp[i] == '}'){
      end = i;
      break; 
    }
  }

  tmp.erase(end, tmp.length());
  tmp.erase(0, start);

  Analisador analisador(tmp);
  tmp = analisador.getCode();
  
  this->str = this->str + tmp + "\n}";
  
}

std::string Enquanto::getCode(){
  return this->str;
}
