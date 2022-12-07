#include "model/Monster.h"
#include <model/MainHero.h>
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

Monster::Monster(const Monster& other):Character(other)
{
    //copy ctor
    this->dead = other.dead;
    this->scoreValue = other.scoreValue;
//    id = new int(*(other.id));
}

Monster& Monster::operator=(const Monster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

//    delete id;
    Character::operator=(rhs);
    this->dead = rhs.dead;
    this->scoreValue = rhs.scoreValue;
//    this->id = new int(*rhs.id);
    return *this;
}

void Monster::attack(MainHero* mainHero)
{

}

void Monster::receiveDamage(int damage)
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
int Monster::getScoreValue()const { return scoreValue;}
void Monster::setScoreValue(int newScoreValue) { this->scoreValue = newScoreValue;}

float Monster::distanceFromMainHero(MainHero &mainHero)
{
    return sqrt(pow((mainHero.getPosX() - this->posX), 2.) + pow((mainHero.getPosY() - this->posY), 2.));
}

//return a tuple containing offsetX and offsetY for the monster's position
std::tuple<float, float> Monster::moveToMainHero(MainHero &mainHero)
{
    float offsetX=0;
    float offsetY=0;
    if(posX == mainHero.getPosX())
    {
        offsetX = 0;
    }else
    {
        if(posX > mainHero.getPosX()+40)
            offsetX = moveLeft();

        if(posX < mainHero.getPosX()-40)
            offsetX = moveRight();

    }

    if(posY == mainHero.getPosY())
    {
        offsetY = 0;
    }else
        posY > mainHero.getPosY()? offsetY = moveUp() : offsetY = moveDown();

    return std::make_tuple(offsetX, offsetY);
}
