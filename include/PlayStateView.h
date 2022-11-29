#ifndef PLAYSTATEVIEW_H
#define PLAYSTATEVIEW_H
#include "StateView.h"
#include "GameManagerView.h"
#include "MainHero.h"
#include "MainHeroView.h"
#include "BasicRoomView.h"
#include <PauseView.h>
#include <DeadView.h>
#include "LifeBarView.h"

class PlayStateView: public StateView
{
    private:
        // GameManager
        GameManagerView* gm;

        //Model
        MainHero* mainHeroM;

        //View
        MainHeroView* mainHeroV;
        BasicRoomView* roomV;

        PauseView* pauseV;
        DeadView* deadV;

        bool pauseFlag = false;
        bool pKey,escapeKey;


    public:
        PlayStateView(GameManagerView* gm);
        virtual ~PlayStateView();
        PlayStateView(const PlayStateView& other);
        PlayStateView& operator=(const PlayStateView& other);

        /* Method (DP "State") */
        virtual void init(sf::RenderWindow* window);
        virtual void run(sf::RenderWindow* window);
        virtual void render(sf::RenderWindow* window);
        virtual void destroy();


};

#endif // PLAYSTATEVIEW_H
