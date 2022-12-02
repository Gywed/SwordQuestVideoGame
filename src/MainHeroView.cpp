#include "MainHeroView.h"
#include <iostream>
#include <thread>


MainHeroView::MainHeroView(MainHero *mainHero)
{
    this->mainHero = mainHero;
    this->setPosition(mainHero->getPosX(), mainHero->getPosY());

    //Idle animation
    this->idleTextureRect = new sf::IntRect(0, 0, Sprite_Width, Sprite_Height);
    this->idleTextureSource = "images/Animation/MainHero/Idle.png";
    this->idleAnimationStep = 45;
    this->idleTextureRectMaxLeft = 135;
    this->idleAnimationTimeBetweenEachFrame = 0.35;

    //Movement animation
    this->movementTextureRect = new sf::IntRect(0, 0, Sprite_Width, Sprite_Height);
    this->movementTextureSource = "images/Animation/MainHero/Movement.png";
    this->movementAnimationStep = 45;
    this->movementTextureRectMaxLeft = 225;
    this->movementAnimationTimeBetweenEachFrame = 0.15;

    //Simple attack animation
    this->simpleAttackTextureRect = new sf::IntRect(0, 0, 71, 63);
    this->simpleAttackTextureSource = "images/Animation/MainHero/Attack1.png";
    this->simpleAttackAnimationStep = 71;
    this->simpleAttackTextureRectMaxLeft = 284;
    this->simpleAttackAnimationTimeBetweenEachFrame = 0.13;

    //Heavy attack animation
    this->heavyAttackTextureRect = new sf::IntRect(0, 0, 102, 62);
    this->heavyAttackTextureSource = "images/Animation/MainHero/Attack2.png";
    this->heavyAttackAnimationStep = 102;
    this->heavyAttackTextureRectMaxLeft = 612;
    this->heavyAttackAnimationTimeBetweenEachFrame = 0.2;

    //Death animation
    this->deathTextureRect = new sf::IntRect(0, 0, 75, 59);
    this->deathTextureSource = "images/Animation/MainHero/Death.png";
    this->deathAnimationStep = 75;
    this->deathTextureRectMaxLeft = 300;
    this->deathAnimationTimeBetweenEachFrame = 0.3;

    this->loadTexture(idleTextureSource);
    this->setTextureRect(*idleTextureRect);
    this->setScale(2., 2.);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -16);

    this->lifebarV = new LifeBarView();
    this->mainHeroColor = new sf::Color(this->getColor());
}

MainHeroView::~MainHeroView()
{
    delete heavyAttackTextureRect;
    delete lifebarV;
}

MainHeroView::MainHeroView(const MainHeroView& other)
{
    //copy ctor
}

MainHeroView& MainHeroView::operator=(const MainHeroView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Setters Getters
MainHero* MainHeroView::getMainHero()const { return mainHero; }
void MainHeroView::setMainHero(MainHero* mainHero) { this->mainHero = mainHero; }
sf::IntRect* MainHeroView::getRectSourceSprite()const { return idleTextureRect; }
void MainHeroView::setRectSourceSprite(sf::IntRect* textureRect)
{
    delete this->idleTextureRect;
    this->idleTextureRect = new sf::IntRect(textureRect->left, textureRect->top, textureRect->width, textureRect->height);
}

//Method
void MainHeroView::spriteEvents(sf::RenderWindow* window)
{
    //Death event
    if(deathFlag)
    {
        //Animation
        setColor(*mainHeroColor);
        updateSpriteDeathAnimation();
    }
    else
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            //The sprite can't move if it's attacking
            if(!attackFlag)
            {
                this->mainHero->setRightClock(std::chrono::high_resolution_clock::now());
                idleFlag=false;
                //symmetry on X axis using setScale so the sprite face the right direction
                this->setScale(2., 2.);

                //Modify the position of the modele and return the value of the movement in the sf::Vector
                this->movement.x += this->mainHero->moveRight();
                this->movement.y += 0.;
                //Manage the boundaries collisions
                if(this->mainHero->getPosX() > window->getSize().x - 64)
                {
                    this->mainHero->setPosX(window->getSize().x - 64);
                    this->movement.x = 0.;
                }

                //Animation
                updateSpriteMovementAnimation();
            }

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(!attackFlag)
            {
                this->mainHero->setUpClock(std::chrono::high_resolution_clock::now());
                idleFlag=false;

                //Modify the position of the modele and return the value of the movement in the sf::Vector
                this->movement.y += this->mainHero->moveUp();
                this->movement.x += 0.;
                //Manage the boundaries collisions
                if(this->mainHero->getPosY() < 192)
                {
                    this->mainHero->setPosY(192);
                    this->movement.y = 0.;
                }
                //Animation
                updateSpriteMovementAnimation();

            }

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(!attackFlag)
            {
                this->mainHero->setLeftClock(std::chrono::high_resolution_clock::now());
                idleFlag=false;
                //symmetry on X axis using setScale so the sprite face the right direction
                this->setScale(-2., 2.);
                //Modify the position of the modele and return the value of the movement in the sf::Vector
                this->movement.x += this->mainHero->moveLeft();
                this->movement.y += 0.;
                //Manage the boundaries collisions
                if(this->mainHero->getPosX() < 64.)
                {
                    this->mainHero->setPosX(64);
                    this->movement.x = 0.;
                }
                //Animation
                updateSpriteMovementAnimation();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(!attackFlag)
            {
                this->mainHero->setDownClock(std::chrono::high_resolution_clock::now());
                idleFlag=false;
                //Modify the position of the modele and return the value of the movement in the sf::Vector
                this->movement.y += this->mainHero->moveDown();
                this->movement.x += 0.;
                //Manage the boundaries collisions
                if(this->mainHero->getPosY() > window->getSize().y - 112)
                {
                    this->mainHero->setPosY(window->getSize().y - 112);
                    this->movement.y = 0.;
                }
                //Animation
                updateSpriteMovementAnimation();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //Sprite can't initiate an attack if it's already attacking
            if(!attackFlag)
            {
                if(simpleAttackCoolDownTimer.getElapsedTime().asSeconds() > 0.8f)
                {
                    //Stop the idle animation
                    idleFlag=false;
                    //Enable attack
                    attackFlag=true;
                    //Notify the type of attack
                    simpleAttackFlag=true;
                    //Adapt texture rect to the texture dimensions of Attack1.png
                    this->setTextureRect(*simpleAttackTextureRect);
                    //determine the value of the position modifier for the attack because of the texture size differences
                    if(this->getScale().x < 0)
                        spritePosModifier.x = -26;
                    else
                        spritePosModifier.x = 26;
                    spritePosModifier.y = 31;
                    //Apply the position modifiers
                    this->setPosition(this->mainHero->getPosX() - spritePosModifier.x, this->mainHero->getPosY() - spritePosModifier.y);

                    //Attack method
                    attack();
                    simpleAttackCoolDownTimer.restart();
                }

            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            //Sprite can't initiate an attack if it's already attacking
            if(!attackFlag)
            {
                if(heavyAttackCoolDownTimer.getElapsedTime().asSeconds() > 2.f)
                {
                    //Stop the idle animation
                    idleFlag=false;
                    //Enable attack
                    attackFlag=true;
                    //Notify the type of attack
                    heavyAttackFlag=true;
                    //Adapt texture rect to the texture dimensions of Attack1.png
                    this->setTextureRect(*heavyAttackTextureRect);
                    //determine the value of the position modifier for the attack because of the texture size differences
                    if(this->getScale().x < 0)
                        spritePosModifier.x = -45;
                    else
                        spritePosModifier.x = 45;
                    spritePosModifier.y = 25;
                    //Apply the position modifiers
                    this->setPosition(this->mainHero->getPosX() - spritePosModifier.x, this->mainHero->getPosY() - spritePosModifier.y);

                    //Attack method
                    attack();
                    heavyAttackCoolDownTimer.restart();
                }

            }
        }

        //Temporary event to test the death event
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            idleFlag=false;
            attackFlag=false;
            deathFlag=true;

            this->setTextureRect(*deathTextureRect);
            //determine the value of the position modifier for the attack because of the texture size differences
            if(this->getScale().x < 0)
                spritePosModifier.x = -30;
            else
                spritePosModifier.x = 30;
            spritePosModifier.y = 27;
            //Apply the position modifiers
            this->setPosition(this->mainHero->getPosX() - spritePosModifier.x, this->mainHero->getPosY() - spritePosModifier.y);
        }
        //Temporary event to test the getDamaged event
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            getDamaged(1);
        }

        if(this->mainHero->isAttackable())
        {
            this->setColor(*this->mainHeroColor);
        }


        //Verifying events
        sf::Event ev;
        while (window->pollEvent(ev))
        {

            // If a key is released
            if (ev.type == sf::Event::KeyReleased)
            {
                switch (ev.key.code)
                {
                    // Process the up, down, left and right keys
                    case sf::Keyboard::Up :
                        //Can't return to default state if it's attacking
                        if(!attackFlag)
                        {
                            idleFlag=true;
                            idleTextureRect->left=0;
                            movementTextureRect->left=0;
                            break;
                        }
                    case sf::Keyboard::Down:
                        if(!attackFlag)
                        {
                            idleFlag=true;
                            idleTextureRect->left=0;
                            movementTextureRect->left=0;
                            break;
                        }
                    case sf::Keyboard::Left:
                        if(!attackFlag)
                        {
                            idleFlag=true;
                            idleTextureRect->left=0;
                            movementTextureRect->left=0;
                            break;
                        }
                    case sf::Keyboard::Right:
                        if(!attackFlag)
                        {
                            idleFlag=true;
                            idleTextureRect->left=0;
                            movementTextureRect->left=0;
                            break;
                        }

                    default : break;
                }
                this->setTextureRect(*idleTextureRect);

            }
        }

        //Apply the modification done to the movement attribute (Entity)
        this->updatePosition();

        //Action if the sprite is in idle state
        if(idleFlag)
            updateSpriteIdleAnimation();

        //Actions if the sprite is attacking
        if(attackFlag)
        {
            //Animation
            if(simpleAttackFlag)
                updateSpriteSimpleAttackAnimation();
            else
                updateSpriteHeavyAttackAnimation();
            //Check if the animation is finished
            if(!attackFlag)
            {
                //Put back the correct position to match the model
                this->setPosition(this->mainHero->getPosX(), this->mainHero->getPosY());
                //Adapt textureRect to the dimensions of Idle.png and Movement.png
                this->idleTextureRect->left=0;
		this->movementTextureRect->left=0;
                this->setTextureRect(*idleTextureRect);
                //Enable idle state
                idleFlag=true;
            }
        }
    }
}

void MainHeroView::attack()
{
    //Attack from model will be called here
    //Instruction for the view to manage collision with a monster
}

void MainHeroView::updateSpriteSimpleAttackAnimation()
{
    this->loadTexture("images/Animation/MainHero/Attack1.png");
    this->setTextureRect(*simpleAttackTextureRect);
    if (animationTimer.getElapsedTime().asSeconds() > 0.13f){

        if (simpleAttackTextureRect->left == 284)
        {
            simpleAttackTextureRect->left=0;
            //When we reach the end of Attack1.png sprite sheet, we notify the end of the attack
            attackFlag=false;
            simpleAttackFlag=false;
        }
        else
            simpleAttackTextureRect->left+=71;

        this->setTextureRect(*simpleAttackTextureRect);
        animationTimer.restart();
    }
}

void MainHeroView::updateSpriteHeavyAttackAnimation()
{
    this->loadTexture("images/Animation/MainHero/Attack2.png");
    this->setTextureRect(*heavyAttackTextureRect);
    if (animationTimer.getElapsedTime().asSeconds() > 0.20f){
        if (heavyAttackTextureRect->left == 612)
        {
            heavyAttackTextureRect->left=0;
            //When we reach the end of Attack1.png sprite sheet, we notify the end of the attack
            attackFlag=false;
            heavyAttackFlag=false;
        }
        else
            heavyAttackTextureRect->left+=102;

        this->setTextureRect(*heavyAttackTextureRect);
        animationTimer.restart();
    }
}

void MainHeroView::getDamaged(int dmg)
{
    this->mainHero->getDamaged(dmg);
    int hp = this->mainHero->getHP();
    this->setColor(sf::Color::Red);
    if(hp==0)
    {
        idleFlag=false;
        attackFlag=false;
        deathFlag=true;

        this->setTextureRect(*deathTextureRect);
        //determine the value of the position modifier for the attack because of the texture size differences
        if(this->getScale().x < 0)
            spritePosModifier.x = -30;
        else
            spritePosModifier.x = 30;
        spritePosModifier.y = 27;
        //Apply the position modifiers
        this->setPosition(this->mainHero->getPosX() - spritePosModifier.x, this->mainHero->getPosY() - spritePosModifier.y);
    }

    this->lifebarV->getDamaged(hp);


}

LifeBarView* MainHeroView::getLifeBarView()const{
    return this->lifebarV;
}
