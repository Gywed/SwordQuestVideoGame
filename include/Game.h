#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "MainMenu.h"
#include "PlayScreen.h"
#include "AboutScreen.h"
#include "OptionScreen.h"
#include "cScreen.h"

class Game
{

    private:
        //Variables
        //Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        MainMenu mainMenu;
        PlayScreen playScreen;
        OptionScreen optionScreen;
        AboutScreen aboutScreen;
        std::vector<cScreen*> Screens;
        int screen = 0;


        //Private Functions
        void initializeViariable();
        void initWindow();


    public:
        //Constructors
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        //Accessors
        const bool running() const;


        //Functions
        void pollEvents();
        void update();
        void render();
        void run();

};

#endif // GAME_H
