#include "model/MainHero.h"
#include <iostream>
#include <unistd.h>
#include <signal.h>


MainHero::MainHero(float posX, float posY): Character(posX, posY)
{
    init();
}

MainHero::~MainHero()
{

}

MainHero::MainHero(const MainHero& other):Character(other),attackable(other.attackable), invTime(other.invTime)
{
    //copy ctor
}

MainHero& MainHero::operator=(const MainHero& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Character::operator=(rhs);
    this->attackable = rhs.attackable;
    this->invTime= rhs.invTime;

    return *this;
}

void MainHero::init()
{
    this->HP = 10;
    this->speed = 0.1;
    this->damage = 1;

    attackable_file.open("attackable",std::ios::out);
    attackable_file<<true;
    attackable_file.close();

    attackable_file.open("attackable",std::ios::in);
    attackable_file >> attackable;
    attackable_file.close();
}

void MainHero::receiveDamage(int damage)
{
    if (!isAttackable())
        return;
    setAttackable(false);
    pid_t pid = fork();
    if (pid == 0)
    {
        stopInvulnaribilityFrame();
        kill(getpid(),SIGTERM);

    } else if (pid > 0) {
        int newHP = getHP() - damage;

        if (newHP <= 0)
        {
            setHP(0);
        }
        else
            setHP(newHP);

    }
}

void MainHero::stopInvulnaribilityFrame()
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

void MainHero::getHealed(int heal)
{
    if(getHP()<10)
    {
        this->setHP(this->getHP()+heal);
        if(getHP()>10)setHP(10);
    }

}

