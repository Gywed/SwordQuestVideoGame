#include "SkeletonView.h"
#include <iostream>

SkeletonView::SkeletonView(Skeleton* skeleton): skeleton(skeleton)
{
    this->setPosition(skeleton->getPosX(), skeleton->getPosY());
    this->loadTexture("images/Animation/Skeleton/Idle.png");
    this->idleTextureRect = new sf::IntRect(0, 0, 32, 40);
    this->movementTextureRect = new sf::IntRect(0, 0, 28, 42);
    this->simpleAttackTextureRect = new sf::IntRect(0, 0, 44, 41);
    this->deathTextureRect = new sf::IntRect(0, 0, 38, 56);
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
void SkeletonView::spriteEvents(sf::RenderWindow* window, MainHero* mainHero)
{
    this->skeleton->getPosX()<mainHero->getPosX()? this->setScale(2. , 2.) : this->setScale(-2, 2);

    if(this->skeleton->distanceFromMainHero(*mainHero) <= this->skeleton->getAggroDistance())
        this->skeleton->setAggroed(true);

    //Movement
    if(this->skeleton->isAggroed())
    {
        std::tie(this->movement.x, this->movement.y) = this->skeleton->moveToMainHero(*mainHero);
        idleFlag=false;
        updateSpriteMovementAnimation();
    }


    this->updatePosition();

    //Action if the sprite is in idle state
    if(idleFlag)
        updateSpriteIdleAnimation();
}

//Animation
void SkeletonView::updateSpriteIdleAnimation()
{
    this->loadTexture("images/Animation/Skeleton/Idle.png");
    //Shift textureRect every time given
    if (animationTimer.getElapsedTime().asSeconds() > 0.35f){

        if (idleTextureRect->left == 96)
            idleTextureRect->left=0;
        else
            idleTextureRect->left+=32;

        this->setTextureRect(*idleTextureRect);
        animationTimer.restart();
    }
}

void SkeletonView::updateSpriteMovementAnimation()
{
    this->loadTexture("images/Animation/Skeleton/Movement.png");
    this->setTextureRect(*movementTextureRect);
    //Shift textureRect every time given
    if (animationTimer.getElapsedTime().asSeconds() > 0.15f){

        if (movementTextureRect->left == 112)
            movementTextureRect->left=0;
        else
            movementTextureRect->left+=28;

        this->setTextureRect(*movementTextureRect);
        animationTimer.restart();
    }
}

void SkeletonView::updateSpriteSimpleAttackAnimation()
{

}

void SkeletonView::updateSpriteDeathAnimation()
{
    this->loadTexture("images/Animation/Skeleton/Death.png");
    this->setTextureRect(*deathTextureRect);
    if (animationTimer.getElapsedTime().asSeconds() > 0.3f){

        if (deathTextureRect->left == 190)
        {
            //When we reach the end of Death.png sprite sheet, we notify the end of the death animation
            deathFlag=false;
            deadFlag = true;
        }
        else
            deathTextureRect->left+=38;

        this->setTextureRect(*deathTextureRect);
        animationTimer.restart();
    }
}


