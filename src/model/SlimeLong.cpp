#include "model/SlimeLong.h"

SlimeLong::SlimeLong(float posX, float posY): Monster(posX, posY)
{
    this->HP = 1;
    this->speed = 0.02;
    this->aggroDistance = 300;
    this->damage = 1;
    this->scoreValue = 1;
}

SlimeLong::~SlimeLong()
{
    //dtor
}

SlimeLong::SlimeLong(const SlimeLong& other): Monster(other)
{
    //copy ctor
}

SlimeLong& SlimeLong::operator=(const SlimeLong& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    Monster::operator=(rhs);

    return *this;
}
