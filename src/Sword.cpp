#include "Sword.h"

<<<<<<< HEAD
Sword::Sword(int cooldown, float range): Weapon(cooldown,range)
=======
Sword::Sword(int cooldown, float range, int damage): Weapon(cooldown,range,damage)
>>>>>>> origin/dev
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

<<<<<<< HEAD
int Sword::attack()
{
    return 666;
=======
void Sword::attack(vector<Monster*> monsters)
{
    for (Monster* monster : monsters)
    {
        monster->getDamaged(getDamage());
    }
>>>>>>> origin/dev
}
