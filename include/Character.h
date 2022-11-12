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
        int posX, posY, speed=0.1;
        vector<Weapon*> weapons;
    public:
        Character(int posX, int posY);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        string str() const;

        void getDamaged(int damage);

        void setHP(int newHP);
        int getHP() const;
        int getPosX()const;
        void setPosX(int posX);
        int getPosY()const;
        void setPosY(int posY);


    protected:



};

#endif // CHARACTER_H
