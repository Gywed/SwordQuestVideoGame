#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <Weapon.h>
#include <string>
#include <sstream>

using std::string;
using std::vector;

class Character
{
    private:
        int HP;
        float posX, posY, speed=0.4;
        vector<Weapon*> weapons;
    public:
        Character(float posX, float posY);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        string str() const;

        void getDamaged(int damage);

        void setHP(int newHP);
        int getHP() const;
        float getPosX()const;
        void setPosX(float posX);
        float getPosY()const;
        void setPosY(float posY);

        //Return the speed
        float moveUp();
        float moveLeft();
        float moveDown();
        float moveRight();


    protected:



};

#endif // CHARACTER_H
