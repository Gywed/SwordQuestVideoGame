#ifndef PAUSESTATEVIEW_H
#define PAUSESTATEVIEW_H
#include <SFML/Graphics.hpp>
#include <GameManagerView.h>

#define Nb_Btn 2

using namespace sf;

class PauseStateView
{
    private:
        GameManagerView* gm;

        Sprite spriteBackground;
        Sprite spritePauseMenu;

        Texture backgroundTexture;
        Texture signTexture;

        int PauseMenuSelected=0;
        Sprite mMenu[Nb_Btn];
        Texture btnTexture[Nb_Btn*3];

        bool rightKey,leftKey, enterKey;

    public:
        PauseStateView(GameManagerView* gm = nullptr);
        virtual ~PauseStateView();
        PauseStateView(const PauseStateView& other);
        PauseStateView& operator=(const PauseStateView& other);

        void init(sf::RenderWindow* window);

        int run(sf::RenderWindow* window);

        void render();
};

#endif // PAUSESTATEVIEW_H
