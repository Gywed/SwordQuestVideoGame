#include "view/PauseView.h"

PauseView::PauseView(GameManagerView* gm):gm(gm)
{
    //ctor
    init(gm->getWindow());
}

PauseView::~PauseView()
{
    //dtor
}

PauseView::PauseView(const PauseView& other)
{
    //copy ctor
    this->gm = other.gm;

    this->spriteBackground = other.spriteBackground;
    this->spritePauseMenu = other.spritePauseMenu;

}

PauseView& PauseView::operator=(const PauseView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->gm = rhs.gm;

    this->spriteBackground = rhs.spriteBackground;
    this->spritePauseMenu = rhs.spritePauseMenu;
    return *this;
}

void PauseView::init(sf::RenderWindow* window)
{
    spriteBackground.setTextureRect(IntRect(0,0,window->getSize().x,window->getSize().y));
    backgroundTexture.loadFromFile("images/WhiteBG.png");
    spriteBackground.setTexture(backgroundTexture);
    spriteBackground.setColor(Color(128,128,128,128));

    signTexture.loadFromFile("images/PauseMenu/Sword.png");
    signTexture.setSmooth(true);
    spritePauseMenu.setTexture(signTexture);
    spritePauseMenu.setTextureRect(IntRect(0,0,signTexture.getSize().x,signTexture.getSize().y));
    float scaleX = 2.1;
    float scaleY = 2.1;
    spritePauseMenu.setScale(scaleX,scaleY);
    float signPosX = (window->getSize().x-signTexture.getSize().x*scaleX)/2;
    float signPosY = (window->getSize().y-signTexture.getSize().y*scaleY)/2;
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
    pMenu[0].setPosition(window->getSize().x*0.17,window->getSize().y/2.1);
    pMenu[0].setScale(.65, .65);

    // Button Main Menu
    pMenu[1].setPosition(window->getSize().x*0.45,window->getSize().y/2.1);
    pMenu[1].setScale(.65, .65);
}

int PauseView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKey) {
    pMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected], true);
        if(PauseMenuSelected-1>=0){
            PauseMenuSelected--;
        }
        else
            PauseMenuSelected=1;


        pMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected+2], true);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKey) {
        pMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected], true);
        if(PauseMenuSelected+1>=Nb_Btn)
            PauseMenuSelected=0;
        else
            PauseMenuSelected++;
        pMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected+2], true);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !this->enterKey)
    {
        return PauseMenuSelected;
    }

    this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);

    return -1;
}

void PauseView::render()
{
    this->gm->getWindow()->draw(spriteBackground);
    this->gm->getWindow()->draw(spritePauseMenu);

    pMenu[0].setTexture(btnTexture[0]);
    pMenu[1].setTexture(btnTexture[1]);
    pMenu[0].setOrigin(pMenu[0].getGlobalBounds().width/2., pMenu[0].getGlobalBounds().height/2.);
    pMenu[1].setOrigin(pMenu[1].getGlobalBounds().width/2., pMenu[1].getGlobalBounds().height/2.);
    pMenu[PauseMenuSelected].setTexture(btnTexture[PauseMenuSelected+2], true);

    for(int i=0;i<Nb_Btn;i++){
        this->gm->getWindow()->draw(pMenu[i]);
    }

}
