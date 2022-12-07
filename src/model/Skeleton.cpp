#include "model/Skeleton.h"

Skeleton::Skeleton(float posX, float posY): Monster(posX, posY)
{
    this->HP = 3;
    this->speed = 0.035;
    this->damage = 2;
    this->scoreValue = HP;
}

Skeleton::~Skeleton()
{
    //dtor
}

Skeleton::Skeleton(const Skeleton& other): Monster(other)
{
    //copy ctor
}

Skeleton& Skeleton::operator=(const Skeleton& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    Monster::operator=(rhs);

    return *this;
}
