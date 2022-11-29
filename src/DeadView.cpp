#include "DeadView.h"

DeadView::DeadView(GameManagerView* gm):gm(gm)
{
    //ctor
    init(gm->getWindow());
}

DeadView::~DeadView()
{
    //dtor
}

DeadView::DeadView(const DeadView& other)
{
    //copy ctor
    this->gm = other.gm;

    this->spriteBackground = other.spriteBackground;
    this->spriteDeadMenu = other.spriteDeadMenu;
}

DeadView& DeadView::operator=(const DeadView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    this->gm = rhs.gm;

    this->spriteBackground = rhs.spriteBackground;
    this->spriteDeadMenu = rhs.spriteDeadMenu;

    return *this;
}

void DeadView::init(sf::RenderWindow* window)
{
    spriteBackground.setTextureRect(IntRect(0,0,window->getSize().x,window->getSize().y));
    backgroundTexture.loadFromFile("images/DeadMenu/WhiteBG.png");
    spriteBackground.setTexture(backgroundTexture);
    spriteBackground.setColor(Color(128,128,128,128));

    signTexture.loadFromFile("images/DeadMenu/Sword.png");
    signTexture.setSmooth(true);
    spriteDeadMenu.setTexture(signTexture);
    spriteDeadMenu.setTextureRect(IntRect(0,0,signTexture.getSize().x,signTexture.getSize().y));
    float scaleX = 2.1;
    float scaleY = 2.1;
    spriteDeadMenu.setScale(scaleX,scaleY);
    float signPosX = (window->getSize().x-signTexture.getSize().x*scaleX)/2;
    float signPosY = (window->getSize().y-signTexture.getSize().y*scaleY)/2;
    spriteDeadMenu.setPosition(signPosX,signPosY);

    btnTexture.loadFromFile("images/DeadMenu/Button/MAIN_MENU_Hovered.png");

    btnTexture.setSmooth(true);

    // Button resume
    mMenu.setPosition(window->getSize().x*0.15,window->getSize().y/2.1);
    mMenu.setScale(.65, .65);

}

int DeadView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !this->enterKey)
    {
        return DeadMenuSelected;
    }

    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);

    return -1;
}

void DeadView::render()
{
    this->gm->getWindow()->draw(spriteBackground);
    this->gm->getWindow()->draw(spriteDeadMenu);

    mMenu.setTexture(btnTexture);
    mMenu.setOrigin(mMenu.getGlobalBounds().width/2., mMenu.getGlobalBounds().height/2.);

    this->gm->getWindow()->draw(mMenu);
}
