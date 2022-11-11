#include "PlayScreen.h"

//Sprite speed
#define SPRITE_SPEED 0.1

// Size of Sprite
#define Sprite_Width 96
#define Sprite_Height 104

//// Define not moving sprite for each position
#define Sprite_Right 312
#define Sprite_Left 104
#define Sprite_Back 208
#define Sprite_Front 0
//
//// Define moving sprite for each position
#define Sprite_Right_Moving 728
#define Sprite_Left_Moving 520
#define Sprite_Back_Moving 624
#define Sprite_Front_Moving 416
#define Sprite_Changing_Step 96
#define Sprite_Changing_Left_Max 864

PlayScreen::PlayScreen(void)
{
    //ctor
    movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

PlayScreen::~PlayScreen()
{
    //dtor
}

PlayScreen::PlayScreen(const PlayScreen& other)
{
    //copy ctor
}

PlayScreen& PlayScreen::operator=(const PlayScreen& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int PlayScreen::Run(sf::RenderWindow *App){

    // ::: Load texture :::

    // Create texture from PNG file
    sf::Texture texture;
    if (!texture.loadFromFile("images/SpriteSheet.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }
    texture.setSmooth(true);

    // ::: Create sprite and apply texture :::
    sf::IntRect rectSourceSprite(0, 0, Sprite_Width, Sprite_Height);
    sf::Sprite sprite(texture,rectSourceSprite);
    sprite.setScale(.8,.8);
    sf::FloatRect spriteSize=sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);

    // ::: Main loop :::

    // Sprite coordinates
    float x=App->getSize().x/2.;
    float y=App->getSize().y/2.;


	sf::Event ev;
	bool Running = true;

	//Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;

    sf::Clock timer;
	while (Running)
	{
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rightFlag=true;
            startSpriteMovementAnimation(sprite, Sprite_Right_Moving, timer);

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            upFlag=true;
            startSpriteMovementAnimation(sprite, Sprite_Back_Moving, timer);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            leftFlag=true;
            startSpriteMovementAnimation(sprite, Sprite_Left_Moving, timer);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            downFlag=true;
            startSpriteMovementAnimation(sprite, Sprite_Front_Moving, timer);

        }
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
                case  sf::Keyboard::Escape :  App->close();return (-1);break;


                default : break;
                }
			}
			// If a key is released
            if (ev.type == sf::Event::KeyReleased)
            {
                switch (ev.key.code)
                {
                // Process the up, down, left and right keys
                case sf::Keyboard::Up :     upFlag=false; rectSourceSprite.left=0;rectSourceSprite.top=Sprite_Back; break;
                case sf::Keyboard::Down:    downFlag=false; rectSourceSprite.left=0;rectSourceSprite.top=Sprite_Front; break;
                case sf::Keyboard::Left:    leftFlag=false; rectSourceSprite.left=0;rectSourceSprite.top=Sprite_Left;break;
                case sf::Keyboard::Right:   rightFlag=false; rectSourceSprite.left=0;rectSourceSprite.top=Sprite_Right;break;
                default : break;
                }
                sprite.setTextureRect(rectSourceSprite);
            }
		}

        // Update coordinates
        if (leftFlag){
            x-=SPRITE_SPEED;
//            sprite.setTextureRect(sf::IntRect(0, Sprite_Left, Sprite_Width, Sprite_Height));

        }
        if (rightFlag){
            x+=SPRITE_SPEED;
//            sprite.setTextureRect(sf::IntRect(0, Sprite_Right, Sprite_Width, Sprite_Height));
        }
        if (upFlag){
            y-=SPRITE_SPEED;
//            sprite.setTextureRect(sf::IntRect(0, Sprite_Back, Sprite_Width, Sprite_Height));


        }
        if (downFlag){
            y+=SPRITE_SPEED;
//            sprite.setTextureRect(sf::IntRect(0, Sprite_Front, Sprite_Width, Sprite_Height));
        }

        // Check screen boundaries
        if (x<0) x=0;
        if (x>(float)App->getSize().x) x=App->getSize().x;
        if (y<0) y=0;
        if (y>(float)App->getSize().y) y=App->getSize().y;

        // Clear the window and apply grey background
        App->clear( sf::Color(127,127,127));

        // Rotate and draw the sprite
        sprite.setPosition(x,y);
		//Drawing
		App->draw(sprite);
		App->display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}

void PlayScreen::startSpriteMovementAnimation(sf::Sprite& sprite, int startingSpriteTop, sf::Clock& timer)
{
    sf::IntRect rectSourceSprite = sprite.getTextureRect();
    rectSourceSprite.top = startingSpriteTop;
    if (timer.getElapsedTime().asSeconds() > 0.09f){

        if (rectSourceSprite.left == Sprite_Changing_Left_Max)
            rectSourceSprite.left=0;
        else
            rectSourceSprite.left+=Sprite_Changing_Step;

        sprite.setTextureRect(rectSourceSprite);
        timer.restart();
    }

}
