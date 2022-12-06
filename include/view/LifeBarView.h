#ifndef LIFEBARVIEW_H
#define LIFEBARVIEW_H
#include "SFML/Graphics.hpp"


class LifeBarView
{
    private:

        sf::Sprite* lifebarSprite;
        sf::Texture* texture;
        sf::IntRect* intrect;





    public:
        LifeBarView();
        virtual ~LifeBarView();
        LifeBarView(const LifeBarView& other);
        LifeBarView& operator=(const LifeBarView& other);

        void getDamaged(int hp);
        void getHealed(int hp);

        sf::Sprite* getSprite()const;
};

#endif // LIFEBARVIEW_H
