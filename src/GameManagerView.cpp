#include "GameManagerView.h"
#include "OptionStateView.h"
#include "AboutStateView.h"
#include "PlayStateView.h"
#include "MenuStateView.h"

GameManagerView::GameManagerView()
{
    this->state = NULL;

    bufferMainMenu = new sf::SoundBuffer();
    bufferMainMenu->loadFromFile("Sound/LE_TITRE.wav");

    bufferPlaying = new sf::SoundBuffer();
    bufferPlaying->loadFromFile("Sound/LE_DONJONNNNN.wav");

    sound = new sf::Sound();
    sound->setVolume(50.);
    sound->setLoop(true);
}

GameManagerView::~GameManagerView()
{
    //Destroy state pointer
    delete this->state;

    delete sound;

    delete bufferMainMenu;
    delete bufferPlaying;
}

GameManagerView::GameManagerView(const GameManagerView& other)
{
    //copy ctor
}

GameManagerView& GameManagerView::operator=(const GameManagerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/* Getters and setters */
sf::RenderWindow* GameManagerView::getWindow() const { return window; }
StateView* GameManagerView::getState() const { return state; }
void GameManagerView::setWindow(sf::RenderWindow* window) {this->window = window;}
void GameManagerView::setState(const EnumState st)
{
    delete state;
    switch(st)
    {
        case EnumState::MENUSTATE:
            this->state = new MenuStateView(this);
            if (sound->getBuffer() != bufferMainMenu)
            {
                sound->setBuffer(*bufferMainMenu);
                sound->play();
            }
            break;

        case EnumState::PLAYSTATE:
            this->state = new PlayStateView(this);
            if (sound->getBuffer() != bufferPlaying)
            {
                sound->setBuffer(*bufferPlaying);
                sound->play();
            }
            break;

//        case EnumState::OPTIONSTATE: this->state = new OptionStateView(this);break;
        case EnumState::ABOUTSTATE:
            this->state = new AboutStateView(this);
            if (sound->getBuffer() != bufferMainMenu)
            {
                sound->setBuffer(*bufferMainMenu);
                sound->play();
            }
            break;
        default:break;
    }

    if(this->state!=NULL)
        this->state->init(this->window);
}
/*  Method  */
void GameManagerView::run()
{
    if(this->state != NULL) {
        this->state->run(this->window);
      }
}
void GameManagerView::render()
{
    if(this->state != NULL) {
        this->state->render(this->window);
      }
}
