#include "MainHero.h"
#include <iostream>
#include <ctime>
#include <sys/mman.h>
#include <unistd.h>
#define _GNU_SOURCE

MainHero::MainHero(float posX, float posY): posX(posX), posY(posY)
{
    HP = 10;
    attackable_file.open("attackable",std::ios::out);
    attackable_file<<true;
    attackable_file.close();

    attackable_file.open("attackable",std::ios::in);
    attackable_file >> attackable;
    attackable_file.close();
}

MainHero::~MainHero()
{
    //dtor
    for (Weapon* weapon : weapons)
        delete weapon;
}

MainHero::MainHero(const MainHero& other)
{
    //copy ctor
    this->HP = other.HP;

    for (Weapon* weapon : other.weapons)
    {
        this->weapons.push_back(new Weapon(*weapon));
    }
}

MainHero& MainHero::operator=(const MainHero& rhs)
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

void MainHero::getDamaged(int damage)
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

void MainHero::stopInvunaribilityFrame()
{
    usleep(this->invTime*1000000);
    setAttackable(true);
}

void MainHero::setInvTime(float invTime)
{
    this->invTime = invTime;
}

float MainHero::getInvTime()const
{
    return this->invTime;
}

bool MainHero::isAttackable()
{
    attackable_file.open("attackable",std::ios::in);
    attackable_file >> attackable;
    attackable_file.close();
    return attackable;
}

void MainHero::setAttackable(bool newAttackable)
{
    attackable_file.open("attackable",std::ios::out);
    attackable_file<<newAttackable;
    attackable_file.close();
    this->attackable = newAttackable;
}

void MainHero::setHP(int newHP)
{
    this->HP = newHP;
}

int MainHero::getHP() const
{
    return this->HP;
}

float MainHero::getPosX()const { return posX; }
void MainHero::setPosX(float posX) { this->posX = posX; }
float MainHero::getPosY()const { return posY; }
void MainHero::setPosY(float posY) { this->posY = posY; }

//Moving methods
float MainHero::moveUp() { posY-=speed; return -speed; }
float MainHero::moveLeft() { posX-=speed; return -speed; };
float MainHero::moveDown() { posY+=speed; return speed; };
float MainHero::moveRight() { posX+=speed; return speed; };

string MainHero::str() const {
    std::stringstream ss;
    ss << HP;
    return ss.str();
}
