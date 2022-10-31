#include "Game.h"

void Game::initializeViariable(){
    this->window=nullptr;
}

void Game::initWindow(){
    this->videoMode.height=600;
    this->videoMode.width=800;
    this->window = new sf::RenderWindow(this->videoMode, "SwordQuest",sf::Style::Titlebar | sf::Style::Fullscreen);
}


Game::Game()
{
    //ctor
    this->initializeViariable();
    this->initWindow();
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
    while(this->window->pollEvent(this->ev))
    {

        if(this->ev.type==sf::Event::Closed)
            this->window->close();

        if(this->ev.type==sf::Event::KeyPressed)
            if(this->ev.key.code==sf::Keyboard::Escape)
                this->window->close();
    }
}

void Game::update(){
    this->pollEvents();
}

void Game::render(){


    //Draw Game object
    this->window->display();
}
