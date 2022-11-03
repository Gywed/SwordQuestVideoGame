#include "Weapon.h"

<<<<<<< HEAD
Weapon::Weapon(int cooldown, float range): cooldown(cooldown), range(range)
=======
Weapon::Weapon(int cooldown, float range, int damage): cooldown(cooldown), range(range), damage(damage)
>>>>>>> origin/dev
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
<<<<<<< HEAD
=======
    this->damage = other.damage;
>>>>>>> origin/dev
    id = new int(*(other.id));
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment operator
    delete id;
    this->cooldown = rhs.cooldown;
    this->range = rhs.range;
<<<<<<< HEAD
=======
    this->damage = rhs.damage;
>>>>>>> origin/dev
    this->id = new int(*rhs.id);

    return *this;
}


<<<<<<< HEAD
int Weapon::attack(){}
=======
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
>>>>>>> origin/dev
