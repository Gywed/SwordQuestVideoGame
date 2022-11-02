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
    this->mainMenu = new MainMenu(this->window->getSize().x,this->window->getSize().y);

}

Game::~Game()
{
    //dtor
    delete this->window;
    delete this->mainMenu;
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
    //Set up Event on key pressed
    while(this->window->pollEvent(this->ev))
    {

        if(this->ev.type==sf::Event::Closed)
            this->window->close();

        //Escape to close the window
        // Will be deleted later
        if(this->ev.type==sf::Event::KeyPressed)
            if(this->ev.key.code==sf::Keyboard::Escape)
                this->window->close();

        if(this->ev.type==Event::KeyReleased)
        {
            // Moving in the menu
            if(this->ev.key.code==Keyboard::Up){
                this->mainMenu->MoveUp();
                break;
            }
            if(this->ev.key.code==Keyboard::Down){
                this->mainMenu->MoveDown();
                break;
            }
            if(this->ev.key.code==Keyboard::Return){
                // Creating window for each option in the menu
                // Will be changed later in Frame
                // Because window are not optimized
                RenderWindow Play(this->videoMode,"SwordQuest");
                RenderWindow Options(this->videoMode,"OPTIONS");
                RenderWindow About(this->videoMode,"ABOUT");

                int x = mainMenu->MainMenuPressed();
                if(x==0){
                    while(Play.isOpen())
                    {
                        Event aevent;
                        while(Play.pollEvent(aevent)){
                            if(aevent.type==Event::Closed)
                            {
                                Play.close();

                            }
                            if(aevent.type==Event::KeyPressed){
                                if(aevent.key.code==Keyboard::Escape){
                                    Play.close();
                                }
                            }
                        }
                        Options.close();
                        About.close();
                        Play.clear();
                        Play.display();

                    }
                }
                if(x==1){
                    while(Options.isOpen())
                    {
                        Event aevent;
                        while(Options.pollEvent(aevent)){
                            if(aevent.type==Event::Closed)
                            {
                                Options.close();

                            }
                            if(aevent.type==Event::KeyPressed){
                                if(aevent.key.code==Keyboard::Escape){
                                    Options.close();
                                }
                            }
                        }
                        Play.close();
                        About.close();
                        Options.clear();
                        Options.display();

                    }
                }
                if(x==2){
                    while(About.isOpen())
                    {
                        Event aevent;
                        while(About.pollEvent(aevent)){
                            if(aevent.type==Event::Closed)
                            {
                                About.close();

                            }
                            if(aevent.type==Event::KeyPressed){
                                if(aevent.key.code==Keyboard::Escape){
                                    About.close();
                                }
                            }
                        }
                        Options.close();
                        Play.close();
                        About.clear();
                        About.display();

                    }
                }
                if(x==3)
                    this->window->close();
                break;

            }
        }

    }
    this->window->clear();
    this->mainMenu->draw(this->window);
    this->window->display();
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
    while(this->window->isOpen())
    {

        update();

        render();
    }
}
