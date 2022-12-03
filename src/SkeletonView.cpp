#include "SkeletonView.h"
#include <iostream>

SkeletonView::SkeletonView(Skeleton* skeleton): skeleton(skeleton)
{
    this->setPosition(skeleton->getPosX(), skeleton->getPosY());

    //Idle animation
    this->idleTextureRect = new sf::IntRect(0, 0, 32, 40);
    this->idleTextureSource = "images/Animation/Skeleton/Idle.png";
    this->idleAnimationStep = 32;
    this->idleTextureRectMaxLeft = 96;
    this->idleAnimationTimeBetweenEachFrame = 0.35;

    //Movement animation
    this->movementTextureRect = new sf::IntRect(0, 0, 28, 42);
    this->movementTextureSource = "images/Animation/Skeleton/Movement.png";
    this->movementAnimationStep = 28;
    this->movementTextureRectMaxLeft = 112;
    this->movementAnimationTimeBetweenEachFrame = 0.15;

    //Simple attack animation
    this->simpleAttackTextureRect = new sf::IntRect(0, 0, 44, 41);
    this->simpleAttackTextureSource = "images/Animation/Skeleton/Attack1.png";
    this->simpleAttackAnimationStep = 44;
    this->simpleAttackTextureRectMaxLeft = 220;
    this->simpleAttackAnimationTimeBetweenEachFrame = 0.13;

    //Death animation
    this->deathTextureRect = new sf::IntRect(0, 0, 38, 56);
    this->deathTextureSource = "images/Animation/Skeleton/Death.png";
    this->deathAnimationStep = 38;
    this->deathTextureRectMaxLeft = 190;
    this->deathAnimationTimeBetweenEachFrame = 0.3;

    this->loadTexture(idleTextureSource);
    this->setTextureRect(*idleTextureRect);
    this->setScale(2., 2.);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -16);
}

SkeletonView::~SkeletonView()
{
    //dtor
}

SkeletonView::SkeletonView(const SkeletonView& other)
{
    //copy ctor
}

SkeletonView& SkeletonView::operator=(const SkeletonView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Skeleton* SkeletonView::getSkeleton()const { return skeleton; }
void SkeletonView::setSkeleton(Skeleton* skeleton) { this->skeleton = skeleton;}


//Method
//###################################################################################################
bool SkeletonView::spriteEvents(sf::RenderWindow* window, MainHeroView* mainHeroV)
{
    this->skeleton->getPosX()<mainHeroV->getMainHero()->getPosX()? this->setScale(2. , 2.) : this->setScale(-2, 2);

    if(this->skeleton->distanceFromMainHero(*mainHeroV->getMainHero()) <= this->skeleton->getAggroDistance())
        this->skeleton->setAggroed(true);

    //Movement
    if(this->skeleton->isAggroed() && !attackFlag)
    {
        this->skeleton->setAllMovementClock(std::chrono::high_resolution_clock::now());

        std::tie(this->movement.x, this->movement.y) = this->skeleton->moveToMainHero(*mainHeroV->getMainHero());
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
            mainHeroV->getDamaged(this->skeleton->getDamage());
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
            this->setPosition(this->skeleton->getPosX(), this->skeleton->getPosY());
            //Adapt textureRect to the dimensions of Idle.png and Movement.png
            this->idleTextureRect->left=0;
            this->movementTextureRect->left=0;
            this->setTextureRect(*idleTextureRect);
            //Enable idle state
            idleFlag=true;
        }
    }
}

void SkeletonView::getDamaged(int dmg)
{
    this->skeleton->getDamaged(dmg);
    int hp = this->skeleton->getHP();
    if(hp==0)
    {
        idleFlag=false;
        attackFlag=false;
        deathFlag=true;

        this->setTextureRect(*deathTextureRect);
        //determine the value of the position modifier for the attack because of the texture size differences
        if(this->getScale().x < 0)
            spritePosModifier.x = -30;
        else
            spritePosModifier.x = 30;
        spritePosModifier.y = 27;
        //Apply the position modifiers
        this->setPosition(this->skeleton->getPosX() - spritePosModifier.x, this->skeleton->getPosY() - spritePosModifier.y);
    }
}


