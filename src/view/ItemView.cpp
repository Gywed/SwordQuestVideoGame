#include "ItemView.h"

ItemView::ItemView()
{
    //ctor
    this->spritePotion=new sf::Sprite;
    this->texture=new sf::Texture();
    this->texture->loadFromFile("images/Items.png");
    this->intrect=new sf::IntRect(28,0,20,33);
    this->spritePotion->setTextureRect(*intrect);
    this->spritePotion->setTexture(*this->texture);
    this->spritePotion->setPosition(20.0,20.0);


}

ItemView::~ItemView()
{
    //dtor
    delete spritePotion;
    delete texture;
    delete intrect;

}

ItemView::ItemView(const ItemView& other)
{
    //copy ctor
}

ItemView& ItemView::operator=(const ItemView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

sf::Sprite* ItemView::getSprite(){
    return this->spritePotion;
}
