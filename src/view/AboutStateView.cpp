#include "view/AboutStateView.h"
#include <iostream>
#include <string>

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
    credits[0].setPosition(700,75);

    credits[1].setString("Yohan Noel-Huls");
    credits[1].setOutlineColor(sf::Color(sf::Color::Black));
    credits[1].setOutlineThickness(7.);
    credits[1].setCharacterSize(70);
    credits[1].setPosition(600,200);

    credits[2].setString("Nathan Tytgat");
    credits[2].setOutlineColor(sf::Color(sf::Color::Black));
    credits[2].setOutlineThickness(7.);
    credits[2].setCharacterSize(70);
    credits[2].setPosition(700,325);

    // Background image
    this->background.setSize(Vector2f(window->getSize().x,window->getSize().y));
    this->aboutTexture.loadFromFile("images/bk.png");
    this->background.setTexture(&aboutTexture);

    // Grey background
    this->greyRectangle.setSize(Vector2f(window->getSize().x*0.9,window->getSize().y*0.9));
    this->greyRectangleTexture.loadFromFile("images/WhiteBG.png");
    this->greyRectangle.setTexture(&greyRectangleTexture);
    this->greyRectangle.setFillColor(Color(128,128,128,128));
    this->greyRectangle.setPosition(window->getSize().x*0.05,window->getSize().y*0.05);

    specialThanksText.setString("Special thanks to :");
    specialThanksText.setFont(font);
    specialThanksText.setOutlineColor(sf::Color(sf::Color::Black));
    specialThanksText.setOutlineThickness(7.);
    specialThanksText.setCharacterSize(100);
    specialThanksText.setStyle(sf::Text::Underlined);
    specialThanksText.setPosition((window->getSize().x-specialThanksText.getGlobalBounds().width)/2,450);

    musicsText.setString("Musics :");
    musicsText.setFont(font);
    musicsText.setOutlineColor(sf::Color(sf::Color::Black));
    musicsText.setOutlineThickness(7.);
    musicsText.setCharacterSize(70);
    musicsText.setPosition(window->getSize().x*0.1,625);

    tileSetText.setString("Tile Set :");
    tileSetText.setFont(font);
    tileSetText.setOutlineColor(sf::Color(sf::Color::Black));
    tileSetText.setOutlineThickness(7.);
    tileSetText.setCharacterSize(70);
    tileSetText.setPosition(window->getSize().x*0.1,750);

    AnimationText.setString("Animation :");
    AnimationText.setFont(font);
    AnimationText.setOutlineColor(sf::Color(sf::Color::Black));
    AnimationText.setOutlineThickness(7.);
    AnimationText.setCharacterSize(70);
    AnimationText.setPosition(window->getSize().x*0.1,900);

    credits[3].setString("Idonotcomprehend_");
    credits[3].setOutlineColor(sf::Color(sf::Color::Black));
    credits[3].setOutlineThickness(7.);
    credits[3].setCharacterSize(70);
    credits[3].setPosition(window->getSize().x*0.1 + AnimationText.getGlobalBounds().width + 20,625);

    credits[4].setString("Gary Shaw");
    credits[4].setOutlineColor(sf::Color(sf::Color::Black));
    credits[4].setOutlineThickness(7.);
    credits[4].setCharacterSize(70);
    credits[4].setPosition(window->getSize().x*0.1 + AnimationText.getGlobalBounds().width + 20,750);

    credits[5].setString("Snodekfeld");
    credits[5].setOutlineColor(sf::Color(sf::Color::Black));
    credits[5].setOutlineThickness(7.);
    credits[5].setCharacterSize(70);
    credits[5].setPosition(window->getSize().x*0.1 + AnimationText.getGlobalBounds().width + 20,900);


    for(int i = 0;i<Nb_Credit;i++){
        credits[i].setFont(font);
    }

}

void AboutStateView::run(sf::RenderWindow* window)
{
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->gm->setState(EnumState::MENUSTATE);

}

void AboutStateView::render(sf::RenderWindow* window)
{
    window->draw(background);
    window->draw(greyRectangle);

    window->draw(specialThanksText);
    window->draw(musicsText);
    window->draw(tileSetText);
    window->draw(AnimationText);

    for(int i = 0;i<Nb_Credit;i++){
        window->draw(credits[i]);
    }
}
void AboutStateView::destroy()
{

}
