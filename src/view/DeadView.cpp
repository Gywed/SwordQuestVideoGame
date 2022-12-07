#include "view/DeadView.h"

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

void DeadView::updateScore(int newScore)
{
    this->score = newScore;
    scoreText.setString("Score : "+std::to_string(score));
}

void DeadView::init(sf::RenderWindow* window)
{
    // Background
    spriteBackground.setTextureRect(IntRect(0,0,window->getSize().x,window->getSize().y));
    backgroundTexture.loadFromFile("images/WhiteBG.png");
    spriteBackground.setTexture(backgroundTexture);
    spriteBackground.setColor(Color(128,128,128,128));

    // Menu image
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


    // Buttons
    btnTexture[0].loadFromFile("images/DeadMenu/Button/RESTART.png");
    btnTexture[1].loadFromFile("images/DeadMenu/Button/MAIN_MENU.png");
    btnTexture[2].loadFromFile("images/DeadMenu/Button/RESTART_Hovered.png");
    btnTexture[3].loadFromFile("images/DeadMenu/Button/MAIN_MENU_Hovered.png");

    btnTexture[0].setSmooth(true);
    btnTexture[1].setSmooth(true);
    btnTexture[2].setSmooth(true);
    btnTexture[3].setSmooth(true);

    // Button restart
    dMenu[0].setPosition(window->getSize().x*0.17,window->getSize().y/2.1);
    dMenu[0].setScale(.65, .65);

    // Button Main Menu
    dMenu[1].setPosition(window->getSize().x*0.45,window->getSize().y/2.1);
    dMenu[1].setScale(.65, .65);

    // Global Text
    globalFont.loadFromFile("Fonts/Berlin_Sans_FB_Demi_Bold.ttf");

    // Game over
    gameOverText.setFont(globalFont);
    gameOverText.setString("Game Over");
    gameOverText.setOutlineColor(sf::Color(sf::Color::Black));
    gameOverText.setOutlineThickness(7.);
    gameOverText.setCharacterSize(150);
    gameOverText.setPosition((window->getSize().x-gameOverText.getGlobalBounds().width)/2-200.,window->getSize().y*0.10);

    // Score
    scoreText.setFont(globalFont);
    scoreText.setOutlineColor(sf::Color(sf::Color::Black));
    scoreText.setOutlineThickness(7.);
    scoreText.setCharacterSize(100);
    scoreText.setPosition((window->getSize().x-gameOverText.getGlobalBounds().width)/2,window->getSize().y*0.70);
}

int DeadView::run(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKey) {
    dMenu[DeadMenuSelected].setTexture(btnTexture[DeadMenuSelected], true);
        if(DeadMenuSelected-1>=0){
            DeadMenuSelected--;
        }
        else
            DeadMenuSelected=1;


        dMenu[DeadMenuSelected].setTexture(btnTexture[DeadMenuSelected+2], true);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKey) {
        dMenu[DeadMenuSelected].setTexture(btnTexture[DeadMenuSelected], true);
        if(DeadMenuSelected+1>=Nb_Btn)
            DeadMenuSelected=0;
        else
            DeadMenuSelected++;

        dMenu[DeadMenuSelected].setTexture(btnTexture[DeadMenuSelected+2], true);

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !this->enterKey)
    {
        return DeadMenuSelected;
    }

    this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);

    return -1;
}

void DeadView::render()
{
    this->gm->getWindow()->draw(spriteBackground);
    this->gm->getWindow()->draw(spriteDeadMenu);
    this->gm->getWindow()->draw(gameOverText);
    this->gm->getWindow()->draw(scoreText);

    dMenu[0].setTexture(btnTexture[0]);
    dMenu[1].setTexture(btnTexture[1]);
    dMenu[0].setOrigin(dMenu[0].getGlobalBounds().width/2., dMenu[0].getGlobalBounds().height/2.);
    dMenu[1].setOrigin(dMenu[1].getGlobalBounds().width/2., dMenu[1].getGlobalBounds().height/2.);
    dMenu[DeadMenuSelected].setTexture(btnTexture[DeadMenuSelected+2], true);

    for(int i=0;i<Nb_Btn;i++){
        this->gm->getWindow()->draw(dMenu[i]);
    }
}
