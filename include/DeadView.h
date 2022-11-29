#ifndef DEADVIEW_H
#define DEADVIEW_H

#include <SFML/Graphics.hpp>
#include <GameManagerView.h>

#define Nb_Btn 1

using namespace sf;

class DeadView
{
    private:

        GameManagerView* gm; // AEP

        Sprite spriteBackground;
        Sprite spriteDeadMenu;

        Texture backgroundTexture;
        Texture signTexture;

        int DeadMenuSelected=0;
        Sprite mMenu;
        Texture btnTexture;

        bool enterKey;

    public:
        DeadView(GameManagerView* gm = nullptr);
        virtual ~DeadView();
        DeadView(const DeadView& other);
        DeadView& operator=(const DeadView& other);

        void init(sf::RenderWindow* window);

        int run(sf::RenderWindow* window);

        void render();


};

#endif // DEADVIEW_H
