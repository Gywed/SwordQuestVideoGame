#ifndef PLAYSTATEVIEW_H
#define PLAYSTATEVIEW_H
#include "StateView.h"
#include "GameManagerView.h"
#include "Character.h"
#include "CharacterView.h"

class PlayStateView: public StateView
{
    private:
        // GameManager
        GameManagerView* gm;

        //Model
        Character* characterM;

        //View
        CharacterView* characterV;

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
