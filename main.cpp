//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>


// Size of Sprite
//#define Sprite_Width 96
//#define Sprite_Height 104

// Define not moving sprite for each position
//#define Sprite_Right 312
//#define Sprite_Left 104
//#define Sprite_Back 208
//#define Sprite_Front 0

// Define moving sprite for each position
//#define Sprite_Right_Moving 728
//#define Sprite_Left_Moving 520
//#define Sprite_Back_Moving 624
//#define Sprite_Front_Moving 416

// Demonstrate creating a spritesheet
//#include "SFML/Graphics.hpp"
//
//int main(int argc, char ** argv){
//  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
//
//  sf::Event event;
//  sf::Texture texture;
//  texture.loadFromFile("images/SpriteSheet.png");
//
//  sf::IntRect rectSourceSprite(0, 0, Sprite_Width, Sprite_Height);
//  sf::Sprite sprite(texture,rectSourceSprite);
//  sf::Clock clock;
//
//  while (renderWindow.isOpen()){
//    while (renderWindow.pollEvent(event)){
//      if (event.type == sf::Event::EventType::Closed)
//        renderWindow.close();
//    }
//
//    if (clock.getElapsedTime().asSeconds() > 3.0f){
//      if (rectSourceSprite.left == 192)
//        rectSourceSprite.left = 0;
//      else
//        rectSourceSprite.left += 96;
//
//      sprite.setTextureRect(rectSourceSprite);
//      clock.restart();
//    }
//
//
//    renderWindow.clear();
//    renderWindow.draw(sprite);
//    renderWindow.display();
//  }
//}




// SFML libraries
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <math.h>
//
//// Sprite speed (high values = high speed)
//#define         SPRITE_SPEED        5
//
//int main()
//{
//    // _____________________
//    // ::: Create window :::
//
//    // Create a window with the same pixel depth as the desktop
////    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SwordQuest");
////
////    sf::RenderWindow window(sf::VideoMode(  desktopMode.width,
////                                            desktopMode.height,
////                                            desktopMode.bitsPerPixel),
////                            "SFML part 3",
////                            sf::Style::Fullscreen);
//
//    // Enable vertical sync. (vsync)
//    window.setVerticalSyncEnabled (true);
//    // When a key is pressed, sf::Event::KeyPressed will be true only once
//    window.setKeyRepeatEnabled(false);
//
//    // ____________________
//    // ::: Load texture :::
//
//    // Create texture from PNG file
//    sf::Texture texture;
//    if (!texture.loadFromFile("images/SpriteSheet.png"))
//    {
//        std::cerr << "Error while loading texture" << std::endl;
//        return -1;
//    }
//
//    // Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
//    texture.setSmooth(true);
//
//    // _______________________________________
//    // ::: Create sprite and apply texture :::
//
//    // Create the sprite and apply the texture
//    sf::IntRect rectSourceSprite(0, Sprite_Front, Sprite_Width, Sprite_Height);
//    sf::Sprite sprite(texture,rectSourceSprite);
////    sf::Sprite sprite;
////    sprite.setTexture(texture);
//    sprite.setScale(.8,.8);
//    sf::FloatRect spriteSize=sprite.getGlobalBounds();
//
//    sprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
//
//        // _________________
//    // ::: Main loop :::
//
//    // Sprite coordinates
//    int x=window.getSize().x/2.;
//    int y=window.getSize().y/2.;
//
//    // Flags for key pressed
//    bool upFlag=false;
//    bool downFlag=false;
//    bool leftFlag=false;
//    bool rightFlag=false;
//
//    sf::Clock timer;
////    int left;
//    while (window.isOpen())
//    {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // Close the window if a key is pressed or if requested
//            if (event.type == sf::Event::Closed) window.close();
//
//            // If a key is pressed
//            if (event.type == sf::Event::KeyPressed)
//            {
//                switch (event.key.code)
//                {
//                // If escape is pressed, close the application
//                case  sf::Keyboard::Escape : window.close(); break;
//
//                // Process the up, down, left and right keys
////                case sf::Keyboard::Up :     upFlag=true; break;
//                case sf::Keyboard::Up:
//                    upFlag=true;
//                    rectSourceSprite.top = Sprite_Back_Moving;
//                    sprite.setTextureRect(rectSourceSprite);
////                    while(event.type == sf::Event::KeyPressed){
////                        if (timer.getElapsedTime().asSeconds() > 1.0f){
////
////                          if (rectSourceSprite.left == 864)
////                            rectSourceSprite.left=0;
////                          else
////                            rectSourceSprite.left+=96;
////
////                          sprite.setTextureRect(rectSourceSprite);
////                          timer.restart();
////                        }
////                    }
//
//
//                    break;
//
//
//
//                case sf::Keyboard::Down:    downFlag=true; break;
//                case sf::Keyboard::Left:    leftFlag=true; break;
//                case sf::Keyboard::Right:   rightFlag=true; break;
//                default : break;
//                }
//
//
//            }
//
//            // If a key is released
//            if (event.type == sf::Event::KeyReleased)
//            {
//                switch (event.key.code)
//                {
//                // Process the up, down, left and right keys
//                case sf::Keyboard::Up :     upFlag=false; rectSourceSprite.top=Sprite_Back; break;
//                case sf::Keyboard::Down:    downFlag=false; rectSourceSprite.top=Sprite_Front; break;
//                case sf::Keyboard::Left:    leftFlag=false; rectSourceSprite.top=Sprite_Left;break;
//                case sf::Keyboard::Right:   rightFlag=false; rectSourceSprite.top=Sprite_Right;break;
//                default : break;
//                }
//                sprite.setTextureRect(rectSourceSprite);
//            }
//        }
//
//        // Update coordinates
//        if (leftFlag){
//            x-=SPRITE_SPEED;
////            sprite.setTextureRect(sf::IntRect(0, Sprite_Left, Sprite_Width, Sprite_Height));
//
//        }
//        if (rightFlag){
//            x+=SPRITE_SPEED;
////            sprite.setTextureRect(sf::IntRect(0, Sprite_Right, Sprite_Width, Sprite_Height));
//        }
//        if (upFlag){
//            y-=SPRITE_SPEED;
////            sprite.setTextureRect(sf::IntRect(0, Sprite_Back, Sprite_Width, Sprite_Height));
//
//
//        }
//        if (downFlag){
//            y+=SPRITE_SPEED;
////            sprite.setTextureRect(sf::IntRect(0, Sprite_Front, Sprite_Width, Sprite_Height));
//        }
//
//        // Check screen boundaries
//        if (x<0) x=0;
//        if (x>(int)window.getSize().x) x=window.getSize().x;
//        if (y<0) y=0;
//        if (y>(int)window.getSize().y) y=window.getSize().y;
//
//        // Clear the window and apply grey background
//        window.clear( sf::Color(127,127,127));
//
//        // Rotate and draw the sprite
//        sprite.setPosition(x,y);
////        sprite.setRotation( timer.getElapsedTime().asSeconds() / M_PI * 90.f );
//        window.draw(sprite);
//
//        // Update display and wait for vsync
//        window.display();
//    }
//    return 0;
//}






#include <iostream>
#include "Character.h"
#include "GameManagerView.h"

using namespace std;

int main()
{
//    Character c;
//    cout<<c.str();
//    Game game;
//    game.run();
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1900, 1080), "SwordQuest",sf::Style::Titlebar | sf::Style::Fullscreen);
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
