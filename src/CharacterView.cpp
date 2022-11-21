#include "CharacterView.h"
#include <iostream>
CharacterView::CharacterView(Character *character)
{
    this->character = character;
    this->setPosition(character->getPosX(), character->getPosY());
    this->loadTexture("images/Animation/MainHero/Idle.png");
    this->defaultTextureRect = new sf::IntRect(0, 0, Sprite_Width, Sprite_Height);
    this->simpleAttackTextureRect = new sf::IntRect(0, 0, 71, 63);
    this->heavyAttackTextureRect = new sf::IntRect(0, 0, 102, 62);
    this->deathTextureRect = new sf::IntRect(0, 0, 75, 59);
    this->setTextureRect(*defaultTextureRect);
    this->setScale(2., 2.);
    this->getTexture()->setSmooth(true);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -16);
}

CharacterView::~CharacterView()
{
    delete defaultTextureRect;
    delete simpleAttackTextureRect;
    delete heavyAttackTextureRect;
    delete deathTextureRect;
}

CharacterView::CharacterView(const CharacterView& other)
{
    //copy ctor
}

CharacterView& CharacterView::operator=(const CharacterView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Setters Getters
Character* CharacterView::getCharacter()const { return character; }
void CharacterView::setCharacter(Character* character) { this->character = character; }
sf::IntRect* CharacterView::getRectSourceSprite()const { return defaultTextureRect; }
void CharacterView::setRectSourceSprite(sf::IntRect* textureRect)
{
    delete this->defaultTextureRect;
    this->defaultTextureRect = new sf::IntRect(textureRect->left, textureRect->top, textureRect->width, textureRect->height);
}

//Method
void CharacterView::spriteEvents(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        //The sprite can't move if it's attacking
        if(!attackFlag)
        {
            idleFlag=false;
            //symmetry on X axis using setScale so the sprite face the right direction
            this->setScale(2., 2.);

            //Modify the position of the modele and return the value of the movement in the sf::Vector
            this->movement.x += this->character->moveRight();
            this->movement.y += 0.;
            //Manage the boundaries collisions
            if(this->character->getPosX() > window->getSize().x - 64)
            {
                this->character->setPosX(window->getSize().x - 64);
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
            idleFlag=false;

            //Modify the position of the modele and return the value of the movement in the sf::Vector
            this->movement.y += this->character->moveUp();
            this->movement.x += 0.;
            //Manage the boundaries collisions
            if(this->character->getPosY() < 192)
            {
                this->character->setPosY(192);
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
            idleFlag=false;
            //symmetry on X axis using setScale so the sprite face the right direction
            this->setScale(-2., 2.);
            //Modify the position of the modele and return the value of the movement in the sf::Vector
            this->movement.x += this->character->moveLeft();
            this->movement.y += 0.;
            //Manage the boundaries collisions
            if(this->character->getPosX() < 64.)
            {
                this->character->setPosX(64);
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
            idleFlag=false;
            //Modify the position of the modele and return the value of the movement in the sf::Vector
            this->movement.y += this->character->moveDown();
            this->movement.x += 0.;
            //Manage the boundaries collisions
            if(this->character->getPosY() > window->getSize().y - 112)
            {
                this->character->setPosY(window->getSize().y - 112);
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
            if(simpleAttackCoolDownTimer.getElapsedTime().asSeconds() > 0.5f)
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
                    spritePosXModifierWhenAttacking = -26;
                else
                    spritePosXModifierWhenAttacking = 26;
                spritePosYModifierWhenAttacking = 31;
                //Apply the position modifiers
                this->setPosition(this->character->getPosX() - spritePosXModifierWhenAttacking, this->character->getPosY() - spritePosYModifierWhenAttacking);

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
                    spritePosXModifierWhenAttacking = -45;
                else
                    spritePosXModifierWhenAttacking = 45;
                spritePosYModifierWhenAttacking = 25;
                //Apply the position modifiers
                this->setPosition(this->character->getPosX() - spritePosXModifierWhenAttacking, this->character->getPosY() - spritePosYModifierWhenAttacking);

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
            spritePosXModifierWhenAttacking = -30;
        else
            spritePosXModifierWhenAttacking = 30;
        spritePosYModifierWhenAttacking = 27;
        //Apply the position modifiers
        this->setPosition(this->character->getPosX() - spritePosXModifierWhenAttacking, this->character->getPosY() - spritePosYModifierWhenAttacking);
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
                        defaultTextureRect->left=0;
                        break;
                    }
                case sf::Keyboard::Down:
                    if(!attackFlag)
                    {
                        idleFlag=true;
                        defaultTextureRect->left=0;
                        break;
                    }
                case sf::Keyboard::Left:
                    if(!attackFlag)
                    {
                        idleFlag=true;
                        defaultTextureRect->left=0;
                        break;
                    }
                case sf::Keyboard::Right:
                    if(!attackFlag)
                    {
                        idleFlag=true;
                        defaultTextureRect->left=0;
                        break;
                    }
                default : break;
            }
            this->setTextureRect(*defaultTextureRect);

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
            this->setPosition(this->character->getPosX(), this->character->getPosY());
            //Adapt textureRect to the dimensions of Idle.png and Movement.png
            this->defaultTextureRect->left=0;
            this->setTextureRect(*defaultTextureRect);
            //Enable idle state
            idleFlag=true;
        }
    }

    //Death event
    if(deathFlag)
    {
        //Animation
        updateSpriteDeathAnimation();
    }
}

void CharacterView::attack()
{
    //Attack from model will be called here
    //Instruction for the view to manage collision with a monster
}

void CharacterView::updateSpriteMovementAnimation()
{
    this->loadTexture("images/Animation/MainHero/Movement.png");
    //Shift textureRect every time given
    if (timer.getElapsedTime().asSeconds() > 0.15f){

        if (defaultTextureRect->left == 225)
            defaultTextureRect->left=0;
        else
            defaultTextureRect->left+=45;

        this->setTextureRect(*defaultTextureRect);
        timer.restart();
    }

}

void CharacterView::updateSpriteIdleAnimation()
{
    this->loadTexture("images/Animation/MainHero/Idle.png");
    //Shift textureRect every time given
    if (timer.getElapsedTime().asSeconds() > 0.35f){

        if (defaultTextureRect->left == 135)
            defaultTextureRect->left=0;
        else
            defaultTextureRect->left+=45;

        this->setTextureRect(*defaultTextureRect);
        timer.restart();
    }

}

void CharacterView::updateSpriteSimpleAttackAnimation()
{
    this->loadTexture("images/Animation/MainHero/Attack1.png");
    this->setTextureRect(*simpleAttackTextureRect);
    if (timer.getElapsedTime().asSeconds() > 0.13f){

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
        timer.restart();
    }
}

void CharacterView::updateSpriteHeavyAttackAnimation()
{
    this->loadTexture("images/Animation/MainHero/Attack2.png");
    this->setTextureRect(*heavyAttackTextureRect);
    if (timer.getElapsedTime().asSeconds() > 0.20f){
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
        timer.restart();
    }
}

void CharacterView::updateSpriteDeathAnimation()
{
    this->loadTexture("images/Animation/MainHero/Death.png");
    if (timer.getElapsedTime().asSeconds() > 0.3f){

        if (deathTextureRect->left == 300)
        {
            //When we reach the end of Death.png sprite sheet, we notify the end of the death animation
            deathFlag=false;
        }
        else
            deathTextureRect->left+=75;

        this->setTextureRect(*deathTextureRect);
        timer.restart();
    }
}


