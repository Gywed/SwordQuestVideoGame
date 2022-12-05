#include "model/SlimeRound.h"

SlimeRound::SlimeRound(float posX, float posY): Monster(posX, posY)
{
    this->HP = 1;
    this->speed = 0.02;
    this->aggroDistance = 300;
    this->damage = 1;
    this->scoreValue = 1;
}

SlimeRound::~SlimeRound()
{
    //dtor
}

SlimeRound::SlimeRound(const SlimeRound& other): Monster(other)
{
    //copy ctor
}

SlimeRound& SlimeRound::operator=(const SlimeRound& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    Monster::operator=(rhs);

    return *this;
}
