#ifndef ABOUTSTATEVIEW_H
#define ABOUTSTATEVIEW_H
#include "StateView.h"
#include "SFML/Graphics.hpp"
#include "GameManagerView.h"

#define Nb_Credit 7

using namespace sf;

class AboutStateView: public StateView
{
    private:

        RectangleShape background;
        Texture aboutTexture;

        RectangleShape greyRectangle;
        Texture greyRectangleTexture;

        sf::Font font;
        sf::Text credits[Nb_Credit];
        sf::Text specialThanksText;
        sf::Text musicsText;
        sf::Text tileSetText;
        sf::Text animationText;

        sf::Text mainMenuText;
    public:
        AboutStateView(GameManagerView* gm);
        virtual ~AboutStateView();
        AboutStateView(const AboutStateView& other);
        AboutStateView& operator=(const AboutStateView& other);

         /* Method (DP "State") */
        virtual void init(sf::RenderWindow* window);
        virtual void run(sf::RenderWindow* window);
        virtual void render(sf::RenderWindow* window);

    protected:


};

#endif // ABOUTSTATEVIEW_H
