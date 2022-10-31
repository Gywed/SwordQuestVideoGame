#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4

class MainMenu
{
    private:
        int MainMenuSelected;
        Font font;
        Text mainMenu[Max_main_menu];


    public:
        MainMenu(float width,float height);
        virtual ~MainMenu();
        MainMenu(const MainMenu& other);
        MainMenu& operator=(const MainMenu& other);

        //Public Functions
        void draw(RenderWindow* window);
        void MoveUp();
        void MoveDown();

        int MainMenuPressed(){
            return MainMenuSelected;
        }


};

#endif // MAINMENU_H
