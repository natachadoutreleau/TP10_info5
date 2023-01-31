#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character{
public:

    Character();
    ~Character()=default;

    void Accelerate();
    void Break();
    inline float speed() const;

    protected :
        float speed_;
        float max_speed_;
};


#endif
