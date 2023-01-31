#include "Character.h"

#include<iostream>

/**
 * Constructs a Character object, initializing parameter values to 0
 * @param none
 */
Character::Character(){
  speed_=0;
  max_speed_=10;
}

/**
 * Increment the value speed if the speed is lower than the max_speed_
 * @param none
 */
void Character::Accelerate(){
  if (speed_<max_speed_){
    speed_++;
  }
  else {
    std::cout<< "You can't go faster!"<< std::endl;
  }
}

/**
 * Decrement the value speed if the speed is higher than 0
 * @param none
 */
void Character::Break(){
  if (speed_>0){
    speed_--;
  }
  else {
    std::cout<< "Your car is stopped!"<< std::endl;
  }
}

/**
 * Inlined getter of speed
 * @param none
 */
inline float Character::speed(){
  return speed_;
}
