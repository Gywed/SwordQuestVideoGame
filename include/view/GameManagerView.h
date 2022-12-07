#ifndef GAMEMANAGERVIEW_H
#define GAMEMANAGERVIEW_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

//#include "StateView.h"
#include "EnumState.h"

class StateView;

class GameManagerView
{
    private:
        // Window game
        sf::RenderWindow* window; //AEP
        // State(PlayState,MenuState,etc..)
        StateView* state;

        // Sound
        sf::SoundBuffer* bufferMainMenu;
        sf::SoundBuffer* bufferPlaying;
        sf::Sound* sound;

    public:
        GameManagerView();
        virtual ~GameManagerView();
        GameManagerView(const GameManagerView& other);
        GameManagerView& operator=(const GameManagerView& other);
        /* Getters and setters */
        sf::RenderWindow* getWindow() const;
        StateView* getState() const;
        void setWindow(sf::RenderWindow* window);
        void setState(const EnumState st);
        sf::Sound* getSound()const;
        /*  Method  */
        void run();
        void render();

    protected:


};

#endif // GAMEMANAGERVIEW_H
