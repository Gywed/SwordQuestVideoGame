#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <Weapon.h>
#include <string>
#include <sstream>
#include <fstream>

using std::string;
using std::vector;

class MainHero
{
    private:
        int HP;
        float posX, posY, speed=0.4;
        vector<Weapon*> weapons;
        bool attackable;
        float invTime = 1.0f;
        std::fstream attackable_file;

    public:
        MainHero(float posX = 0.0, float posY = 0.0);
        virtual ~MainHero();
        MainHero(const MainHero& other);
        MainHero& operator=(const MainHero& other);
        string str() const;

        void getDamaged(int damage);
        void stopInvunaribilityFrame();

        void setHP(int newHP);
        int getHP() const;
        float getPosX()const;
        void setPosX(float posX);
        float getPosY()const;
        void setInvTime(float invTime);
        float getInvTime()const;
        void setPosY(float posY);
        bool isAttackable();
        void setAttackable(bool newAttackable);

        //Return the speed
        float moveUp();
        float moveLeft();
        float moveDown();
        float moveRight();


    protected:



};

#endif // CHARACTER_H
