#ifndef PAUSEVIEW_H
#define PAUSEVIEW_H
#include <SFML/Graphics.hpp>

class pauseView
{
    public:
        pauseView(sf::RenderWindow* window = nullptr);
        virtual ~pauseView();
        pauseView(const pauseView& other);
        pauseView& operator=(const pauseView& other);
        sf::Sprite* getSpriteBackground() const;

        void render();


    protected:

    private:
        sf::Sprite* spriteBackground;
        sf::RenderWindow* window;
        sf::Sprite* spriteRectPauseMenu;
};

#endif // PAUSEVIEW_H
