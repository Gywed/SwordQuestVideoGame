#include "MainHero.h"
#include <iostream>
#include <ctime>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>


MainHero::MainHero(float posX, float posY): Character(posX, posY)
{
    this->HP = 10;
    this->speed = 0.4;

    attackable_file.open("attackable",std::ios::out);
    attackable_file<<true;
    attackable_file.close();

    attackable_file.open("attackable",std::ios::in);
    attackable_file >> attackable;
    attackable_file.close();
}

MainHero::~MainHero()
{

}

MainHero::MainHero(const MainHero& other)
{
    //copy ctor
    this->HP = other.HP;

}

MainHero& MainHero::operator=(const MainHero& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->setHP(rhs.getHP());

    return *this;
}

void MainHero::getDamaged(int damage)
{
    if (!isAttackable())
        return;
    setAttackable(false);
//    int pid = fork();
//    if (pid == 0)
//    {
//        stopInvulnaribilityFrame();
//        exit(0);
////        kill(pid,SIGTERM);
//
//    } else if (pid > 0) {
        int newHP = getHP() - damage;

        if (newHP <= 0)
        {
            setHP(0);
        }
        else
            setHP(newHP);
    setAttackable(true);
//    }
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



