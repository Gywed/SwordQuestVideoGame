#include "view/PlayStateView.h"
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
    delete roomV;
    delete pauseV;
    delete deadV;
    delete skeletonV;

    delete playStateMenuSound;
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
    // Main hero

    this->mainHeroM = new MainHero(window->getSize().x/2., window->getSize().y/2.);
    this->mainHeroV = new MainHeroView(mainHeroM);

    // Room
    this->skeletonM = new Skeleton(1400., 500.);
    this->skeletonV = new SkeletonView(skeletonM);

    this->mainHeroV->attach(skeletonV);

    this->roomV = new BasicRoomView();

    // Menu
    this->pauseV = new PauseView(this->gm);
    this->deadV = new DeadView(this->gm);

    // Sound
    this->playStateMenuSound = new sf::Sound();
    this->playStateMenuSound->setVolume(50.);
    this->playStateMenuSound->setLoop(true);
    this->buffer = new sf::SoundBuffer();
    this->buffer->loadFromFile("Sound/NoooOoodabedeedabeda.wav");
}

void PlayStateView::run(sf::RenderWindow* window)
{
    // Thread for the dead menu
    if (mainHeroV->getDeadFlag())
    {
        deadV->updateScore(score);
        std::cout<<score<<endl;
        std::thread deadThread(doDead);
        int state = -1;
        while(state == -1)
        {
            state = deadV->run(window);
            render(window);
            window->display();
        }
        deadThread.join();
        mainHeroV->setDeadFlag(false);
        this->playStateMenuSound->stop();
        this->gm->getSound()->play();
        // restart a game
        if (state == 0)
        {
            this->gm->setState(EnumState::PLAYSTATE);
            // This is used to block the rest of the run function (same for all return after a setState)
            return;
        }
        // return to main menu
        if (state == 1)
        {
            this->gm->setState(EnumState::MENUSTATE);
            return;
        }
    }
    // Block Event here if MainHero is dying
    if (mainHeroV->getDeathFlag())
    {
        if (this->playStateMenuSound->getStatus() != sf::Sound::Playing)
        {
            this->gm->getSound()->pause();
            this->gm->getSound()->setPitch(1.);
            this->playStateMenuSound->setBuffer(*buffer);
            this->playStateMenuSound->play();
        }
        this->mainHeroV->spriteEvents(window);
        return;
    }

    if (mainHeroV->getMainHero()->getHP()<= 2)
    {
        this->gm->getSound()->setPitch(1.20);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        std::cout<<"Dead\n";
        this->skeletonV->setDeadFlag(true);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {

        std::thread pauseThread(doPause);
        this->pauseFlag = true;
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
    if (this->skeletonV->getDeadFlag())
    {
        this->score += this->skeletonV->getMonster()->getScoreValue();
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
