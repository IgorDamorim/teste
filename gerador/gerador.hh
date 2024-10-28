#ifndef GERADOR
#define GERADOR
#include <iostream>
#include <regex>
#include <cstring>

class Gerador{
public:
  virtual std::string getCode() = 0;
};

#endif
