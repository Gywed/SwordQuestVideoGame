#include "view/SkeletonView.h"

SkeletonView::SkeletonView(Skeleton* skeleton): MonsterEntity(skeleton)
{
    this->setPosition(skeleton->getPosX(), skeleton->getPosY());

    //Idle animation
    this->idleTextureRect = new sf::IntRect(0, 0, 32, 40);
    this->idleTextureSource = "images/Animation/Skeleton/Idle.png";
    this->idleAnimationStep = 32;
    this->idleTextureRectMaxLeft = 96;
    this->idleAnimationTimeBetweenEachFrame = 0.3;

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
    this->deathAnimationTimeBetweenEachFrame = 0.15;

    this->setTexture(*Entity::resourceManager.searchTexturesList(idleTextureSource));
    this->setTextureRect(*idleTextureRect);
    this->setScale(2., 2.);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -15);


    this->colorOfSkeleton =new sf::Color(this->getColor());
    this->attackConnectsFrame = simpleAttackAnimationStep * 3;
}

SkeletonView::~SkeletonView()
{
    //dtor
    delete colorOfSkeleton;
}

SkeletonView::SkeletonView(const SkeletonView& other): MonsterEntity(other)
{
    //copy ctor
}

SkeletonView& SkeletonView::operator=(const SkeletonView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


//Method
//###################################################################################################
void SkeletonView::receiveDamage(int dmg)
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
        spritePosModifier.y = abs(movementTextureRect->height - deathTextureRect->height) + 15;
        //Apply the position modifiers
        this->setPosition(this->monster->getPosX() - spritePosModifier.x, this->monster->getPosY() - spritePosModifier.y);

    }else
    {
        this->getKnockbacked();
    }
}

