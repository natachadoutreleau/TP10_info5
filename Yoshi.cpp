#include "Yoshi.h"
#include "Character.h"
#include <string>
#include<iostream>


/**
 * Constructs a Yoshi object, initializing parameter crest_ to 0 and all the other paramter like Character
 * @param none
 */
Yoshi::Yoshi(): Character()
{
  crest_=new int(0);
}

/**
 * Constructs a Yoshi object, initializing parameter crest_ to crest and all the other paramter like Character
 * @param int crest: number of crest
 */
Yoshi::Yoshi(int crest): Character()
{
  crest_=new int(crest);
}

/**
 * Destructor of Yoshi; override the Character destructor
 * @param none
 */
Yoshi::~Yoshi(){
  delete crest_;
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
