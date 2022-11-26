#include "Character.h"

Character::Character(float posX, float posY): posX(posX), posY(posY)
{
    //ctor
}

Character::~Character()
{
    //dtor
}

Character::Character(const Character& other)
{
    //copy ctor
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Getters/Setters
float Character::getPosX()const { return posX; }
void Character::setPosX(float posX) { this->posX = posX; }
float Character::getPosY()const { return posY; }
void Character::setPosY(float posY) { this->posY = posY; }
void Character::setHP(int newHP) { this->HP = newHP; }
int Character::getHP() const { return this->HP; }
float Character::getSpeed()const { return speed; }
void Character::setSpeed(float speed) { this->speed = speed; }
void Character::setDamage(int newDamage) { this->damage = newDamage; }
int Character::getDamage()const { return damage; }

//Moving methods
float Character::moveUp() { posY-=speed; return -speed; }
float Character::moveLeft() { posX-=speed; return -speed; };
float Character::moveDown() { posY+=speed; return speed; };
float Character::moveRight() { posX+=speed; return speed; };

string Character::str() const {
    std::stringstream ss;
    ss << HP;
    return ss.str();
}
