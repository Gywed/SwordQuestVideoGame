#include "Weapon.h"

Weapon::Weapon()
{
    //ctor
}

Weapon::~Weapon()
{
    //dtor
}

Weapon::Weapon(const Weapon& other)
{
    //copy ctor
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
