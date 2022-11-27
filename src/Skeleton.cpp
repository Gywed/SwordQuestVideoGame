#include "Skeleton.h"

Skeleton::Skeleton(float posX, float posY): Monster(posX, posY)
{
    this->HP = 5;
    this->speed = 0.3;
    this->aggroDistance = 50;
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
    return *this;
}
