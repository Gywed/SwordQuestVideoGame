#include "Monster.h"
#include <MainHero.h>
#include <cmath>
#include <iostream>

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

//Getters/Setters
float Monster::getAggroDistance()const { return aggroDistance; }
void Monster::setAggroDistance(float aggroDistance) { this->aggroDistance = aggroDistance; }
bool Monster::isAggroed()const { return aggroed; }
void Monster::setAggroed(bool aggroed) { this->aggroed = aggroed; }

float Monster::distanceFromMainHero(MainHero &mainHero)
{
    return sqrt(pow((mainHero.getPosX() - this->posX), 2.) + pow((mainHero.getPosY() - this->posY), 2.));
}

//return a tuple containing offsetX and offsetY for the monster's position
std::tuple<float, float> Monster::moveToMainHero(MainHero &mainHero)
{
    float offsetX;
    float offsetY;
    if(posX == mainHero.getPosX())
    {
        offsetX = 0;
    }else
        posX > mainHero.getPosX()? offsetX = moveLeft() : offsetX = moveRight();

    if(posY == mainHero.getPosY())
    {
        offsetY = 0;
    }else
        posY > mainHero.getPosY()? offsetY = moveUp() : offsetY = moveDown();

    return std::make_tuple(offsetX, offsetY);
}
