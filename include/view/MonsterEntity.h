#ifndef MONSTERENTITY_H
#define MONSTERENTITY_H
#include "view/Entity.h"
#include "model/Monster.h"
#include "model/Observer.h"
#include "view/MainHeroView.h"

class MonsterEntity: public Entity, public Observer
{
    private:
        bool scoreCounted = false;

    public:
        MonsterEntity(Monster* monster);
        virtual ~MonsterEntity();
        MonsterEntity(const MonsterEntity& other);
        MonsterEntity& operator=(const MonsterEntity& other);

        Monster* getMonster()const;
        void setMonster(Monster* monster);

        bool spriteEvents(sf::RenderWindow* window, MainHeroView* mainHeroV);

        virtual void getDamaged(int dmg) = 0;
        //Redefinition of Observer method
        bool update(Observable* obs) override;

    protected:
        Monster* monster;
        sf::Color* colorOfEntity;


};

#endif // MONSTERENTITY_H
