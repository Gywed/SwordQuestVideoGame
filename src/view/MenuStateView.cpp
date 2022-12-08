#include "view/MenuStateView.h"
#include <iostream>

MenuStateView::MenuStateView(GameManagerView* gm):StateView(gm)
{

}

MenuStateView::~MenuStateView()
{
    //dtor
}

MenuStateView::MenuStateView(const MenuStateView& other):StateView(other)
{
    //copy ctor
}

MenuStateView& MenuStateView::operator=(const MenuStateView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/* Method (DP "State") */
// Method init: this method from State allow initialize menustate with all graphics component and logic variable
/*
Assertion :
window : window game (AEP)
*/
void MenuStateView::init(sf::RenderWindow* window)
{

    //Set the background
    this->background.setSize(Vector2f(window->getSize().x,window->getSize().y));
    this->mainTexture.loadFromFile("images/MainMenu/swordQuestMenuTitle.png");



    //Set all images for each Button
    btnTexture[0].loadFromFile("images/MainMenu/PLAY.png");
    btnTexture[1].loadFromFile("images/MainMenu/OPTIONS.png");
    btnTexture[2].loadFromFile("images/MainMenu/ABOUT.png");
    btnTexture[3].loadFromFile("images/MainMenu/EXIT.png");
    btnTexture[4].loadFromFile("images/MainMenu/PLAY_Hovered.png");
    btnTexture[5].loadFromFile("images/MainMenu/OPTIONS_Hovered.png");
    btnTexture[6].loadFromFile("images/MainMenu/ABOUT_Hovered.png");
    btnTexture[7].loadFromFile("images/MainMenu/EXIT_Hovered.png");

    //Smoothing textures
    btnTexture[0].setSmooth(true);
    btnTexture[1].setSmooth(true);
    btnTexture[2].setSmooth(true);
    btnTexture[3].setSmooth(true);
    btnTexture[4].setSmooth(true);
    btnTexture[5].setSmooth(true);
    btnTexture[6].setSmooth(true);
    btnTexture[7].setSmooth(true);

    //Button Play
    mMenu[0].setPosition(window->getSize().x/2. - 20.,350);
    mMenu[0].setScale(.8, .8);

    //Button Option
    mMenu[1].setPosition(window->getSize().x/2. - 20.,500);
    mMenu[1].setScale(.8, .8);

    //Button About
    mMenu[2].setPosition(window->getSize().x/2. - 20.,650);
    mMenu[2].setScale(.8, .8);

    //Button Exit
    mMenu[3].setPosition(window->getSize().x/2. - 20.,800);
    mMenu[3].setScale(.8, .8);

}

// Method run: this method from State allow run menustate with all graphics component and logic variable
/*
Assertion :
window : window game (AEP)
*/
void MenuStateView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up )&& !this->upKey) {
        mMenu[MainMenuSelected].setTexture(btnTexture[MainMenuSelected], true);
        if(MainMenuSelected-1>=0){
            MainMenuSelected--;
        }
        else
            MainMenuSelected=3;

        mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected], true);

    }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)  && !this->downKey) {
        mMenu[MainMenuSelected].setTexture(btnTexture[MainMenuSelected], true);
         if(MainMenuSelected+1>=Max_main_menu)
            MainMenuSelected=0;
        else if(MainMenuSelected<3)
            MainMenuSelected++;
        mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected], true);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !this->enterKey)
    {
        switch(MainMenuSelected)
        {
            case 0 : this->gm->setState(EnumState::PLAYSTATE);break;
            case 1 : this->gm->setState(EnumState::OPTIONSTATE);break;
            case 2 : this->gm->setState(EnumState::ABOUTSTATE);break;
            case 3 : window->close();break;
        }
    }

    // The while in the main is too fast so it is necessary to check in the switch if event is the same as the previous one/
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);

}

// Method render: this method from State allow draw menustate with all graphics component(title,etc..)
/*
Assertion :
window : window game (AEP)
*/
void MenuStateView::render(sf::RenderWindow* window)
{
    //Set the background Texture
    this->background.setTexture(&mainTexture);

    //Set the button texture
    mMenu[0].setTexture(btnTexture[0]);
    mMenu[1].setTexture(btnTexture[1]);
    mMenu[2].setTexture(btnTexture[2]);
    mMenu[3].setTexture(btnTexture[3]);
    mMenu[0].setOrigin(mMenu[0].getGlobalBounds().width/2., mMenu[0].getGlobalBounds().height/2.);
    mMenu[1].setOrigin(mMenu[1].getGlobalBounds().width/2., mMenu[1].getGlobalBounds().height/2.);
    mMenu[2].setOrigin(mMenu[2].getGlobalBounds().width/2., mMenu[2].getGlobalBounds().height/2.);
    mMenu[3].setOrigin(mMenu[3].getGlobalBounds().width/2., mMenu[3].getGlobalBounds().height/2.);
    mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected], true);

    //Draw the graphics elements
    window->draw(this->background);

    for(int i=0;i<Max_main_menu;i++){
        window->draw(mMenu[i]);
    }

}
void MenuStateView::destroy()
{

}
