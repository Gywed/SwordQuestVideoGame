#include "Character.h"
#include <iostream>
#include <ctime>
#include <sys/mman.h>
#include <unistd.h>
#define _GNU_SOURCE

Character::Character(float posX, float posY): posX(posX), posY(posY)
{
    HP = 10;
    attackable_file.open("attackable",std::ios::out);
    attackable_file<<true;
    attackable_file.close();

    attackable_file.open("attackable",std::ios::in);
    attackable_file >> attackable;
    attackable_file.close();
}

Character::~Character()
{
    //dtor
    for (Weapon* weapon : weapons)
        delete weapon;
}

Character::Character(const Character& other)
{
    //copy ctor
    this->HP = other.HP;

    for (Weapon* weapon : other.weapons)
    {
        this->weapons.push_back(new Weapon(*weapon));
    }
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->HP = rhs.HP;

    for (Weapon* weapon : weapons)
        delete weapon;
    for (Weapon* weapon : rhs.weapons)
    {
        this->weapons.push_back(new Weapon(*weapon));
    }

    return *this;
}

void Character::getDamaged(int damage)
{
    if (!isAttackable())
        return;
    setAttackable(false);

    if (fork() == 0)
    {
        stopInvunaribilityFrame();
        exit(0);
    }
    int newHP = getHP() - damage;

    if (newHP <= 0)
    {
        setHP(0);
    }
    else
        setHP(newHP);
}

void Character::stopInvunaribilityFrame()
{
    usleep(this->invTime*1000000);
    setAttackable(true);
}

void Character::setInvTime(float invTime)
{
    this->invTime = invTime;
}

float Character::getInvTime()const
{
    return this->invTime;
}

bool Character::isAttackable()
{
    attackable_file.open("attackable",std::ios::in);
    attackable_file >> attackable;
    attackable_file.close();
    return attackable;
}

void Character::setAttackable(bool newAttackable)
{
    attackable_file.open("attackable",std::ios::out);
    attackable_file<<newAttackable;
    attackable_file.close();
    this->attackable = newAttackable;
}

void Character::setHP(int newHP)
{
    this->HP = newHP;
}

int Character::getHP() const
{
    return this->HP;
}

float Character::getPosX()const { return posX; }
void Character::setPosX(float posX) { this->posX = posX; }
float Character::getPosY()const { return posY; }
void Character::setPosY(float posY) { this->posY = posY; }

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
