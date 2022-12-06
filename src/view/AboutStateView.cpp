#include "view/AboutStateView.h"
#include <iostream>

AboutStateView::AboutStateView(GameManagerView* gm)
{
    this->gm = gm;
}

AboutStateView::~AboutStateView()
{
    //dtor
}

AboutStateView::AboutStateView(const AboutStateView& other)
{
    //copy ctor
}

AboutStateView& AboutStateView::operator=(const AboutStateView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/* Method (DP "State") */
void AboutStateView::init(sf::RenderWindow* window)
{
    if(!font.loadFromFile("Fonts/Berlin_Sans_FB_Demi_Bold.ttf")){
        std::cout << "No Font is here";
    }

    credits[0].setString("Alexandre Dujacquier");
    credits[0].setOutlineColor(sf::Color(sf::Color::Black));
    credits[0].setOutlineThickness(7.);
    credits[0].setCharacterSize(70);
    credits[0].setPosition(700,175);

    credits[1].setString("Yohan Noel-Huls");
    credits[1].setOutlineColor(sf::Color(sf::Color::Black));
    credits[1].setOutlineThickness(7.);
    credits[1].setCharacterSize(70);
    credits[1].setPosition(600,325);

    credits[2].setString("Nathan Tytgat");
    credits[2].setOutlineColor(sf::Color(sf::Color::Black));
    credits[2].setOutlineThickness(7.);
    credits[2].setCharacterSize(70);
    credits[2].setPosition(700,475);

}

void AboutStateView::run(sf::RenderWindow* window)
{
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->gm->setState(EnumState::MENUSTATE);

}

void AboutStateView::render(sf::RenderWindow* window)
{
    for(int i = 0;i<4;i++){
        credits[i].setFont(font);
    }

    for(int i = 0;i<4;i++){
        window->draw(credits[i]);
    }
}
void AboutStateView::destroy()
{

}
