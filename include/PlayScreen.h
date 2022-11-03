#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "cScreen.h"

class PlayScreen:public cScreen
{
    public:
        PlayScreen(void);
        virtual ~PlayScreen();
        PlayScreen(const PlayScreen& other);
        PlayScreen& operator=(const PlayScreen& other);

        virtual int Run(sf::RenderWindow *App);

    protected:

    private:
        float movement_step;
        float posx;
        float posy;
        sf::RectangleShape Rectangle;
};

#endif // PLAYSCREEN_H
