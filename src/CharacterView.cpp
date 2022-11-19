#include "CharacterView.h"
#include <iostream>
CharacterView::CharacterView(Character *character)
{
    this->character = character;
    this->setPosition(character->getPosX(), character->getPosY());
    this->loadTexture("images/Animation/MainHero/Idle.png");
    this->rectSourceSprite = new sf::IntRect(0, 0, Sprite_Width, Sprite_Height);
    this->setTextureRect(*rectSourceSprite);
    this->setScale(2., 2.);
    this->getTexture()->setSmooth(true);
    this->setOrigin(this->getLocalBounds().width/2., this->getGlobalBounds().height/2. -16);
}

CharacterView::~CharacterView()
{
    delete rectSourceSprite;
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
sf::IntRect* CharacterView::getRectSourceSprite()const { return rectSourceSprite; }
void CharacterView::setRectSourceSprite(sf::IntRect* rectSourceSprite)
{
    delete this->rectSourceSprite;
    this->rectSourceSprite = new sf::IntRect(rectSourceSprite->left, rectSourceSprite->top, rectSourceSprite->width, rectSourceSprite->height);
}

//Method
void CharacterView::moveAnyDirection(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            idleFlag=false;
            this->setScale(2., 2.);

            this->movement.x += this->character->moveRight();
            this->movement.y += 0.;
            if(this->character->getPosX() > window->getSize().x - 64)
            {
                this->character->setPosX(window->getSize().x - 64);
                this->movement.x = 0.;
            }
            startSpriteMovementAnimation();

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            idleFlag=false;
            this->movement.y += this->character->moveUp();
            this->movement.x += 0.;
            if(this->character->getPosY() < 192)
            {
                this->character->setPosY(192);
                this->movement.y = 0.;
            }
            startSpriteMovementAnimation();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            idleFlag=false;
            this->setScale(-2., 2.);
            this->movement.x += this->character->moveLeft();
            this->movement.y += 0.;
            if(this->character->getPosX() < 64.)
            {
                this->character->setPosX(64);
                this->movement.x = 0.;
            }
            startSpriteMovementAnimation();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            idleFlag=false;

            this->movement.y += this->character->moveDown();
            this->movement.x += 0.;
            if(this->character->getPosY() > window->getSize().y - 112)
            {
                this->rectSourceSprite->top += this->movement.y;
                this->character->setPosY(window->getSize().y - 112);
                this->movement.y = 0.;
            }
            startSpriteMovementAnimation();

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
                case sf::Keyboard::Up :     idleFlag=true; rectSourceSprite->left=0; break;
                case sf::Keyboard::Down:    idleFlag=true; rectSourceSprite->left=0; break;
                case sf::Keyboard::Left:    idleFlag=true; rectSourceSprite->left=0; break;
                case sf::Keyboard::Right:   idleFlag=true; rectSourceSprite->left=0; break;
                default : break;
                }
                this->setTextureRect(*rectSourceSprite);

            }
		}

        this->updatePosition();

        if(idleFlag)
            startSpriteIdleAnimation();
}

void CharacterView::startSpriteMovementAnimation()
{
    this->loadTexture("images/Animation/MainHero/Movement.png");
    if (timer.getElapsedTime().asSeconds() > 0.15f){

        if (rectSourceSprite->left == 225)
            rectSourceSprite->left=0;
        else
            rectSourceSprite->left+=45;

        this->setTextureRect(*rectSourceSprite);
        timer.restart();
    }

}

void CharacterView::startSpriteIdleAnimation()
{
    this->loadTexture("images/Animation/MainHero/Idle.png");
    if (timer.getElapsedTime().asSeconds() > 0.35f){

        if (rectSourceSprite->left == 135)
            rectSourceSprite->left=0;
        else
            rectSourceSprite->left+=45;

        this->setTextureRect(*rectSourceSprite);
        timer.restart();
    }
}
