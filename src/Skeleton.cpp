#include "Skeleton.h"

Skeleton::Skeleton(float posX, float posY): Monster(posX, posY)
{
    this->setHP(5);
    this->setSpeed(0.3);
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
