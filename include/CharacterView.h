#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H
// Size of Sprite
#define Sprite_Width 45
#define Sprite_Height 47

// Define not moving sprite for each position
#define Sprite_Right 312
#define Sprite_Left 104
#define Sprite_Back 208
#define Sprite_Front 0

// Define moving sprite for each position
#define Sprite_Right_Moving 728
#define Sprite_Left_Moving 520
#define Sprite_Back_Moving 624
#define Sprite_Front_Moving 416
#define Sprite_Changing_Step 96
#define Sprite_Changing_Left_Max 864

#include "SFML/Graphics.hpp"
#include "Character.h"
#include "Entity.h"


class CharacterView: public Entity
{
    private:
        Character* character;

        sf::IntRect* rectSourceSprite;
        sf::Clock timer;

        bool idleFlag = true, attackFlag=false;
        bool upKey,downKey, leftKey, rightKey;

        int spritePosXModifierWhenAttacking;
        int spritePosYModifierWhenAttacking = 31;

    public:
        CharacterView(Character *character);
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& other);

        //Setters Getters
        Character* getCharacter()const;
        void setCharacter(Character* Character);
        sf::IntRect* getRectSourceSprite()const;
        void setRectSourceSprite(sf::IntRect* rectSourceSprite);

        //Method
        void spriteEvents(sf::RenderWindow* window);
        void attack();
        void updateSpriteMovementAnimation();
        void updateSpriteIdleAnimation();
        void updateSpriteSimpleAttackAnimation();


};

#endif // CHARACTERVIEW_H
