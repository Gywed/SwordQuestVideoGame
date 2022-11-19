#include "PlayStateView.h"

PlayStateView::PlayStateView(GameManagerView* gm)
{
    this->gm = gm;
}

PlayStateView::~PlayStateView()
{
    delete characterV;
    delete characterM;
    delete roomV;
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

    this->roomV = new BasicRoomView();
}

void PlayStateView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->gm->setState(EnumState::MENUSTATE);
    }else
    {
        this->characterV->moveAnyDirection(window);
    }

}
void PlayStateView::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(this->roomV->getTileMap());
    window->draw(*this->characterV);
}
void PlayStateView::destroy()
{

}
