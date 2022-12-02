#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Character
{
    private:
        // Clock for harmonized movement
        std::chrono::_V2::system_clock::time_point upClock;
        std::chrono::_V2::system_clock::time_point downClock;
        std::chrono::_V2::system_clock::time_point leftClock;
        std::chrono::_V2::system_clock::time_point rightClock;

        static int nbClock;
        static float clockAvrg;

        static void newClockavrg(int newClock);

    protected:
        int HP, damage;
        float posX, posY, speed;

    public:
        Character(float posX = 0.0, float posY = 0.0);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);

        // Get/Set
        void setUpClock(std::chrono::_V2::system_clock::time_point clock);
        void setDownClock(std::chrono::_V2::system_clock::time_point clock);
        void setLeftClock(std::chrono::_V2::system_clock::time_point clock);
        void setRightClock(std::chrono::_V2::system_clock::time_point clock);

        void setHP(int newHP);
        int getHP() const;
        void setDamage(int newDamage);
        int getDamage()const;
        float getPosX()const;
        void setPosX(float posX);
        float getPosY()const;
        void setPosY(float posY);
        float getSpeed()const;
        void setSpeed(float speed);

        //Return the speed
        float moveUp();
        float moveLeft();
        float moveDown();
        float moveRight();

};

#endif // CHARACTER_H
