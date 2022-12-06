#ifndef ITEMVIEW_H
#define ITEMVIEW_H
#include "SFML/Graphics.hpp"
#include "view/MainHeroView.h"

class ItemView
{
    private:
        sf::Sprite* spritePotion;
        sf::Texture* texture;
        sf::IntRect* intrect;


    public:
        ItemView();
        virtual ~ItemView();
        ItemView(const ItemView& other);
        ItemView& operator=(const ItemView& other);

        sf::Sprite* getSprite();

        bool takePotion(MainHeroView* mainHeroV);
};

#endif // ITEMVIEW_H
