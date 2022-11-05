#include "OptionScreen.h"

OptionScreen::OptionScreen()
{
    //ctor
}

OptionScreen::~OptionScreen()
{
    //dtor
}

OptionScreen::OptionScreen(const OptionScreen& other)
{
    //copy ctor
}

OptionScreen& OptionScreen::operator=(const OptionScreen& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int OptionScreen::Run(sf::RenderWindow *App){

    sf::Event ev;
    bool Running = true;

    while(Running){
        //Verifying events
		while (App->pollEvent(ev))
		{
            // Window closed
            if (ev.type == sf::Event::Closed)
            {
                App->close();
                return (-1);
            }

            //Key pressed
			if (ev.type == sf::Event::KeyPressed)
			{
				switch (ev.key.code)
                {
                // If escape is pressed, close the application
//                case  sf::Keyboard::Escape : App->close(); return (-1);break;
                case  sf::Keyboard::Escape : return 0;break;
                default : break;
                }
            }
        }
        // Clear the window and apply grey background
        App->clear( sf::Color(127,127,127));
		//Drawing
		App->display();
    }




    //Never reaching this point normally, but just in case, exit the application
    return -1;
}