#include "MainMenu.h"

MainMenu::MainMenu(void)
{
    isPlay=false;
    isOption=false;
    isAbout=false;
    isQuit=false;
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

void MainMenu::clear(RenderWindow* window){
    window->clear();
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

int MainMenu::Run(sf::RenderWindow *App){

    sf::Event ev;
    bool Running = true;

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



    while(Running){
        //Verifying events
        while(App->pollEvent(ev)){

            //Window closed
            if(ev.type==sf::Event::Closed) return -1;


            //Escape to close the window
            // Will be deleted later
            if(ev.type==sf::Event::KeyPressed)
                if(ev.key.code==sf::Keyboard::Escape){
                        App->close();
                        return (-1);
                }




            if(ev.type==sf::Event::KeyReleased)
            {
                // Moving in the menu
                if(ev.key.code==sf::Keyboard::Up){
                    MoveUp();
                    break;
                }
                if(ev.key.code==sf::Keyboard::Down){
                    MoveDown();
                    break;
                }

                if(ev.key.code==sf::Keyboard::Return){
                    int menu = MainMenuPressed();
                    cout<<menu<<endl;
                    if(menu==0){
                        isPlay=true;
                        return (1);
                    }
                    else if(menu==1){
                        isOption=true;
                        return (2);
                    }
                    else if(menu==2){
                        isAbout=true;
                        return (3);
                    }
                    else{
                        App->close();
                        return (-1);
                    }
                    break;
                }

            }
        }

        App->clear();
        draw(App);
        App->display();
    }
    return (-1);
}

