#include<iostream>
#include <vector>
#include "test_character.h"
#include "Character.h"
#include "Mario.h"
#include "Yoshi.h"


/**
 * Test the constructor an if the speed is set to 0
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_ctor(){
    Mario c;
    if (c.speed()==0){
      std::cout<< "The speed is: "<< c.speed()<<std::endl;
      return 0;
    }
    return 1;
}

/**
 * Test that the speed is incremented
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_accelerate(){
  Mario c;
  std::cout<< "The speed is: "<< c.speed()<<std::endl;
  c.Accelerate();
  if (c.speed()==1){
    std::cout<< "The new speed is: "<< c.speed()<<std::endl;
    return 0;
  }
  return 1;
}

/**
 * Test that the speed is not incremented if the speed is already at the max_speed_
 * @param none
 * @return 0 if the test is a success; 1 if not
 */

int test_accelerate_more_than_max_speed(){
  Mario c;
  int i =0;
  while(i<10){
    c.Accelerate();
    i++;
  }
  std::cout<< "The speed is: "<< c.speed()<<std::endl;
  c.Accelerate();
  if (c.speed()==10){
    std::cout<< "The speed is still: "<< c.speed()<<std::endl;
    return 0;
  }
  return 1;
}

/**
 * Test that the speed is not decremented if the speed is already at 0
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_break_lower_than_zero(){
  Mario c;
  std::cout<< "The speed is: "<< c.speed()<<std::endl;
  c.Break();
  if (c.speed()==0){
    std::cout<< "You can't go slower than staying still: "<< c.speed()<<std::endl;
    return 0;
  }
  return 1;
}

/**
 * Test that the speed is decremented
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_break(){
  Mario c;
  int i =0;
  while(i<10){
    c.Accelerate();
    i++;
  }
  std::cout<< "The speed is: "<< c.speed()<<std::endl;
  c.Break();
  if (c.speed()==9){
    std::cout<< "The speed is: "<< c.speed()<<std::endl;
    return 0;
  }
  return 1;
}

/**
 * Test the destructor, valgrind is needed;
 * if the delete line is commented, the memory in use at exit will be 8 byte;
 * if delete is used (destructor) than the memory in use at exit is 0
 *
 * @param none
 */
void test_destructor(){
  Mario *c = new Mario;
  delete c;
}

/**
 * Test if Mario an Yoshi override the WhatAmI function
 *
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_Mario_and_Yoshi(){
  Mario m;
  Yoshi y;
  if (m.WhatAmI()=="Mario"){
    std::cout<<m.WhatAmI()<<std::endl;
    if (y.WhatAmI()=="Yoshi"){
      std::cout<<y.WhatAmI()<<std::endl;
      return 0;
    }
  }
  return 1;
}

/**
 * Test if Yoshi Accelerate faster than mario
 *
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_Mario_and_Yoshi_accelerate(){
  Mario m;
  Yoshi y;
  if(m.speed()==y.speed()){
    m.Accelerate();
    y.Accelerate();
    if(m.speed()< y.speed()){
      std::cout<<m.WhatAmI()<<" : "<<m.speed()<<std::endl;
      std::cout<<y.WhatAmI()<<" : "<<y.speed()<<std::endl;
      return 0;
    }
  }
  return 1;
}


/**
 * Race between two mario's and a yoshi; the first that goes up to speed 10 win.
 *
 * @param none
 */
void Let_the_Race_begin(){
  std::vector<Character*> racer;
  racer.push_back(new Mario);
  racer.push_back(new Yoshi);
  racer.push_back(new Mario);
  int course=1;
  Character* winner;
  while(course==1){
    for(Character* n : racer){
      n->Accelerate();
      if(n->speed()==10){
        course=0;
      }
    }
  }
    for(Character* n : racer){
      std::cout<<n->WhatAmI()<<" :"<<n->speed()<<std::endl;
      if(n->speed()==10){
        winner=n;
      }
      }
    std::cout<<"The winner is "<<winner->WhatAmI()<<std::endl;
    for(Character* n : racer){
      delete n;
      }
}

void Yoshi_constructor_and_destructor(){
  Yoshi y;
  Yoshi y2(5);
  std::cout<<y.WhatAmI()<<std::endl;
  std::cout<<y2.WhatAmI()<<std::endl;
}
