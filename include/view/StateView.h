#ifndef STATEVIEW_H
#define STATEVIEW_H
#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "view/GameManagerView.h"


class StateView
{
    public:
        StateView(GameManagerView* gm);
        virtual ~StateView();
        StateView(const StateView& other);
        StateView& operator=(const StateView& other);

        /* Abstract Method */
        /* Method to initialize the state (constructor) */
        virtual void init(sf::RenderWindow* window) = 0;
        /* Method to run the state */
        virtual void run(sf::RenderWindow* window) = 0;
        /* Method to draw component in the game window */
        virtual void render(sf::RenderWindow* window) = 0;
        /* Method for destroy component in the window game */
        virtual void destroy() = 0;

    protected:
        // GameManager
        GameManagerView* gm;

    private:
};

#endif // STATEVIEW_H
