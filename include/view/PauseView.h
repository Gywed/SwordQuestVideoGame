#ifndef PAUSEVIEW_H
#define PAUSEVIEW_H
#include <SFML/Graphics.hpp>
#include <view/GameManagerView.h>

#define Nb_Btn 2

using namespace sf;

class PauseView
{
    private:
        GameManagerView* gm; // AEP

        Sprite spriteBackground;
        Sprite spritePauseMenu;

        Texture backgroundTexture;
        Texture signTexture;

        int PauseMenuSelected=0;
        Sprite pMenu[Nb_Btn];
        Texture btnTexture[Nb_Btn*3];

        bool rightKey, leftKey, enterKey;

    public:
        PauseView(GameManagerView* gm = nullptr);
        virtual ~PauseView();
        PauseView(const PauseView& other);
        PauseView& operator=(const PauseView& other);

        void init(sf::RenderWindow* window);

        int run(sf::RenderWindow* window);

        void render();
};

#endif // PAUSEVIEW_H
