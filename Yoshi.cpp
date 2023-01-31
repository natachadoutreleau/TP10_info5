#include "Yoshi.h"
#include "Character.h"
#include <string>
#include<iostream>


/**
 * Override the Character::WhatamI function
 * @param none
 */
std::string Yoshi::WhatAmI() const{
  return "Yoshi";
}

void Yoshi::Accelerate(){
  if (speed_<max_speed_){
    speed_=speed_+2;
  }
  else {
    std::cout<< "You can't go faster!"<< std::endl;
  }
}
