#ifndef DEADVIEW_H
#define DEADVIEW_H
#include <SFML/Graphics.hpp>
#include <GameManagerView.h>

#define Nb_Btn 2

using namespace sf;

class DeadView
{
    private:
        GameManagerView* gm; // AEP

        // Global design
        Sprite spriteBackground;
        Sprite spriteDeadMenu;

        Texture backgroundTexture;
        Texture signTexture;

        // Menu button
        int DeadMenuSelected=0;
        Sprite dMenu[Nb_Btn];
        Texture btnTexture[Nb_Btn*2];


        // Text
        Font globalFont;

        // Game over text
        Text gameOverText;

        // Score text
        Text scoreText;

        // Score
        int score = 0;

        bool rightKey, leftKey, enterKey;

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
