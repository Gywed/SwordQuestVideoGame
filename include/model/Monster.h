#ifndef MONSTER_H
#define MONSTER_H
#include "MainHero.h"

#include <tuple>

class Monster: public Character
{
    protected:
        float aggroDistance;
        bool dead=false, aggroed = false;
        int scoreValue;

//        int* id;
//
//        inline static int compteur;

    public:
        Monster(float posX, float posY);
        virtual ~Monster();
        Monster(const Monster& other);
        Monster& operator=(const Monster& other);

        //Getters/Setters
        float getAggroDistance()const;
        void setAggroDistance(float aggroDistance);
        bool isAggroed()const;
        void setAggroed(bool aggroed);
        int getScoreValue()const;
        void setScoreValue(int newScoreValue);


        virtual void attack(MainHero* mainHero);

        void getDamaged(int damage);

//        static int getCompteur();
//        int getId() const;

        float distanceFromMainHero(MainHero &mainHero);
        //return a tuple containing offsetX and offsetY for the monster's position
        std::tuple<float, float> moveToMainHero(MainHero &mainHero);



};

#endif // MONSTER_H
