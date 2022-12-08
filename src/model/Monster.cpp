#include "model/Monster.h"
#include <model/MainHero.h>
#include <cmath>

Monster::Monster(float posX, float posY): Character(posX, posY)
{
    //ctor
}

Monster::~Monster()
{
    //dtor

}

Monster::Monster(const Monster& other):Character(other)
{
    //copy ctor
    this->dead = other.dead;
    this->scoreValue = other.scoreValue;

}

Monster& Monster::operator=(const Monster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    Character::operator=(rhs);
    this->dead = rhs.dead;
    this->scoreValue = rhs.scoreValue;

    return *this;
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
