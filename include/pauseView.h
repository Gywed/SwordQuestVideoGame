#ifndef PAUSEVIEW_H
#define PAUSEVIEW_H
#include <SFML/Graphics.hpp>
#include <GameManagerView.h>

#define Nb_Btn 2

using namespace sf;

class pauseView
{
    private:
        GameManagerView* gm;

        Sprite spriteBackground;
        Sprite spritePauseMenu;

        Texture backgroundTexture;
        Texture signTexture;

        int PauseMenuSelected=0;
        Sprite mMenu[Nb_Btn];
        Texture btnTexture[Nb_Btn*2];

        bool upKey,downKey, enterKey;

    public:
        pauseView(GameManagerView* gm = nullptr);
        virtual ~pauseView();
        pauseView(const pauseView& other);
        pauseView& operator=(const pauseView& other);

        void init(sf::RenderWindow* window);

        int run(sf::RenderWindow* window);

        void render();
};

#endif // PAUSEVIEW_H
