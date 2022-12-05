#include "view/MonsterEntity.h"

MonsterEntity::MonsterEntity(Monster* monster):monster(monster)
{
    //ctor
    colorOfEntity= new sf::Color(this->getColor());
}

MonsterEntity::~MonsterEntity()
{
    //where is colorOfEntity deleted? i have segment fault if i delete it here
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
    if(gettingKnockbacked)

            if (knockbackTimer.getElapsedTime() >= sf::milliseconds(100)){
                this->gettingKnockbacked = false;
                knockbackTimer.restart();
            }


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
            spritePosModifier.y = movementTextureRect->height - simpleAttackTextureRect->height;
            //Apply the position modifiers
            this->setPosition(this->monster->getPosX(), this->monster->getPosY() + spritePosModifier.y);
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

bool MonsterEntity::update(Observable* obs)
{
    MainHeroView* mainHeroV = ((MainHeroView*)obs);
    if(this->getGlobalBounds().intersects(mainHeroV->getGlobalBounds()) && this->getScale().x * mainHeroV->getScale().x < 0)
    {
        this->getDamaged(mainHeroV->getMainHero()->getDamage());

        return !this->deadFlag;

    }
    return true;

}

void MonsterEntity::getKnockbacked(){
    this->setColor(sf::Color::Red);
    this->gettingKnockbacked = true;
    int knockbackValue = this->getScale().x > 0 ? -50 : 50;
    this->getMonster()->setPosX(this->getMonster()->getPosX() + knockbackValue);
    this->setPosition(this->getMonster()->getPosX(), this->getMonster()->getPosY());
    this->knockbackTimer.restart();
 }
