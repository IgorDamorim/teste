#include "sesenao.hh"

Sesenao::Sesenao(std::string str){
  std::regex re("se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}\\s+senao\\s+\\{[^}]*\\}");

  if(!std::regex_search(str, m, re)){
    re = "se\\s+\\([^)]*\\)\\s+\\{[^}]*\\}";
    b = false;
    std::regex_search(str, m, re);
  }

  for(unsigned i = 0; i < m.size(); ++i)
    tmp += m[i];

  // extrair o conteúdo dos  parenteses
  re = "\\([A-Za-z0-9]+\\s+==\\s+[A-Za-z0-9]+\\)";
  if(!std::regex_search(tmp, m, re)){
    re = "\\([A-Za-z0-9]+\\s+!=\\s+[A-Za-z0-9]+\\)";
    if(!std::regex_search(tmp, m, re)){
      re = "\\([A-Za-z0-9]+\\s+>=\\s+[A-Za-z0-9]+\\)";
      if(!std::regex_search(tmp, m, re)){
	re = "\\([A-Za-z0-9]+\\s+=<\\s+[A-Za-z0-9]+\\)";
	if(!std::regex_search(tmp, m, re)){
	  re = "\\([A-Za-z0-9]+\\s+>\\s+[A-Za-z0-9]+\\)";
	  if(!std::regex_search(tmp, m, re)){
	    re = "\\([A-Za-z0-9]+\\s+<\\s+[A-Za-z0-9]+\\)";
	    std::regex_search(tmp, m, re);
	  }
	}
      }
    }
  }
  for(unsigned i = 0; i < m.size(); ++i)
    x += m[i];
  char c0[] = "()";
  for(unsigned i = 0; i < strlen(c0); ++i)
    x.erase(std::remove(x.begin(), x.end(), c0[i]), x.end());
  //

  // extrair o conteúdo das primeiras chaves (apenas se)
  re = "\\{[^}]*\\}";
  std::regex_search(tmp, m, re);
  for(unsigned i = 0; i < m.size(); ++i)
    y += m[i];
  char c1[] = "{}";
  for(unsigned i = 0; i < strlen(c1); ++i)
    y.erase(std::remove(y.begin(), y.end(), c1[i]), y.end());
  //

  // verificar o conteúdo das primeiras chaves
  Lexico lexico(y);
  y = lexico.getCode();
  //

  tmp = std::string("if") + std::string(" (") + x + std::string(") ") + std::string("{") + std::string("\n") +  y + std::string("\n}");

  
  // extrair o conteúdo das segundas chaves (apenas se-senao)
  if(b){
    for(unsigned i = 0; i < str.length(); ++i){
      if(str[i] == 's')
	if(str[++i] == 'e')
	  if(str[++i] == 'n')
	    if(str[++i] == 'a')
	      if(str[++i] == 'o')
		str.erase(0, i);
    }
    std::regex_search(str, m, re);
    for(unsigned i = 0; i < m.size(); ++i)
      z += m[i];
    for(unsigned i = 0; i < strlen(c1); ++i)
      z.erase(std::remove(z.begin(), z.end(), c1[i]), z.end());

    // verificar o conteúdo das segundas chaves
    Lexico lexico(z);
    z = lexico.getCode();
    //

    tmp = tmp + std::string(" else {\n") + z + std::string("\n}"); 
  }

  
  
}

std::string Sesenao::getCode(){
  return tmp;
}
