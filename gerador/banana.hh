#ifndef BANANA
#define BANANA
#include "gerador.hh"

class Banana: public Gerador{
  std::string str;
public:
  Banana(std::string str);
  std::string getCode() override;
};

#endif
