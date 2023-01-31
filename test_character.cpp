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
    if (y.WhatAmI()=="Bald Yoshi"){
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
 * @return 0 if the test is a success; 1 if not
 */
int Let_the_Race_begin(){
  std::vector<Character*> racers;
  racers.push_back(new Mario);
  racers.push_back(new Yoshi(5));
  racers.push_back(new Mario);
  int course=1;
  Character* winner;
  while(course==1){
    for(Character* n : racers){
      n->Accelerate();
      if(n->speed()==10){
        course=0;
      }
    }
  }
    for(Character* n : racers){
      std::cout<<n->WhatAmI()<<" :"<<n->speed()<<std::endl;
      if(n->speed()==10){
        winner=n;
      }
      }
    std::cout<<"The winner is "<<winner->WhatAmI()<<std::endl;

    if(winner->WhatAmI()=="5 crested Yoshi"){
      for(Character* n : racers){
        delete n;
        }
      return 0;
    }
    for(Character* n : racers){
      delete n;
      }
    return 1;
}

/**
 * Test the default constructor and the constructor for Yoshi
 *
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int Yoshi_constructor_and_destructor(){
  Yoshi y;
  Yoshi y2(5);
  if (y.WhatAmI()=="Bald Yoshi"){
    std::cout<<y.WhatAmI()<<std::endl;
    if (y2.WhatAmI()=="5 crested Yoshi"){
    std::cout<<y2.WhatAmI()<<std::endl;
    return 0;
  }
  }
return 1;
}

int all_test(){
  int i= 0;

  std::cout<< "Test constructeur: "<<std::endl;
  i+=test_ctor();
  std::cout<< "\nTest accelerer: "<<std::endl;
  i+=test_accelerate();
  std::cout<< "\nTest accelerer plus que la vitesse: "<<std::endl;
  i+=test_accelerate_more_than_max_speed();
  std::cout<< "\nTest breack lower than 0: "<<std::endl;
  i+=test_break_lower_than_zero();
  std::cout<< "\nTest break : "<<std::endl;

  i+=test_break();
  std::cout<< "\nTest mario et yoshi: "<<std::endl;
  i+=test_Mario_and_Yoshi();
  std::cout<< "\nTest mario et yoshi accelerate: "<<std::endl;
  i+=test_Mario_and_Yoshi_accelerate();
  test_destructor();
  std::cout<< "\nTest yoshi constructor: "<<std::endl;
  i+=Yoshi_constructor_and_destructor();
  std::cout<< "\nThe BIG RACE: "<<std::endl;
  i+= Let_the_Race_begin();

  if (i==0){
    std::cout<<"Tout les tests sont réussis"<<std::endl;
    return 0;
  }
  return 1;
}
