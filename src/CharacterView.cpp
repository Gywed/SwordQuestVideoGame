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

}

void CharacterView::startSpriteMovementAnimation(int startingSpriteTop)
{
    rectSourceSprite->top = startingSpriteTop;
    if (timer.getElapsedTime().asSeconds() > 0.09f){

        if (rectSourceSprite->left == Sprite_Changing_Left_Max)
            rectSourceSprite->left=0;
        else
            rectSourceSprite.left+=Sprite_Changing_Step;

        sprite.setTextureRect(rectSourceSprite);
        timer.restart();
    }

}
