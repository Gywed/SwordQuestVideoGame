#ifndef ABOUTSTATEVIEW_H
#define ABOUTSTATEVIEW_H
#include "StateView.h"
#include "SFML/Graphics.hpp"
#include "GameManagerView.h"

#define Nb_Credit 6

using namespace sf;

class AboutStateView: public StateView
{
    private:
        GameManagerView* gm;

        RectangleShape background;
        Texture aboutTexture;

        RectangleShape greyRectangle;
        Texture greyRectangleTexture;

        sf::Font font;
        sf::Text credits[Nb_Credit];
        sf::Text specialThanksText;
        sf::Text musicsText;
        sf::Text tileSetText;
        sf::Text AnimationText;
    public:
        AboutStateView(GameManagerView* gm);
        virtual ~AboutStateView();
        AboutStateView(const AboutStateView& other);
        AboutStateView& operator=(const AboutStateView& other);

         /* Method (DP "State") */
        virtual void init(sf::RenderWindow* window);
        virtual void run(sf::RenderWindow* window);
        virtual void render(sf::RenderWindow* window);
        virtual void destroy();

    protected:


};

#endif // ABOUTSTATEVIEW_H
