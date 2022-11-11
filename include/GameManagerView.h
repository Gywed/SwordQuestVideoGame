#ifndef GAMEMANAGERVIEW_H
#define GAMEMANAGERVIEW_H
#include <SFML/Graphics.hpp>

using namespace std;

#include "State.h"
#include "EnumState.h"

class GameManagerView
{
    private:
        // Window game
        sf::RenderWindow* window;
        // State(GameState,MenuState,etc..)
        State* state;

    public:
        GameManagerView();
        virtual ~GameManagerView();
        GameManagerView(const GameManagerView& other);
        GameManagerView& operator=(const GameManagerView& other);
        /* Getters and setters */
        sf::RenderWindow* getWindow() const;
        State* getState() const;
        void setWindow(sf::RenderWindow* window);
        void setState(const EnumState st);
        /*  Method  */
        void run();
        void render();

    protected:


};

#endif // GAMEMANAGERVIEW_H
