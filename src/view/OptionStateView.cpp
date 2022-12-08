#include "view/OptionStateView.h"

OptionStateView::OptionStateView(GameManagerView* gm):StateView(gm)
{
    //ctor
}

OptionStateView::~OptionStateView()
{
    //dtor
    delete sliderVolume;
}

OptionStateView::OptionStateView(const OptionStateView& other):StateView(other)
{
    //copy ctor
}

OptionStateView& OptionStateView::operator=(const OptionStateView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void OptionStateView::init(sf::RenderWindow* window)
{
    // Background image
    this->background.setSize(Vector2f(window->getSize().x,window->getSize().y));
    this->optionTexture.loadFromFile("images/bk.png");
    this->background.setTexture(&optionTexture);

    // Grey background
    this->greyRectangle.setSize(Vector2f(window->getSize().x*0.9,window->getSize().y*0.9));
    this->greyRectangleTexture.loadFromFile("images/WhiteBG.png");
    this->greyRectangle.setTexture(&greyRectangleTexture);
    this->greyRectangle.setFillColor(Color(128,128,128,128));
    this->greyRectangle.setPosition(window->getSize().x*0.05,window->getSize().y*0.05);

    // Volume text
    if (!globalFont.loadFromFile("Fonts/Berlin_Sans_FB_Demi_Bold.ttf"))
		std::cout << "Error loading font\n";

    volumeText.setString("Volume : ");
    volumeText.setFont(globalFont);
	volumeText.setFillColor(sf::Color::White);
	volumeText.setOutlineColor(sf::Color::Black);
    volumeText.setOutlineThickness(7.);
    volumeText.setCharacterSize(100);
    volumeText.setPosition(window->getSize().x*0.1,(window->getSize().y-volumeText.getGlobalBounds().height)*0.2);

    // Volume slider
    sliderVolume = new SliderSFML(window->getSize().x*0.11+volumeText.getGlobalBounds().width,window->getSize().y*0.2+40);
    sliderVolume->create(0, 100);
    sliderVolume->setSliderValue(50.);

    // KeyBinding
    keyBindingTexture.loadFromFile("images/keybinding.png");
    keyBindingSprite.setTexture(keyBindingTexture);
    keyBindingSprite.setScale(0.5,0.5);
    keyBindingSprite.setPosition((window->getSize().x-keyBindingSprite.getGlobalBounds().width)/2-100,window->getSize().y*0.4);

}


void OptionStateView::run(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        gm->getSound()->setVolume(sliderVolume->getSliderValue());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->gm->setState(EnumState::MENUSTATE);
    }

}
void OptionStateView::render(sf::RenderWindow* window)
{
    window->clear();
    window->draw(background);
    window->draw(greyRectangle);
    window->draw(volumeText);
    sliderVolume->draw(*window);
    window->draw(keyBindingSprite);
    window->display();
}
