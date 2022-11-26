#include <iostream>
#include "MainHero.h"
#include "GameManagerView.h"
#include <unistd.h>

using namespace std;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SwordQuest",sf::Style::Titlebar | sf::Style::Fullscreen);
    GameManagerView *gm = new GameManagerView();
    gm->setWindow(window);
    gm->setState(EnumState::MENUSTATE);

    while (window->isOpen())
    {
//        sf::Event event;
//        while (window->pollEvent(event))
//        {
//            switch(event.type) {
//              case sf::Event::Closed:  window->close();  break;
//              default: break;
//            }
//        }
        window->clear();
        gm->run();
        gm->render();
        window->display();

    }


    delete window;
    delete gm;

    return 0;
}
