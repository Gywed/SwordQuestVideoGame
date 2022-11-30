#include "PlayStateView.h"
#include <iostream>
#include <thread>

// For Pause Thread
void doPause()
{}

// For Dead thread
void doDead()
{}

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
    delete deadV;
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
    // Main hero

    this->mainHeroM = new MainHero(window->getSize().x/2., window->getSize().y/2.);
    this->mainHeroV = new MainHeroView(mainHeroM);

    // Room
    this->skeletonM = new Skeleton(1400., 500.);
    this->skeletonV = new SkeletonView(skeletonM);

    this->roomV = new BasicRoomView();

    // Menu
    this->pauseV = new PauseView(this->gm);
    this->deadV = new DeadView(this->gm);

}

void PlayStateView::run(sf::RenderWindow* window)
{
    // Thread for the dead menu
    if (mainHeroV->getDeadFlag())
    {
        std::thread deadThread(doDead);
        render(window);
        window->display();
        int state = -1;
        while(state == -1)
        {
            state = deadV->run(window);
            render(window);
            window->display();
        }
        deadThread.join();
        mainHeroV->setDeadFlag(false);
        if (state == 0)
            this->gm->setState(EnumState::PLAYSTATE);
        if (state == 1)
        {
            this->gm->setState(EnumState::MENUSTATE);
            // This is used to block the rest of the run function (same for all next return after setState)
            return;
        }
    }

    // Block Event here if MainHero is dying
    if (mainHeroV->getDeathFlag())
    {
        this->mainHeroV->spriteEvents(window);
        return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {

        std::thread pauseThread(doPause);
        this->pauseFlag = true;
        render(window);
        window->display();
        int state = -1;
        while(state == -1)
        {
            state = pauseV->run(window);
            render(window);
            window->display();
        }

        pauseThread.join();
        this->pauseFlag = false;
        if (state == 0)
            this->mainHeroV->spriteEvents(window);
        if (state == 1)
        {
            this->gm->setState(EnumState::MENUSTATE);
            return;
        }
    } else
    {
        this->mainHeroV->spriteEvents(window);
        this->skeletonV->spriteEvents(window, this->mainHeroV);
    }
}

void PlayStateView::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(this->roomV->getTileMap());
    window->draw(*this->mainHeroV->getLifeBarView()->getSprite());
    window->draw(*this->mainHeroV->getLifeBarView()->getSprite());
    window->draw(*this->skeletonV);
    window->draw(*this->mainHeroV);
    if (this->pauseFlag)
        pauseV->render();
    if (mainHeroV->getDeadFlag())
        deadV->render();
}
void PlayStateView::destroy()
{

}
