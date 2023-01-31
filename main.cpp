#include<iostream>
#include "Character.h"
#include "test_character.h"

int main(){
  int i= 0;
  std::cout<< "Test 1: "<<std::endl;
  i=test_ctor();
  std::cout<< "\nTest 2: "<<std::endl;
  i=test_accelerate();
  std::cout<< "\nTest 3: "<<std::endl;
  i=test_accelerate_more_than_max_speed();
  std::cout<< "\nTest 4: "<<std::endl;
  i=test_break_lower_than_zero();
  std::cout<< "\nTest 5: "<<std::endl;
  i=test_break();

  test_destructor();


return 0;
}
