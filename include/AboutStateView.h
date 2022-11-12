#ifndef ABOUTSTATEVIEW_H
#define ABOUTSTATEVIEW_H
#include "StateView.h"
#include "SFML/Graphics.hpp"
#include "GameManagerView.h"


class AboutStateView: public StateView
{
    private:
        GameManagerView* gm;

        sf::Font font;
        sf::Text credits[4];
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
