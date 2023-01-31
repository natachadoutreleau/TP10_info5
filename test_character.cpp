#include<iostream>
#include "test_character.h"
#include "Character.h"



int test_ctor(){
    Character c;
    if (c.speed()==0){
      std::cout<< "The speed is: "<< c.speed()<<std::endl;
      return 0;
    }
    return 1;
}

int test_accelerate(){
  Character c;
  std::cout<< "The speed is: "<< c.speed()<<std::endl;
  c.Accelerate();
  if (c.speed()==1){
    std::cout<< "The new speed is: "<< c.speed()<<std::endl;
    return 0;
  }
  return 1;
}
