#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>

class Character{
public:

    Character();
    virtual ~Character()=default;

    virtual void Accelerate();
    void Break();
    float speed() const;
    virtual std::string WhatAmI() const = 0;

    protected :
        float speed_;
        float max_speed_;
};

/**
 * Inlined getter of speed
 * @param none
 * @return float speed
 */
inline float Character::speed()const{
  return speed_;
}

#endif
