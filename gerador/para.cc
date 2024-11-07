#include "para.hh"

Para::Para(std::string str){
  std::string tmp = str;
  int start, end;

  for(int i = 0; i < tmp.length(); i++){
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
  
  while(tmp.find("para") != std::string::npos)
    tmp.replace(tmp.find("para"), 4, "for");

  while(tmp.find("inteiro") != std::string::npos)
    tmp.replace(tmp.find("inteiro"), 7, "int");

  this->str = "\tfor (" + tmp + ") {\n";

  tmp = str;

  for(int i = 0; i < tmp.length(); i++){
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

std::string Para::getCode(){
  return this->str;
}
