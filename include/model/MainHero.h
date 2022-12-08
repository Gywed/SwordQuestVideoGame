#ifndef MAINHERO_H
#define MAINHERO_H
#include "Character.h"
#include <fstream>

class MainHero: public Character
{
    private:
        bool attackable;
        float invTime = 1.0f;
        std::fstream attackable_file;

        // Used to notify if the main hero got healed
        bool receiveHeal = false;

    public:
        MainHero(float posX = 0.0, float posY = 0.0);
        virtual ~MainHero();
        MainHero(const MainHero& other);
        MainHero& operator=(const MainHero& other);

        void receiveDamage(int damage);
        void stopInvulnaribilityFrame();

        // Getter/Setter
        void setInvTime(float invTime);
        float getInvTime()const;
        bool isAttackable();
        void setAttackable(bool newAttackable);
        bool isHealed() const;

        void getHealed(int heal);

        void init();


    protected:



};

#endif // MAINHERO_H
