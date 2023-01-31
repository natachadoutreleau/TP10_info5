#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character{
public:

    Character();
    ~Character()=default;

    void Accelerate();
    void Break();
    float speed() const;

    protected :
        float speed_;
        float max_speed_;
};

/**
 * Inlined getter of speed
 * @param none
 */
inline float Character::speed()const{
  return speed_;
}

#endif
