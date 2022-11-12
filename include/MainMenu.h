#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "cScreen.h"
#include "PlayScreen.h"

#define Max_main_menu 4

class MainMenu:public cScreen
{
    private:
        //Variable
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
        //Constructors
        MainMenu(void);
        virtual ~MainMenu();
        MainMenu(const MainMenu& other);
        MainMenu& operator=(const MainMenu& other);
        virtual int Run(sf::RenderWindow *App);

        //Public Functions
        void draw(RenderWindow* window);
        void clear(RenderWindow* window);
        void MoveUp();
        void MoveDown();

        int MainMenuPressed(){
            return MainMenuSelected;
        }


};

#endif // MAINMENU_H
