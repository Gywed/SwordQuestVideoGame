#include "AboutStateView.h"
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
    if(!font.loadFromFile("Fonts/Typography.otf")){
        std::cout << "No Font is here";
    }

    credits[0].setString("Alexandre Dujacquier");
    credits[0].setCharacterSize(70);
    credits[0].setPosition(700,175);

    credits[1].setString("Yohan Noel-Huls");
    credits[1].setCharacterSize(70);
    credits[1].setPosition(600,325);

    credits[2].setString("Nathan Tytgat");
    credits[2].setCharacterSize(70);
    credits[2].setPosition(700,475);

    credits[3].setString("Pierre Gillebert");
    credits[3].setCharacterSize(70);
    credits[3].setPosition(600,625);
}

void AboutStateView::run(sf::RenderWindow* window)
{
    sf::Event ev;
//    bool Running = true;
//    while(Running){


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
//               case  sf::Keyboard::Escape : App->close(); return (-1);break;
                case  sf::Keyboard::Escape : window->close();break;
//                case  sf::Keyboard::Escape : this->gm->setState(EnumState::MENUSTATE);break;
                default : break;
            }
        }
//    }
    }
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
