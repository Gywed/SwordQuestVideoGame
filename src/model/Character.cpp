#include "model/Character.h"

int Character::nbClock = 0;
float Character::clockAvrg = 0.;

Character::Character(float posX, float posY): posX(posX), posY(posY)
{
    //ctor
}

Character::~Character()
{
    //dtor
}

Character::Character(const Character& other): posX(other.posX), posY(other.posY)
{
    //copy ctor
    this->HP = other.HP;
    this->damage = other.damage;
    this->speed = other.speed;
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->posX = rhs.posX;
    this->posY = rhs.posY;
    this->HP = rhs.HP;
    this->damage = rhs.damage;
    this->speed = rhs.speed;
    return *this;
}

//Getters/Setters
void Character::setUpClock(std::chrono::_V2::system_clock::time_point clock) { this->upClock = clock; }
void Character::setDownClock(std::chrono::_V2::system_clock::time_point clock) { this->downClock = clock; }
void Character::setRightClock(std::chrono::_V2::system_clock::time_point clock) { this->rightClock = clock; }
void Character::setLeftClock(std::chrono::_V2::system_clock::time_point clock) { this->leftClock = clock; }
void Character::setAllMovementClock(std::chrono::_V2::system_clock::time_point clock) {
    this->upClock = clock;
    this->downClock = clock;
    this->rightClock = clock;
    this->leftClock = clock;
}

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

void Character::newClockavrg(int newClock)
{
    nbClock++;
    clockAvrg = clockAvrg+((newClock-Character::clockAvrg)/nbClock);
}

//Moving methods
float Character::moveUp(float singleKeyBoost) {
    if (nbClock < 10000)
    {
        std::chrono::_V2::system_clock::time_point newTime = high_resolution_clock::now();
        int frameTime = ((((newTime - upClock) / nanoseconds(1))/100)+1)*0.8;
        newClockavrg(frameTime);
    }

    float realSpeed = speed*(clockAvrg)*singleKeyBoost;
    posY-=realSpeed;
    return -realSpeed;
}
float Character::moveLeft(float singleKeyBoost) {
    if (nbClock < 10000)
    {
        std::chrono::_V2::system_clock::time_point newTime = high_resolution_clock::now();
        int frameTime = ((((newTime - leftClock) / nanoseconds(1))/100)+1)*0.8;
        newClockavrg(frameTime);
    }

    float realSpeed = speed*(clockAvrg)*singleKeyBoost;
    posX-=realSpeed;
    return -realSpeed;
}
float Character::moveDown(float singleKeyBoost) {
    if (nbClock < 10000)
    {
        std::chrono::_V2::system_clock::time_point newTime = high_resolution_clock::now();
        int frameTime = ((((newTime - downClock) / nanoseconds(1))/100)+1)*0.8;
        newClockavrg(frameTime);
    }

    float realSpeed = speed*(clockAvrg)*singleKeyBoost;
    posY+=realSpeed;
    return realSpeed;
}
float Character::moveRight(float singleKeyBoost) {
    if (nbClock < 10000)
    {
        std::chrono::_V2::system_clock::time_point newTime = high_resolution_clock::now();
        int frameTime = ((((newTime - rightClock) / nanoseconds(1))/100)+1)*0.8;
        newClockavrg(frameTime);
    }

    float realSpeed = speed*(clockAvrg)*singleKeyBoost;
    posX+=realSpeed;
    return realSpeed;

}


