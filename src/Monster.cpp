#include "Monster.h"

Monster::Monster(int HP): HP(HP)
{
    //ctor
    id = new int(++compteur);
}

Monster::~Monster()
{
    //dtor
    delete id;
}

Monster::Monster(const Monster& other)
{
    //copy ctor
    this->HP = other.HP;
    id = new int(*(other.id));
}

Monster& Monster::operator=(const Monster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    delete id;
    this->HP = rhs.HP;
    this->id = new int(*rhs.id);
    return *this;
}

void Monster::attack(){}

int Monster::getCompteur()
{
    return compteur;
}
