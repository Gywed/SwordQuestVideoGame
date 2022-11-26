#include "PauseStateView.h"

PauseStateView::PauseStateView(GameManagerView* gm):gm(gm)
{
    //ctor
    init(gm->getWindow());
}

PauseStateView::~PauseStateView()
{
    //dtor
}

PauseStateView::PauseStateView(const PauseStateView& other)
{
    //copy ctor
    this->gm = other.gm;

    this->spriteBackground = other.spriteBackground;
    this->spritePauseMenu = other.spritePauseMenu;

}

PauseStateView& PauseStateView::operator=(const PauseStateView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void PauseStateView::init(sf::RenderWindow* window)
{
    spriteBackground.setTextureRect(IntRect(0,0,window->getSize().x,window->getSize().y));
    backgroundTexture.loadFromFile("images/PauseMenu/WhiteBG.png");
    spriteBackground.setTexture(backgroundTexture);
    spriteBackground.setColor(Color(128,128,128,128));

    signTexture.loadFromFile("images/PauseMenu/sign.png");
    signTexture.setSmooth(true);
    spritePauseMenu.setTexture(signTexture);
    spritePauseMenu.setTextureRect(IntRect(0,0,signTexture.getSize().x,signTexture.getSize().y));
    float scaleX = 2.;
    float scaleY = 2.;
    spritePauseMenu.setScale(scaleX,scaleY);
    float signPosX = (window->getSize().x-signTexture.getSize().x*scaleX)/2;
    float signPosY = window->getSize().y-signTexture.getSize().y*scaleY;
    spritePauseMenu.setPosition(signPosX,signPosY);

    btnTexture[0].loadFromFile("images/PauseMenu/Button/RESUME.png");
    btnTexture[1].loadFromFile("images/PauseMenu/Button/MAIN_MENU.png");
    btnTexture[2].loadFromFile("images/PauseMenu/Button/RESUME_Hovered.png");
    btnTexture[3].loadFromFile("images/PauseMenu/Button/MAIN_MENU_Hovered.png");

    btnTexture[0].setSmooth(true);
    btnTexture[1].setSmooth(true);
    btnTexture[2].setSmooth(true);
    btnTexture[3].setSmooth(true);

    // Button resume
    mMenu[0].setPosition(window->getSize().x/2. -35.,350);
    mMenu[0].setScale(.7, .7);

    // Button exit
    mMenu[1].setPosition(window->getSize().x/2. -35.,window->getSize().y*0.65);
    mMenu[1].setScale(.7, .7);
}

int PauseStateView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey) {
    mMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected], true);
    if(PauseMenuSelected-1>=0){
        PauseMenuSelected--;
    }
    else
        PauseMenuSelected=1;


    mMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected+2], true);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey) {
        mMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected], true);
        if(PauseMenuSelected+1>=Nb_Btn)
            PauseMenuSelected=0;
        else
            PauseMenuSelected++;
        mMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected+2], true);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !this->enterKey)
    {
        return PauseMenuSelected;
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);

    return -1;
}

void PauseStateView::render()
{
    this->gm->getWindow()->draw(spriteBackground);
    this->gm->getWindow()->draw(spritePauseMenu);

    mMenu[0].setTexture(btnTexture[0]);
    mMenu[1].setTexture(btnTexture[1]);
    mMenu[0].setOrigin(mMenu[0].getGlobalBounds().width/2., mMenu[0].getGlobalBounds().height/2.);
    mMenu[1].setOrigin(mMenu[1].getGlobalBounds().width/2., mMenu[1].getGlobalBounds().height/2.);
    mMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected+2], true);

    for(int i=0;i<Nb_Btn;i++){
        this->gm->getWindow()->draw(mMenu[i]);
    }

}






