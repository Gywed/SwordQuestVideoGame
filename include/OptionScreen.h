#ifndef OPTIONSCREEN_H
#define OPTIONSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "cScreen.h"

class OptionScreen:public cScreen
{
    public:
        OptionScreen();
        virtual ~OptionScreen();
        OptionScreen(const OptionScreen& other);
        OptionScreen& operator=(const OptionScreen& other);

        virtual int Run(sf::RenderWindow *App);
    protected:

    private:
};

#endif // OPTIONSCREEN_H
