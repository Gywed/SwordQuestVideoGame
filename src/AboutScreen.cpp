#include "AboutScreen.h"

AboutScreen::AboutScreen()
{
    //ctor
}

AboutScreen::~AboutScreen()
{
    //dtor
}

AboutScreen::AboutScreen(const AboutScreen& other)
{
    //copy ctor
}

AboutScreen& AboutScreen::operator=(const AboutScreen& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
int AboutScreen::Run(sf::RenderWindow *App){
    sf::Font font;
    if(!font.loadFromFile("Fonts/Typography.otf")){
        cout << "No Font is here";
    }

    credits[0].setFont(font);
    credits[0].setString("Alexandre Dujacquier");
    credits[0].setCharacterSize(70);
    credits[0].setPosition(700,175);

    credits[1].setFont(font);
    credits[1].setString("Yohan Noel-Huls");
    credits[1].setCharacterSize(70);
    credits[1].setPosition(600,325);

    credits[2].setFont(font);
    credits[2].setString("Nathan Tytgat");
    credits[2].setCharacterSize(70);
    credits[2].setPosition(700,475);

    credits[3].setFont(font);
    credits[3].setString("Pierre Gillebert");
    credits[3].setCharacterSize(70);
    credits[3].setPosition(600,625);

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
		for(int i = 0;i<4;i++){
            App->draw(credits[i]);
		}

		App->display();
    }




    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
