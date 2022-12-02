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
void Character::setMovementClock(clock_t clock) { this->startClock = clock; }
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
float Character::moveUp() {
    float newTime = clock();
    float frameTime = (newTime - startClock);
    startClock = newTime;
    posY-=speed*(frameTime);
    return -speed*(frameTime);
}
float Character::moveLeft() {
    float newTime = clock();
    float frameTime = (newTime - startClock);
    startClock = newTime;
    float realSpeed = speed*(frameTime);
    posX-=realSpeed;
    return -realSpeed;
}
float Character::moveDown() {
    float newTime = clock();
    float frameTime = (newTime - startClock);
    startClock = newTime;
    float realSpeed = speed*(frameTime);
    posY+=realSpeed;
    return realSpeed;
}
float Character::moveRight() {
    float newTime = clock();
    float frameTime = (newTime - startClock);
    startClock = newTime;
    float realSpeed = speed*(frameTime);
    posX+=realSpeed;
    return realSpeed;
}

string Character::str() const {
    std::stringstream ss;
    ss << HP;
    return ss.str();
}
