#include<iostream>
#include "Character.h"
#include "Mario.h"
#include "Yoshi.h"
#include "test_character.h"

int main(){
  int i= 0;

  std::cout<< "Test constructeur: "<<std::endl;
  i=test_ctor();
  std::cout<< "\nTest accelerer: "<<std::endl;
  i=test_accelerate();
  std::cout<< "\nTest accelerer plus que la vitesse: "<<std::endl;
  i=test_accelerate_more_than_max_speed();
  std::cout<< "\nTest breack lower than 0: "<<std::endl;
  i=test_break_lower_than_zero();
  std::cout<< "\nTest break : "<<std::endl;
  i=test_break();
  std::cout<< "\nTest mario et yoshi: "<<std::endl;
  i=test_Mario_and_Yoshi();
  std::cout<< "\nTest mario et yoshi accelerate: "<<std::endl;
  i=test_Mario_and_Yoshi_accelerate();

  test_destructor();
  std::cout<< "\nThe BIG RACE: "<<std::endl;
  Let_the_Race_begin();

  Yoshi_constructor_and_destructor();

return 0;
}
