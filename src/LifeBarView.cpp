#include "LifeBarView.h"

LifeBarView::LifeBarView()
{
    //ctor
    this->lifebarSprite= new sf::Sprite();
    this->texture=new sf::Texture();
    texture->loadFromFile("images/lifebar.png");
    this->intrect = new sf::IntRect(16,0,620,53);
    this->lifebarSprite->setTextureRect(*intrect);
    this->lifebarSprite->setTexture(*texture);
    this->lifebarSprite->setPosition(0.0,0.0);
}

LifeBarView::~LifeBarView()
{
    //dtor
    delete lifebarSprite;
    delete texture;
    delete intrect;
}

LifeBarView::LifeBarView(const LifeBarView& other)
{
    //copy ctor
}

LifeBarView& LifeBarView::operator=(const LifeBarView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
void LifeBarView::getDamaged(int hp){
    int res = 10-hp;
    this->intrect->top=0;
    if(this->intrect->top<530)
        this->intrect->top+=(53*res);
    else{
        this->intrect->top=530;
    }
    this->lifebarSprite->setTextureRect(*intrect);
}

void LifeBarView::getHealed(){
}


sf::Sprite* LifeBarView::getSprite()const{
    return this->lifebarSprite;
}
