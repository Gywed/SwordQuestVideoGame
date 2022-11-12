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
virtual void init(sf::RenderWindow* window)
{
    isPlay=false;
    isOption=false;
    isAbout=false;
    isQuit=false;

    //Set the background
    this->background.setSize(Vector2f(1920,1080));
    this->mainTexture.loadFromFile("images/MainMenu/background.png");
    this->background.setTexture(&mainTexture);


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
    mMenu[0].setTexture(btnTexture[0]);
    mMenu[0].setPosition(750,400);

    //Button Option
    mMenu[1].setTexture(btnTexture[1]);
    mMenu[1].setPosition(750,500);

    //Button About
    mMenu[2].setTexture(btnTexture[2]);
    mMenu[2].setPosition(750,600);

    //Button Exit
    mMenu[3].setTexture(btnTexture[3]);
    mMenu[3].setPosition(750,700);

    //Set the background on the window
    window->draw(this->background);

    //Set up all button
    for(int i=0;i<Max_main_menu;i++){
//        window->draw(mainMenu[i]);
        window->draw(mMenu[i]);
    }
//    mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
    //Set the selected button
    mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);
}

virtual void run(sf::RenderWindow* window);
virtual void render(sf::RenderWindow* window);
virtual void destroy();
