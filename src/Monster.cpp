#include "Monster.h"
#include <MainHero.h>

Monster::Monster(float posX, float posY): Character(posX, posY)
{
    //ctor
//    id = new int(++compteur);
//    dead = false;
}

Monster::~Monster()
{
    //dtor
//    delete id;
}

Monster::Monster(const Monster& other)
{
    //copy ctor
    this->setHP(other.getHP());
//    id = new int(*(other.id));
}

Monster& Monster::operator=(const Monster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

//    delete id;
    this->setHP(rhs.getHP());
//    this->id = new int(*rhs.id);
    return *this;
}

void Monster::attack(MainHero* mainHero)
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

//int Monster::getCompteur()
//{
//    return compteur;
//}
//
//int Monster::getId()const
//{
//    return *id;
//}
