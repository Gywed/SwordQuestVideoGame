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
    sound->setLoop(true);
    if (sound->getStatus() != sf::Music::Status::Playing)
        sound->play();

    // Main hero

    this->mainHeroM = new MainHero(window->getSize().x/2., window->getSize().y/2.);
    this->mainHeroV = new MainHeroView(mainHeroM);

    // Room
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
        mainHeroV->setDeadFlag(false);
        deadThread.join();
        if (state == 0)
            this->gm->setState(EnumState::PLAYSTATE);
        if (state == 1)
        {
            sound->stop();
            this->gm->setState(EnumState::MENUSTATE);
        }

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
    if (mainHeroV->getDeadFlag())
        deadV->render();
}
void PlayStateView::destroy()
{

}
