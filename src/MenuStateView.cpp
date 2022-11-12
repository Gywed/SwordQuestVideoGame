#include "MenuStateView.h"
#include <iostream>

MenuStateView::MenuStateView(GameManagerView* gm)
{
    this->gm = gm;
    this->play = new PlayScreen();
}

MenuStateView::~MenuStateView()
{
    //dtor
}

MenuStateView::MenuStateView(const MenuStateView& other)
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
    isPlay=false;
    isOption=false;
    isAbout=false;
    isQuit=false;

    //Set the background
    this->background.setSize(Vector2f(1920,1080));
    this->mainTexture.loadFromFile("images/MainMenu/background.png");



    //Set all images for each Button
    btnTexture[0].loadFromFile("images/MainMenu/btnPlay.png");
    btnTexture[1].loadFromFile("images/MainMenu/btnOption.png");
    btnTexture[2].loadFromFile("images/MainMenu/btnAbout.png");
    btnTexture[3].loadFromFile("images/MainMenu/btnExit.png");
    btnTexture[4].loadFromFile("images/MainMenu/btnPlayHover.png");
    btnTexture[5].loadFromFile("images/MainMenu/btnOptionHover.png");
    btnTexture[6].loadFromFile("images/MainMenu/btnAboutHover.png");
    btnTexture[7].loadFromFile("images/MainMenu/btnExitHover.png");

    //Button Play
    mMenu[0].setPosition(750,400);

    //Button Option
    mMenu[1].setPosition(750,500);

    //Button About
    mMenu[2].setPosition(750,600);

    //Button Exit
    mMenu[3].setPosition(750,700);

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
        mMenu[MainMenuSelected].setTexture(btnTexture[MainMenuSelected]);
        if(MainMenuSelected-1>=0){
//        mainMenu[MainMenuSelected].setFillColor(Color::Black);
            MainMenuSelected--;
        }
        else
            MainMenuSelected=3;


//        mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
        mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);

    }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)  && !this->downKey) {
        mMenu[MainMenuSelected].setTexture(btnTexture[MainMenuSelected]);
         if(MainMenuSelected+1>=Max_main_menu)
            MainMenuSelected=0;
        else if(MainMenuSelected<3)
            MainMenuSelected++;
        mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !this->enterKey)
    {
        switch(MainMenuSelected)
        {
            case 0 : this->gm->setState(EnumState::PLAYSTATE);
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
    mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);

    //Draw the graphics elements
    window->draw(this->background);

    for(int i=0;i<Max_main_menu;i++){
        window->draw(mMenu[i]);
    }

}
void MenuStateView::destroy()
{

}
