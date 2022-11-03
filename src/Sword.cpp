#include "Sword.h"

Sword::Sword(int cooldown, float range): Weapon(cooldown,range)
{
    //ctor
}

Sword::~Sword()
{
    //dtor
}

Sword::Sword(const Sword& other) : Weapon(other)
{
    //copy ctor
}

Sword& Sword::operator=(const Sword& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    Weapon::operator=(rhs);
    return *this;
}

void Sword::attack()
{

}
