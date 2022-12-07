#include "view/SlimeRoundView.h"
#include <iostream>

SlimeRoundView::SlimeRoundView(SlimeRound* slimeRound): MonsterEntity(slimeRound)
{
    this->setPosition(slimeRound->getPosX(), slimeRound->getPosY());

    //Idle animation
    this->idleTextureRect = new sf::IntRect(0, 0, 26, 21);
    this->idleTextureSource = "images/Animation/SlimeRound/Idle.png";
    this->idleAnimationStep = 26;
    this->idleTextureRectMaxLeft = 78;
    this->idleAnimationTimeBetweenEachFrame = 0.35;

    //Movement animation
    this->movementTextureRect = new sf::IntRect(0, 0, 26, 21);
    this->movementTextureSource = "images/Animation/SlimeRound/Movement.png";
    this->movementAnimationStep = 26;
    this->movementTextureRectMaxLeft = 78;
    this->movementAnimationTimeBetweenEachFrame = 0.15;

    //Simple attack animation
    this->simpleAttackTextureRect = new sf::IntRect(0, 0, 44, 26);
    this->simpleAttackTextureSource = "images/Animation/SlimeRound/Attack1.png";
    this->simpleAttackAnimationStep = 44;
    this->simpleAttackTextureRectMaxLeft = 264;
    this->simpleAttackAnimationTimeBetweenEachFrame = 0.13;

    //Death animation
    this->deathTextureRect = new sf::IntRect(0, 0, 36, 37);
    this->deathTextureSource = "images/Animation/SlimeRound/Death.png";
    this->deathAnimationStep = 36;
    this->deathTextureRectMaxLeft = 144;
    this->deathAnimationTimeBetweenEachFrame = 0.15;

    this->setTexture(*Entity::resourceManager.searchTexturesList(idleTextureSource));
    this->setTextureRect(*idleTextureRect);
    this->setScale(2., 2.);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -16);


    this->colorOfSkeleton =new sf::Color(this->getColor());
    this->attackConnectsFrame = simpleAttackAnimationStep * 4;
}

SlimeRoundView::~SlimeRoundView()
{
    //dtor
    delete colorOfSkeleton;
}

SlimeRoundView::SlimeRoundView(const SlimeRoundView& other): MonsterEntity(other)
{
    //copy ctor
}

SlimeRoundView& SlimeRoundView::operator=(const SlimeRoundView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


//Method
//###################################################################################################
void SlimeRoundView::receiveDamage(int dmg)
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
        spritePosModifier.x *= this->getScale().x < 0 ? -1 : 1;
        spritePosModifier.y = abs(movementTextureRect->height - deathTextureRect->height) + 10;
        //Apply the position modifiers
        this->setPosition(this->monster->getPosX() - spritePosModifier.x, this->monster->getPosY() - spritePosModifier.y);

    }else
    {
        this->getKnockbacked();
    }
}

