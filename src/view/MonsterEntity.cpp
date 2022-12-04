#include "view/MonsterEntity.h"

MonsterEntity::MonsterEntity(Monster* monster):monster(monster)
{
    //ctor
    colorOfEntity= new sf::Color(this->getColor());
}

MonsterEntity::~MonsterEntity()
{
    delete monster;
}

MonsterEntity::MonsterEntity(const MonsterEntity& other)
{
    //copy ctor
}

MonsterEntity& MonsterEntity::operator=(const MonsterEntity& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool MonsterEntity::spriteEvents(sf::RenderWindow* window, MainHeroView* mainHeroV)
{
    if(!deadFlag && !deathFlag)
    {
        this->monster->getPosX()<mainHeroV->getMainHero()->getPosX()? this->setScale(2. , 2.) : this->setScale(-2, 2);

        if(this->monster->distanceFromMainHero(*mainHeroV->getMainHero()) <= this->monster->getAggroDistance())
            this->monster->setAggroed(true);

        //Movement
        if(this->monster->isAggroed() && !attackFlag)
        {
            this->setColor(*this->colorOfEntity);
            this->monster->setAllMovementClock(std::chrono::high_resolution_clock::now());

            std::tie(this->movement.x, this->movement.y) = this->monster->moveToMainHero(*mainHeroV->getMainHero());
            idleFlag=false;
            updateSpriteMovementAnimation();
        }

        //Attack
        if(this->getGlobalBounds().intersects(mainHeroV->getGlobalBounds()))
        {
            idleFlag = false;
            if(this->simpleAttackCoolDownTimer.getElapsedTime().asSeconds() > 2.f)
            {
                attackFlag=true;
                mainHeroV->getDamaged(this->monster->getDamage());
                simpleAttackCoolDownTimer.restart();
            }
        }


        this->updatePosition();

        //Action if the sprite is in idle state
        if(idleFlag)
            updateSpriteIdleAnimation();

        //Actions if the sprite is attacking
        if(attackFlag)
        {
            //Animation
            updateSpriteSimpleAttackAnimation();

            //Check if the animation is finished
            if(!attackFlag)
            {
                //Put back the correct position to match the model
                this->setPosition(this->monster->getPosX(), this->monster->getPosY());
                //Adapt textureRect to the dimensions of Idle.png and Movement.png
                this->idleTextureRect->left=0;
                this->movementTextureRect->left=0;
                this->setTextureRect(*idleTextureRect);
                //Enable idle state
                idleFlag=true;
            }
        }
    }

    if(deathFlag)
        updateSpriteDeathAnimation();

    return false;
}

Monster* MonsterEntity::getMonster()const { return monster; }
void MonsterEntity::setMonster(Monster* monster) { this->monster = monster;}

void MonsterEntity::update(Observable* obs)
{
    MainHeroView* mainHeroV = ((MainHeroView*)obs);
    if(this->getGlobalBounds().intersects(mainHeroV->getGlobalBounds()) && this->getScale().x * mainHeroV->getScale().x < 0)
    {
        this->getDamaged(1);
        std::cout<<std::to_string(this->monster->getHP())<<std::endl;
        if(this->deadFlag)
            mainHeroV->detach(this);
    }

}
