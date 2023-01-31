#include<iostream>
#include "test_character.h"
#include "Character.h"


/**
 * Test the constructor an if the speed is set to 0
 * @param none
 * @return 0 if the test is a success; 1 if not
 */
int test_ctor(){
    Character c;
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
  Character c;
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
  Character c;
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
  Character c;
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
  Character c;
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
  Character *c = new Character;
  delete c;
}
