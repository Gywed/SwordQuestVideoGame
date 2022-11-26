#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <sstream>

using namespace std;

class Character
{
    private:
        int HP, damage;
        float posX, posY, speed;

    public:
        Character(float posX = 0.0, float posY = 0.0);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        string str() const;

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
