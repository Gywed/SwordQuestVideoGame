#include "Character.h"

Character::Character()
{
    HP = 10;
}

Character::~Character()
{
    //dtor
}

Character::Character(const Character& other)
{
    //copy ctor
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string Character::str() const {
    std::stringstream ss;
    ss << HP;
    return ss.str();
}
