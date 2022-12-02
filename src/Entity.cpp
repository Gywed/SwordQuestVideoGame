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
