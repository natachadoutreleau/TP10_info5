#ifndef DEF_YOSHI
#define DEF_YOSHI

#include "Character.h"
#include <string>

class Yoshi : public Character
{
  public :
  virtual std::string WhatAmI() const;

};

#endif
