#ifndef ITEMVIEW_H
#define ITEMVIEW_H
#include "SFML/Graphics.hpp"

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


};

#endif // ITEMVIEW_H
