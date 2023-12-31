#ifndef MONSTER_H
#define MONSTER_H
#include "MainHero.h"

#include <tuple>

class Monster: public Character
{
    protected:
        bool dead=false;
        int scoreValue;



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

        void receiveDamage(int damage);


        float distanceFromMainHero(MainHero &mainHero);
        //return a tuple containing offsetX and offsetY for the monster's position
        std::tuple<float, float> moveToMainHero(MainHero &mainHero);



};

#endif // MONSTER_H
