#include "view/SlimeLongView.h"
#include <iostream>

SlimeLongView::SlimeLongView(SlimeLong* slimeLong): MonsterEntity(slimeLong)
{
    this->setPosition(slimeLong->getPosX(), slimeLong->getPosY());

    //Idle animation
    this->idleTextureRect = new sf::IntRect(0, 0, 17, 25);
    this->idleTextureSource = "images/Animation/SlimeLong/Idle.png";
    this->idleAnimationStep = 17;
    this->idleTextureRectMaxLeft = 51;
    this->idleAnimationTimeBetweenEachFrame = 0.35;

    //Movement animation
    this->movementTextureRect = new sf::IntRect(0, 0, 17, 25);
    this->movementTextureSource = "images/Animation/SlimeLong/Movement.png";
    this->movementAnimationStep = 17;
    this->movementTextureRectMaxLeft = 51;
    this->movementAnimationTimeBetweenEachFrame = 0.15;

    //Simple attack animation
    this->simpleAttackTextureRect = new sf::IntRect(0, 0, 34, 23);
    this->simpleAttackTextureSource = "images/Animation/SlimeLong/Attack1.png";
    this->simpleAttackAnimationStep = 34;
    this->simpleAttackTextureRectMaxLeft = 204;
    this->simpleAttackAnimationTimeBetweenEachFrame = 0.13;

    //Death animation
    this->deathTextureRect = new sf::IntRect(0, 0, 34, 32);
    this->deathTextureSource = "images/Animation/SlimeLong/Death.png";
    this->deathAnimationStep = 34;
    this->deathTextureRectMaxLeft = 136;
    this->deathAnimationTimeBetweenEachFrame = 0.15;

    this->setTexture(*Entity::resourceManager.searchTexturesList(idleTextureSource));
    this->setTextureRect(*idleTextureRect);
    this->setScale(2., 2.);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -16);


    this->colorOfSkeleton =new sf::Color(this->getColor());
}

SlimeLongView::~SlimeLongView()
{
    //dtor
    delete colorOfSkeleton;
}

SlimeLongView::SlimeLongView(const SlimeLongView& other): MonsterEntity(other)
{
    //copy ctor
}

SlimeLongView& SlimeLongView::operator=(const SlimeLongView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


//Method
//###################################################################################################
void SlimeLongView::receiveDamage(int dmg)
{
    this->monster->receiveDamage(dmg);
    int hp = this->monster->getHP();
    if(hp==0)
    {
        this->setColor(*this->colorOfSkeleton);
        idleFlag=false;
        attackFlag=false;
        deathFlag=true;

        this->setTextureRect(*deathTextureRect);
        //determine the value of the position modifier for the attack because of the texture size differences
        spritePosModifier.x = abs(movementTextureRect->width - deathTextureRect->width);
        spritePosModifier.x *= this->getScale().x < 0 ? -1. : 1.;
        spritePosModifier.y = abs(movementTextureRect->height - deathTextureRect->height);
        //Apply the position modifiers
        this->setPosition(this->monster->getPosX() - spritePosModifier.x, this->monster->getPosY() - spritePosModifier.y);

    }else
    {
        this->getKnockbacked();
    }
}

