#ifndef DEF_YOSHI
#define DEF_YOSHI

#include "Character.h"
#include <string>

class Yoshi : public Character
{
  public :
  Yoshi();
  Yoshi(int crest);
  ~Yoshi();
  virtual std::string WhatAmI() const;
  void Accelerate();

  private:
    int *crest_;
};

#endif
