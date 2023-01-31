#ifndef DEF_MARIO
#define DEF_MARIO

#include "Character.h"
#include <string>

class Mario : public Character
{
  public :
  virtual std::string WhatAmI() const;

};

#endif
