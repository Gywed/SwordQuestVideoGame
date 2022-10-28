#include "Monster.h"

Monster::Monster()
{
    //ctor
}

Monster::~Monster()
{
    //dtor
}

Monster::Monster(const Monster& other)
{
    //copy ctor
}

Monster& Monster::operator=(const Monster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
