#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    this->texture = new sf::Texture();
    this->last_frame = clock.getElapsedTime().asSeconds();
}

Entity::~Entity()
{
    //dtor
}

Entity::Entity(const Entity& other)
{
    delete texture;
}

Entity& Entity::operator=(const Entity& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

sf::Vector2f Entity::getMovement() const { return movement; }
sf::Texture* Entity::getTexture() const { return texture; }
void Entity::setMovement(const sf::Vector2f movement) { this->movement = movement; }

/* Method */
void Entity::loadTexture(const string filename)
{
    if (!texture->loadFromFile(filename))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
    texture->setSmooth(true);
    this->setTexture(*this->texture);
}

void Entity::updatePosition()
{
    this->move(this->movement);
    this->movement.x=0.;
    this->movement.y=0.;
}

bool Entity::getDeathFlag()const
{
    return this->deathFlag;
}

bool Entity::getDeadFlag()const
{
    return this->deadFlag;
}

void Entity::setDeadFlag(bool newDeadFlag)
{
    this->deadFlag = newDeadFlag;
}

//Animation
//###################################################################################################
void Entity::updateSpriteIdleAnimation()
{
    this->loadTexture(idleTextureSource);
    //Shift textureRect every time given
    if (animationTimer.getElapsedTime().asSeconds() > idleAnimationTimeBetweenEachFrame){

        if (idleTextureRect->left == idleTextureRectMaxLeft)
            idleTextureRect->left=0;
        else
            idleTextureRect->left+=idleAnimationStep;

        this->setTextureRect(*idleTextureRect);
        animationTimer.restart();
    }
}

void Entity::updateSpriteMovementAnimation()
{
    this->loadTexture(movementTextureSource);
    this->setTextureRect(*movementTextureRect);
    //Shift textureRect every time given
    if (animationTimer.getElapsedTime().asSeconds() > movementAnimationTimeBetweenEachFrame){

        if (movementTextureRect->left == movementTextureRectMaxLeft)
            movementTextureRect->left=0;
        else
            movementTextureRect->left+=movementAnimationStep;

        this->setTextureRect(*movementTextureRect);
        animationTimer.restart();
    }
}

void Entity::updateSpriteSimpleAttackAnimation()
{
    this->loadTexture(simpleAttackTextureSource);
    this->setTextureRect(*simpleAttackTextureRect);
    if (animationTimer.getElapsedTime().asSeconds() > simpleAttackAnimationTimeBetweenEachFrame){

        if (simpleAttackTextureRect->left == simpleAttackTextureRectMaxLeft)
        {
            simpleAttackTextureRect->left=0;
            //When we reach the end of Attack1.png sprite sheet, we notify the end of the attack
            attackFlag=false;
        }
        else
            simpleAttackTextureRect->left+=simpleAttackAnimationStep;

        this->setTextureRect(*simpleAttackTextureRect);
        animationTimer.restart();
    }
}

void Entity::updateSpriteDeathAnimation()
{
    this->loadTexture(deathTextureSource);
    this->setTextureRect(*deathTextureRect);
    if (animationTimer.getElapsedTime().asSeconds() > deathAnimationTimeBetweenEachFrame){

        if (deathTextureRect->left == deathTextureRectMaxLeft)
        {
            //When we reach the end of Death.png sprite sheet, we notify the end of the death animation
            deathFlag=false;
            deadFlag = true;
        }
        else
            deathTextureRect->left+=deathAnimationStep;

        this->setTextureRect(*deathTextureRect);
        animationTimer.restart();
    }
}
