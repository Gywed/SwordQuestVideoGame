#ifndef MENUSTATEVIEW_H
#define MENUSTATEVIEW_H
#include <SFML/Graphics.hpp>
#include "view/StateView.h"
#include <view/GameManagerView.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define Max_main_menu 4
using namespace sf;

class MenuStateView: public StateView
{
    private:

        int MainMenuSelected=0;
        Font font;
        Sprite mMenu[Max_main_menu];
        RectangleShape background;
        Texture mainTexture;
        Texture btnTexture[Max_main_menu*3];

        bool upKey,downKey, enterKey;

    public:
        MenuStateView(GameManagerView* gm);
        virtual ~MenuStateView();
        MenuStateView(const MenuStateView& other);
        MenuStateView& operator=(const MenuStateView& other);

        /* Method (DP "State") */
        virtual void init(sf::RenderWindow* window);
        virtual void run(sf::RenderWindow* window);
        virtual void render(sf::RenderWindow* window);
        virtual void destroy();

    protected:


};

#endif // MENUSTATEVIEW_H
