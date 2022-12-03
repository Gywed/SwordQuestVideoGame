#ifndef MONSTERENTITY_H
#define MONSTERENTITY_H
#include "Entity.h"
#include "Monster.h"
#include "Observer.h"
#include "MainHeroView.h"

class MonsterEntity: public Entity, public Observer
{
    private:


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
        void update(Observable* obs) override;

    protected:
        Monster* monster;


};

#endif // MONSTERENTITY_H
