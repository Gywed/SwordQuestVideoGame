#include "Monster.h"
#include <MainHero.h>

Monster::Monster(int HP, int damage): HP(HP), damage(damage)
{
    //ctor
    id = new int(++compteur);
    dead = false;
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

void Monster::attack(Character* character)
{

}

void Monster::getDamaged(int damage)
{
    int newHP = getHP() - damage;

    if (newHP <= 0)
    {
        this->dead = true;
        setHP(0);
    }
    else
        setHP(newHP);
}

void Monster::setDamage(int newDamage)
{
    this->damage = newDamage;
}

int Monster::getDamage()const
{
    return this->damage;
}

int Monster::getCompteur()
{
    return compteur;
}

int Monster::getId()const
{
    return *id;
}

void Monster::setHP(int newHP)
{
    this->HP = newHP;
}

int Monster::getHP() const
{
    return this->HP;
}
