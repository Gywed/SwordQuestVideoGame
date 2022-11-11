#ifndef MENUSTATEVIEW_H
#define MENUSTATEVIEW_H
#include <SFML/Graphics.hpp>
#include "StateView.h"
#include <GameManagerView.h>



class MenuStateView: public StateView
{
    private:
        // GameManager
        GameManagerView* gm;

        int MainMenuSelected=0;
        Font font;
        Text mainMenu[Max_main_menu];
        Sprite mMenu[Max_main_menu];
        RectangleShape background;
        Texture mainTexture;
        Texture btnTexture[8];

        bool isPlay;
        bool isOption;
        bool isAbout;
        bool isQuit;

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
