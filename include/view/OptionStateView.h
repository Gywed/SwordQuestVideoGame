#ifndef OPTIONSTATEVIEW_H
#define OPTIONSTATEVIEW_H
#include "StateView.h"
#include <view/SliderSFML.h>
#include <view/GameManagerView.h>

using namespace sf;

class OptionStateView: public StateView
{
    private:
        GameManagerView* gm;

        SliderSFML* sliderVolume;

        RectangleShape background;
        Texture optionTexture;

        RectangleShape greyRectangle;
        Texture greyRectangleTexture;

        // Font
        Font globalFont;

        // Game over text
        Text volumeText;

    public:
        OptionStateView(GameManagerView* gm = nullptr);
        virtual ~OptionStateView();
        OptionStateView(const OptionStateView& other);
        OptionStateView& operator=(const OptionStateView& other);

        virtual void init(sf::RenderWindow* window);
        virtual void run(sf::RenderWindow* window);
        virtual void render(sf::RenderWindow* window);
        virtual void destroy();
};

#endif // OPTIONSTATEVIEW_H
