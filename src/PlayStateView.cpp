#include "PlayStateView.h"

PlayStateView::PlayStateView(GameManagerView* gm)
{
    this->gm = gm;
}

PlayStateView::~PlayStateView()
{
    //dtor
}

PlayStateView::PlayStateView(const PlayStateView& other)
{
    //copy ctor
}

PlayStateView& PlayStateView::operator=(const PlayStateView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void PlayStateView::init(sf::RenderWindow* window)
{
    this->characterM = new Character(window->getSize().x/2., window->getSize().y/2.);
    this->characterV = new CharacterView(characterM);
}

void PlayStateView::run(sf::RenderWindow* window)
{
    this->characterV->moveAnyDirection(window);
}
void PlayStateView::render(sf::RenderWindow* window)
{
    window->draw(*this->characterV);
}
void PlayStateView::destroy()
{

}
