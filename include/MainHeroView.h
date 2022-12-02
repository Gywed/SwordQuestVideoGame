#ifndef MainHeroVIEW_H
#define MainHeroVIEW_H
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
#include "MainHero.h"
#include "Entity.h"
#include "LifeBarView.h"


class MainHeroView: public Entity
{
    private:
        MainHero* mainHero;
        LifeBarView* lifebarV;

        sf::Clock heavyAttackCoolDownTimer;

        //Heavy attack animation
        sf::IntRect* heavyAttackTextureRect;
        string heavyAttackTextureSource;
        int heavyAttackAnimationStep;
        int heavyAttackTextureRectMaxLeft;
        float heavyAttackAnimationTimeBetweenEachFrame;

        bool heavyAttackFlag= false, simpleAttackFlag = false;

        sf::Color* mainHeroColor;

    public:
        MainHeroView(MainHero *character);
        virtual ~MainHeroView();
        MainHeroView(const MainHeroView& other);
        MainHeroView& operator=(const MainHeroView& other);

        //Setters Getters
        MainHero* getMainHero()const;
        void setMainHero(MainHero* mainHero);
        sf::IntRect* getRectSourceSprite()const;
        void setRectSourceSprite(sf::IntRect* rectSourceSprite);
        LifeBarView* getLifeBarView()const;

        //Method
        void spriteEvents(sf::RenderWindow* window);
        void attack();
        void getDamaged(int dmg);

        //Animation
        void updateSpriteMovementAnimation();
        void updateSpriteIdleAnimation();
        void updateSpriteSimpleAttackAnimation();
        void updateSpriteHeavyAttackAnimation();
        void updateSpriteDeathAnimation();



};

#endif // MainHeroVIEW_H
