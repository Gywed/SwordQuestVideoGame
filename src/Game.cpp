#include "Game.h"
#include "MainMenu.h"

void Game::initializeViariable(){
    this->window=nullptr;
}

void Game::initWindow(){
    //videoMode used if we are not in fullscreen
    this->videoMode.height=600;
    this->videoMode.width=800;
    this->window = new sf::RenderWindow(this->videoMode, "SwordQuest",sf::Style::Titlebar | sf::Style::Fullscreen);
}


Game::Game()
{
    //ctor
    this->initializeViariable();
    this->initWindow();

    this->Screens.push_back(&mainMenu);
    this->Screens.push_back(&playScreen);
    this->Screens.push_back(&optionScreen);
    this->Screens.push_back(&aboutScreen);
    while(screen>=0){
        screen=Screens[screen]->Run(window);
    }

}

Game::~Game()
{
    //dtor
    delete this->window;

}

Game::Game(const Game& other)
{
    //copy ctor
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

// Accessors
const bool Game::running()const{
    return this->window->isOpen();

}


// Function
void Game::pollEvents(){

}

void Game::update(){
    this->pollEvents();
}

void Game::render(){
//    this->window->draw();

    //Draw Game object
    this->window->display();
}

void Game::run(){
    while(running())
    {

        update();

        render();
    }
}
