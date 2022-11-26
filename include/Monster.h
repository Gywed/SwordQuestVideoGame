#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"

// include <MainHero.h> dans Monster.cpp, sinon ça fait des déclaration ciruclaire (MainHero include Weapon, Weapon include Monster, Monster include MainHero ... Boucled)
class MainHero;

class Monster: public Character
{
    private:
        bool dead;

//        int* id;
//
//        inline static int compteur;

    public:
        Monster(float posX, float posY);
        virtual ~Monster();
        Monster(const Monster& other);
        Monster& operator=(const Monster& other);

        virtual void attack(MainHero* mainHero);

        void getDamaged(int damage);

//        static int getCompteur();
//        int getId() const;

    protected:


};

#endif // MONSTER_H
