#include "CharacterView.h"

CharacterView::CharacterView(Character *character)
{
    this->character = character;
    this->setPosition(character->getPosX(), character->getPosY());
    this->loadTexture("images/SpriteSheet.png");
    this->rectSourceSprite = new sf::IntRect(0, 0, Sprite_Width, Sprite_Height);
    this->setTextureRect(rectSourceSprite);
    this->setScale(.8, .8);
    this.setOrigin(this->getGlobalBounds().width/2., this->getGlobalBounds().height/2.);
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
Character* CharacterView::getCharacter()const;
void CharacterView::setCharacter(int *Character);
sf::IntRect* CharacterView::getRectSourceSprite()const;
void CharacterView::setRectSourceSprite(sf::IntRect* rectSourceSprite);

//Method
void CharacterView::moveAnyDirection(sf::RenderWindow* window);
