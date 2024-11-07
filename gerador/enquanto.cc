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

  this->str = "\twhile (" + tmp + ") {\n";

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

  Lexico lexico(tmp);
  tmp = lexico.getCode();
  
  this->str = this->str + "\t" + tmp + "\t}";
  
}

std::string Enquanto::getCode(){
  return this->str;
}
