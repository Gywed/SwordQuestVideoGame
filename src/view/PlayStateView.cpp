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
    this->roomV = new BasicRoomView();
    //Default monsters generated
    this->mainHeroV->attach(this->roomV->generateMonsterView());

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
        deadV->updateScore(mainHeroV->getScore());
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
        //New monster spawn
        if(monsterSpawnTimer.getElapsedTime().asSeconds() > timeBeforeSpawn)
        {
            //Create a new monster and add it to the list of observers of mainHeroV
            this->mainHeroV->attach(this->roomV->generateMonsterView());
            timeBeforeSpawn*=0.9;
            monsterSpawnTimer.restart();
        }

        //Main hero actions
        this->mainHeroV->spriteEvents(window);

        //Loop in the monsters list
        for(MonsterEntity* monster : this->roomV->getMonsters())
            //Monster is dead
            if(monster->getDeadFlag())
            {
                //Score increased
                mainHeroV->increaseScore(monster->getMonster()->getScoreValue());
                //The monster is detach of the obervers list of MainHEroV
                this->mainHeroV->detach(monster);
                //Delete from monster list and free the memory
                this->roomV->removeMonster(monster);
            }
            else
                //Monster actions
                monster->spriteEvents(window, mainHeroV);
    }
}

void PlayStateView::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(this->roomV->getTileMap());
    window->draw(*this->mainHeroV->getLifeBarView()->getSprite());
    window->draw(*this->mainHeroV->getLifeBarView()->getSprite());
    for(MonsterEntity* monster : this->roomV->getMonsters())
        window->draw(*monster);
    window->draw(*this->mainHeroV);
    if (this->pauseFlag)
        pauseV->render();
    if (mainHeroV->getDeadFlag())
        deadV->render();
}
void PlayStateView::destroy()
{

}
