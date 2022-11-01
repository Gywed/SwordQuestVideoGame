#include "MainMenu.h"

MainMenu::MainMenu(float width,float height)
{
    //ctor
    // Set Font
    if(!font.loadFromFile("Fonts/GrinchedRegular.otf")){
        cout << "No Font is here";
    }

    //Set the background
    this->background.setSize(Vector2f(1920,1080));
    this->mainTexture.loadFromFile("images/MainMenu/background.png");
    this->background.setTexture(&mainTexture);


    //Set all images for each Button
    btnTexture[0].loadFromFile("images/MainMenu/btnPlay.png");
    btnTexture[1].loadFromFile("images/MainMenu/btnOption.png");
    btnTexture[2].loadFromFile("images/MainMenu/btnAbout.png");
    btnTexture[3].loadFromFile("images/MainMenu/btnExit.png");
    btnTexture[4].loadFromFile("images/MainMenu/btnPlayHover.png");
    btnTexture[5].loadFromFile("images/MainMenu/btnOptionHover.png");
    btnTexture[6].loadFromFile("images/MainMenu/btnAboutHover.png");
    btnTexture[7].loadFromFile("images/MainMenu/btnExitHover.png");

    //Button Play
    mMenu[0].setTexture(btnTexture[0]);
    mMenu[0].setPosition(750,400);

    //Button Option
    mMenu[1].setTexture(btnTexture[1]);
    mMenu[1].setPosition(750,500);

    //Button About
    mMenu[2].setTexture(btnTexture[2]);
    mMenu[2].setPosition(750,600);

    //Button Exit
    mMenu[3].setTexture(btnTexture[3]);
    mMenu[3].setPosition(750,700);

    //Old Menu Text
    //Play
//    mainMenu[0].setFont(font);
//    mainMenu[0].setFillColor(Color::Black);
//    mainMenu[0].setString("Play");
//    mainMenu[0].setCharacterSize(70);
//    mainMenu[0].setPosition(800,400);

    //Options
//    mainMenu[1].setFont(font);
//    mainMenu[1].setFillColor(Color::Black);
//    mainMenu[1].setString("Options");
//    mainMenu[1].setCharacterSize(70);
//    mainMenu[1].setPosition(800,500);

    //About
//    mainMenu[2].setFont(font);
//    mainMenu[2].setFillColor(Color::Black);
//    mainMenu[2].setString("About");
//    mainMenu[2].setCharacterSize(70);
//    mainMenu[2].setPosition(800,600);

    //Exit
//    mainMenu[3].setFont(font);
//    mainMenu[3].setFillColor(Color::Black);
//    mainMenu[3].setString("Exit");
//    mainMenu[3].setCharacterSize(70);
//    mainMenu[3].setPosition(800,700);
}

MainMenu::~MainMenu()
{
    //dtor
}

MainMenu::MainMenu(const MainMenu& other)
{
    //copy ctor
}

MainMenu& MainMenu::operator=(const MainMenu& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MainMenu::draw(RenderWindow* window){

    //Set the background on the window
    window->draw(this->background);

    //Set up all button
    for(int i=0;i<Max_main_menu;i++){
//        window->draw(mainMenu[i]);
        window->draw(mMenu[i]);
    }
//    mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
    //Set the selected button
    mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);


//    window->draw(mMenu);
}

//Move up in Menu
void MainMenu::MoveUp(){
    if(MainMenuSelected-1>=0){
//        mainMenu[MainMenuSelected].setFillColor(Color::Black);
        mMenu[MainMenuSelected].setTexture(btnTexture[MainMenuSelected]);
        MainMenuSelected--;

//        mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
        mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);
    }
}

//Move down in Menu
void MainMenu::MoveDown(){
    if(MainMenuSelected+1<=Max_main_menu){
//        mainMenu[MainMenuSelected].setFillColor(Color::Black);
        mMenu[MainMenuSelected].setTexture(btnTexture[MainMenuSelected]);
//        MainMenuSelected++;
        if(MainMenuSelected<3){
            MainMenuSelected++;
        }
//        mainMenu[MainMenuSelected].setFillColor(Color::Yellow);
        mMenu[MainMenuSelected].setTexture(btnTexture[4+MainMenuSelected]);
    }
}

