#ifndef ENTITY_H
#define ENTITY_H
#include "SFML/Graphics.hpp"
#include <string>
#include <ctime>

using std::string;

class Entity: public sf::Sprite
{
    protected:
        // Movement (offset) of the entity
        sf::Vector2f movement;
        sf::Clock clock;
        float last_frame;

        // Texture of the entity
        sf::Texture* texture;

        //Idle animation
        sf::IntRect* idleTextureRect;
        string idleTextureSource;
        int idleAnimationStep;
        int idleTextureRectMaxLeft;
        float idleAnimationTimeBetweenEachFrame;

        //Movement animation
        sf::IntRect* movementTextureRect;
        string movementTextureSource;
        int movementAnimationStep;
        int movementTextureRectMaxLeft;
        float movementAnimationTimeBetweenEachFrame;

        //Simple attack animation
        sf::IntRect* simpleAttackTextureRect;
        string simpleAttackTextureSource;
        int simpleAttackAnimationStep;
        int simpleAttackTextureRectMaxLeft;
        float simpleAttackAnimationTimeBetweenEachFrame;

        //Death animation
        sf::IntRect* deathTextureRect;
        string deathTextureSource;
        int deathAnimationStep;
        int deathTextureRectMaxLeft;
        float deathAnimationTimeBetweenEachFrame;

        sf::Clock animationTimer;
        sf::Clock simpleAttackCoolDownTimer;


        bool idleFlag = true, attackFlag=false, deathFlag = false, deadFlag = false;

        sf::Vector2<int> spritePosModifier;

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
        void updatePosition();
        bool getDeathFlag()const;
        bool getDeadFlag()const;
        void setDeadFlag(bool newDeadFlag);

        //Animation
        virtual void updateSpriteMovementAnimation();
        virtual void updateSpriteIdleAnimation();
        virtual void updateSpriteSimpleAttackAnimation();
        virtual void updateSpriteDeathAnimation();






};

#endif // ENTITY_H
