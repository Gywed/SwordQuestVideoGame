#ifndef ENTITY_H
#define ENTITY_H
#include "SFML/Graphics.hpp"


class Entity: public sf::Sprite
{
    private:
        // Movement (offset) of the entity
        sf::Vector2f movement;
        // Texture of the entity
        sf::Texture* texture;

    public:
        Entity();
        virtual ~Entity();
        Entity(const Entity& other);
        Entity& operator=(const Entity& other);

        /* Getters and setters */
        sf::Vector2f getMovement() const;
        sf::Texture* getTexture() const;
        void setMovement(const sf::Vector2f movement);

        /* Method */
        void loadTexture(const string filename);
        virtual void updatePosition();



    protected:


};

#endif // ENTITY_H
