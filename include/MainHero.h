#ifndef MAINHERO_H
#define MAINHERO_H
#include "Character.h"
#include <fstream>

using std::string;

class MainHero: public Character
{
    private:
        bool attackable;
        float invTime = 1.0f;
        std::fstream attackable_file;

    public:
        MainHero(float posX = 0.0, float posY = 0.0);
        virtual ~MainHero();
        MainHero(const MainHero& other);
        MainHero& operator=(const MainHero& other);

        void getDamaged(int damage);
        void stopInvulnaribilityFrame();

        void setInvTime(float invTime);
        float getInvTime()const;
        bool isAttackable();
        void setAttackable(bool newAttackable);




    protected:



};

#endif // MAINHERO_H
