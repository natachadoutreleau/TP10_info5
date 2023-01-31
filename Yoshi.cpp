#include "Yoshi.h"
#include "Character.h"
#include <string>
#include<iostream>


/**
 * Constructer
 * @param none
 */
Yoshi::Yoshi(): Character()
{
  crest_=new int(0);
}

/**
 * Constructer by default, if the number of crest is not given the given number of crest is 0
 * @param none
 */
Yoshi::Yoshi(int crest): Character()
{
  crest_=new int(crest);
}


/**
 * Override the Character::WhatamI function
 * @param none
 */
std::string Yoshi::WhatAmI() const{
  if(*crest_==0){
    return "Bald Yoshi";
  }
  std::string s= std::to_string(*crest_);
  s+=" crested Yoshi";
  return s;
}

/**
 * Override the Character::Accelerate function
 * @param none
 */
void Yoshi::Accelerate(){
  if (speed_<max_speed_){
    speed_=speed_+2;
  }
  else {
    std::cout<< "You can't go faster!"<< std::endl;
  }
}
