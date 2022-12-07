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
#include "model/MainHero.h"
#include "view/Entity.h"
#include "view/LifeBarView.h"
#include "model/Observable.h"


class MainHeroView: public Entity, public Observable
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

        // Score
        int score = 0;

        bool heavyAttackFlag= false, simpleAttackFlag = false;

        bool upKey, downKey, leftKey, rightKey;

        sf::Color* mainHeroColor;

    public:
        MainHeroView(float posX, float posY);
        virtual ~MainHeroView();
        MainHeroView(const MainHeroView& other);
        MainHeroView& operator=(const MainHeroView& other);

        //Setters Getters
        MainHero* getMainHero()const;
        void setMainHero(MainHero* mainHero);
        sf::IntRect* getRectSourceSprite()const;
        void setRectSourceSprite(sf::IntRect* rectSourceSprite);
        LifeBarView* getLifeBarView()const;
        void increaseScore(int increaseValue);
        int getScore()const;
        bool getHeavyAttackFlag()const;

        //Method
        void spriteEvents(sf::RenderWindow* window);
        void attack();
        void receiveDamage(int dmg);
        void getHealed(int heal);

        //Animation
        void updateSpriteSimpleAttackAnimation();
        void updateSpriteHeavyAttackAnimation();



};

#endif // MainHeroVIEW_H
