#include "PlayStateView.h"
#include <iostream>
#include <thread>

// For Pause Thread
void doPause()
{}

// For Dead thread
void doDead()
{
    std::cout<<"Dead"<<std::endl;
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

    delete sound;
    delete buffer;
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
    // Sound
    buffer = new sf::SoundBuffer();
    buffer->loadFromFile("Sound/LE_DONJONNNNN.wav");

    sound = new sf::Sound(*buffer);
    sound->setVolume(50.);
    sound->play();

    // Main hero

    this->mainHeroM = new MainHero(window->getSize().x/2., window->getSize().y/2.);
    this->mainHeroV = new MainHeroView(mainHeroM);

    this->roomV = new BasicRoomView();
    this->pauseV = new PauseView(this->gm);

}

void PlayStateView::run(sf::RenderWindow* window)
{
    // Thread for the dead menu
    if (mainHeroV->getDeadFlag())
    {
        std::thread deadThread(doDead);
        while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
        mainHeroV->setDeadFlag(false);
        deadThread.join();
    }

    // Block Event here if MainHero is dying
    if (mainHeroV->getDeathFlag())
        this->mainHeroV->spriteEvents(window);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {

        std::thread pauseThread(doPause);
        this->pauseFlag = true;
        render(window);
        window->display();
        state = -1;
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
            sound->stop();
            this->gm->setState(EnumState::MENUSTATE);
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->gm->setState(EnumState::MENUSTATE);
        sound->stop();
    }
    else
    {
        this->mainHeroV->spriteEvents(window);
    }
}

void PlayStateView::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(this->roomV->getTileMap());
    window->draw(*this->mainHeroV->lifebarV->getSprite());
    window->draw(*this->mainHeroV);
    if (this->pauseFlag)
        pauseV->render();
}
void PlayStateView::destroy()
{

}
