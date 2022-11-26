#include "PlayStateView.h"
#include <iostream>
#include <thread>

void doPause()
{
}

PlayStateView::PlayStateView(GameManagerView* gm)
{
    this->gm = gm;
}

PlayStateView::~PlayStateView()
{
    delete mainHeroV;
    delete mainHeroM;
    delete roomV;
    delete pauseV;
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
    this->mainHeroM = new MainHero(window->getSize().x/2., window->getSize().y/2.);
    this->mainHeroV = new MainHeroView(mainHeroM);

    this->roomV = new BasicRoomView();
    this->pauseV = new pauseView(this->gm);
}

void PlayStateView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {

        std::thread pauseThread(doPause);
        this->pauseFlag = true;
        render(window);
        window->display();

        state = pauseV->run(window);

        std::cout<<state<<endl;
        pauseThread.join();
        this->pauseFlag = false;
        state = 1;
        if (state == 0)
            this->characterV->spriteEvents(window);
        if (state == 1)
            this->gm->setState(EnumState::MENUSTATE);

    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->gm->setState(EnumState::MENUSTATE);
    }else
    {
        this->mainHeroV->spriteEvents(window);
    }
}

void PlayStateView::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(this->roomV->getTileMap());
    window->draw(*this->mainHeroV);
    if (this->pauseFlag)
        pauseV->render();
}
void PlayStateView::destroy()
{

}
