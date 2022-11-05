#ifndef ABOUTSCREEN_H
#define ABOUTSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "cScreen.h"

class AboutScreen:public cScreen
{
    public:
        AboutScreen();
        virtual ~AboutScreen();
        AboutScreen(const AboutScreen& other);
        AboutScreen& operator=(const AboutScreen& other);

        virtual int Run(sf::RenderWindow *App);
    protected:

    private:
};

#endif // ABOUTSCREEN_H
