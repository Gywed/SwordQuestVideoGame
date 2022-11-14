#include "GameManagerView.h"
#include "OptionStateView.h"
#include "AboutStateView.h"
#include "PlayStateView.h"
#include "MenuStateView.h"

GameManagerView::GameManagerView()
{
    this->state = NULL;
}

GameManagerView::~GameManagerView()
{
    //Destroy state pointer
    if(this->state!=NULL){
        delete this->state;
        this->state = NULL;
    }
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
    switch(st)
    {
        case EnumState::MENUSTATE: this->state = new MenuStateView(this);break;
        case EnumState::PLAYSTATE: this->state = new PlayStateView(this);break;
//        case EnumState::OPTIONSTATE: this->state = new OptionStateView(this);break;
        case EnumState::ABOUTSTATE: this->state = new AboutStateView(this);break;
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
