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
//###################################################################################################
bool SkeletonView::spriteEvents(sf::RenderWindow* window, MainHeroView* mainHeroV)
{
    this->skeleton->getPosX()<mainHeroV->getMainHero()->getPosX()? this->setScale(2. , 2.) : this->setScale(-2, 2);

    if(this->skeleton->distanceFromMainHero(*mainHeroV->getMainHero()) <= this->skeleton->getAggroDistance())
        this->skeleton->setAggroed(true);

    //Movement
    if(this->skeleton->isAggroed() && !attackFlag)
    {
        this->skeleton->setMovementClock(std::clock());
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

//Animation
//###################################################################################################
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
    this->loadTexture("images/Animation/Skeleton/Attack1.png");
    this->setTextureRect(*simpleAttackTextureRect);
    if (animationTimer.getElapsedTime().asSeconds() > 0.13f){

        if (simpleAttackTextureRect->left == 220)
        {
            simpleAttackTextureRect->left=0;
            //When we reach the end of Attack1.png sprite sheet, we notify the end of the attack
            attackFlag=false;
        }
        else
            simpleAttackTextureRect->left+=44;

        this->setTextureRect(*simpleAttackTextureRect);
        animationTimer.restart();
    }
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


