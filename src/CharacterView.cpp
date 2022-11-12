#include "CharacterView.h"

CharacterView::CharacterView(Character *character)
{
    this->character = character;
    this->setPosition(character->getPosX(), character->getPosY());
    this->loadTexture("images/SpriteSheet.png");
    this->rectSourceSprite = new sf::IntRect(0, 0, Sprite_Width, Sprite_Height);
    this->setTextureRect(*rectSourceSprite);
    this->setScale(.8, .8);
    this->setOrigin(this->getGlobalBounds().width/2., this->getGlobalBounds().height/2.);
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
            this->movement.x = this->character->moveRight();
            this->movement.y = 0;
            if(this->character->getPosX() > window->getSize().x)
            {
                this->character->setPosX(window->getSize().x);
                this->movement.x = 0;
            }
            startSpriteMovementAnimation(Sprite_Right_Moving);

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            this->movement.y = this->character->moveUp();
            this->movement.x = 0;
            if(this->character->getPosY() < 0)
            {
                this->character->setPosY(0);
                this->movement.y = 0;
            }
            startSpriteMovementAnimation(Sprite_Back_Moving);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            this->movement.x = this->character->moveLeft();
            this->movement.y = 0;
            if(this->character->getPosX() < 0)
            {
                this->character->setPosX(0);
                this->movement.x = 0;
            }
            startSpriteMovementAnimation(Sprite_Left_Moving);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            this->movement.y = this->character->moveDown();
            this->movement.x = 0;
            if(this->character->getPosY() > window->getSize().y)
            {
                this->character->setPosY(window->getSize().y);
                this->movement.y = 0;
            }
            startSpriteMovementAnimation(Sprite_Front_Moving);

        }

        //Verifying events
        sf::Event ev;
		while (window->pollEvent(ev))
		{
			// Window closed
			if (ev.type == sf::Event::Closed)
			{
			    window->close();
			}
			//Key pressed
			if (ev.type == sf::Event::KeyPressed)
			{
				switch (ev.key.code)
                {
                // If escape is pressed, close the application
                case  sf::Keyboard::Escape :  window->close();break;


                default : break;
                }
			}
			// If a key is released
            if (ev.type == sf::Event::KeyReleased)
            {
                switch (ev.key.code)
                {
                // Process the up, down, left and right keys
                case sf::Keyboard::Up :     rectSourceSprite->left=0;rectSourceSprite->top=Sprite_Back; break;
                case sf::Keyboard::Down:    rectSourceSprite->left=0;rectSourceSprite->top=Sprite_Front; break;
                case sf::Keyboard::Left:    rectSourceSprite->left=0;rectSourceSprite->top=Sprite_Left;break;
                case sf::Keyboard::Right:   rectSourceSprite->left=0;rectSourceSprite->top=Sprite_Right;break;
                default : break;
                }
                this->setTextureRect(*rectSourceSprite);
                this->movement.x=0;
                this->movement.y=0;
            }
		}

        this->updatePosition();
}

void CharacterView::startSpriteMovementAnimation(int startingSpriteTop)
{
    rectSourceSprite->top = startingSpriteTop;
    if (timer.getElapsedTime().asSeconds() > 0.09f){

        if (rectSourceSprite->left == Sprite_Changing_Left_Max)
            rectSourceSprite->left=0;
        else
            rectSourceSprite->left+=Sprite_Changing_Step;

        this->setTextureRect(*rectSourceSprite);
        timer.restart();
    }

}
