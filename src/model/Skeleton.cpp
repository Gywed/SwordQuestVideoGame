#include "model/Skeleton.h"

Skeleton::Skeleton(float posX, float posY): Monster(posX, posY)
{
    this->HP = 2;
    this->speed = 0.04;
    this->aggroDistance = 300;
    this->damage = 2;
    this->scoreValue = 2;
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
