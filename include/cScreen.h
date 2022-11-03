#ifndef CSCREEN_H
#define CSCREEN_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class cScreen
{
    public:
        cScreen();
        virtual ~cScreen();
        cScreen(const cScreen& other);
        cScreen& operator=(const cScreen& other);
        virtual int Run (sf::RenderWindow *App) = 0;

    protected:

    private:
};

#endif // CSCREEN_H
