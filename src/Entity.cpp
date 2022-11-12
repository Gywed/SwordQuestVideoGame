#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    this->texture = new sf::Texture();
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
}
