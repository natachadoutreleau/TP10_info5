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
