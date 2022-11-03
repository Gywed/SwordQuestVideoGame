#include "Weapon.h"

Weapon::Weapon(int cooldown, float range): cooldown(cooldown), range(range)
{
    //ctor
    id = new int(++compteur);
}

Weapon::~Weapon()
{
    //dtor
    delete id;
}

Weapon::Weapon(const Weapon& other)
{
    this->cooldown = other.cooldown;
    this->range = other.range;
    id = new int(*(other.id));
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment operator
    delete id;
    this->cooldown = rhs.cooldown;
    this->range = rhs.range;
    this->id = new int(*rhs.id);

    return *this;
}


void Weapon::attack(){}

int Weapon::getCompteur()
{
    return compteur;
}
