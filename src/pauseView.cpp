#include "pauseView.h"


pauseView::pauseView(sf::RenderWindow* window):window(window)
{
    //ctor
    spriteBackground = new sf::Sprite;
    spriteBackground->setTextureRect(sf::IntRect(0,0,this->window->getSize().x,this->window->getSize().y));
    sf::Texture texture;
    texture.loadFromFile("images/WhiteBG.png");
    spriteBackground->setTexture(texture);
    spriteBackground->setColor(sf::Color(0,0,0,150));

//    sf::Font font;
//    font.loadFromFile("Fonts/Typography.otf");
//    sf::Text* text = new sf::Text();
//    text->setFont(font);
//    text->setString("test");

}

pauseView::~pauseView()
{
    //dtor
    delete spriteBackground;
}

pauseView::pauseView(const pauseView& other)
{
    //copy ctor
    this->window = other.window;
    this->spriteBackground->setTextureRect(other.spriteBackground->getTextureRect());
    this->spriteBackground->setColor(other.spriteBackground->getColor());

}

pauseView& pauseView::operator=(const pauseView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void pauseView::render()
{
    window->draw(*spriteBackground);
//    spriteRectPauseMenu->setTextureRect(sf::IntRect())
}

sf::Sprite* pauseView::getSpriteBackground() const
{
    return this->spriteBackground;
}





