#ifndef PLAYSTATEVIEW_H
#define PLAYSTATEVIEW_H
#include "view/StateView.h"
#include "view/GameManagerView.h"
#include "model/MainHero.h"
#include "view/MainHeroView.h"
#include "view/BasicRoomView.h"
#include <view/PauseView.h>
#include <view/DeadView.h>
#include "view/LifeBarView.h"
#include "model/Skeleton.h"
#include "view/SkeletonView.h"

class PlayStateView: public StateView
{
    private:
        // GameManager
        GameManagerView* gm;

        //Model
        MainHero* mainHeroM;
        Skeleton* skeletonM;
        Skeleton* skeletonM2;

        //View
        MainHeroView* mainHeroV;
        SkeletonView* skeletonV;
        SkeletonView* skeletonV2;
        BasicRoomView* roomV;

        PauseView* pauseV;
        DeadView* deadV;

        // Sound
        sf::SoundBuffer* buffer;
        sf::Sound* playStateMenuSound;

        // Score
        int score = 0;

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
