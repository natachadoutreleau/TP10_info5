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
void Accelerate(){
  if (speed_<max_speed_){
    speed_++;
  }
}
