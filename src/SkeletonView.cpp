#include "SkeletonView.h"

SkeletonView::SkeletonView(Skeleton* skeleton): skeleton(skeleton)
{
    this->setPosition(skeleton->getPosX(), skeleton->getPosY());
    this->loadTexture("images/Animation/Skeleton/Idle.png");
    this->idleTextureRect = new sf::IntRect(0, 0, 28, 40);
    this->movementTextureRect = new sf::IntRect(0, 0, 32, 42);
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
void SkeletonView::spriteEvents(sf::RenderWindow* window)
{
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

}

void SkeletonView::updateSpriteSimpleAttackAnimation()
{

}

void SkeletonView::updateSpriteDeathAnimation()
{

}


