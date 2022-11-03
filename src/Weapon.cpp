#include "Weapon.h"


Weapon::Weapon(int cooldown, float range, int damage): cooldown(cooldown), range(range), damage(damage)

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

    this->damage = other.damage;

    id = new int(*(other.id));
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment operator
    delete id;
    this->cooldown = rhs.cooldown;
    this->range = rhs.range;

    this->damage = rhs.damage;

    this->id = new int(*rhs.id);

    return *this;
}


void Weapon::attack(vector<Monster*>){}

void Weapon::setDamage(int newDamage)
{
    this->damage = newDamage;
}

int Weapon::getDamage()const
{
    return this->damage;
}


int Weapon::getCompteur()
{
    return compteur;
}

int Weapon::getId()const
{
    return *id;
}

