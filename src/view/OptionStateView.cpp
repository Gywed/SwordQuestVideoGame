#include "view/OptionStateView.h"

OptionStateView::OptionStateView(GameManagerView* gm)
{
    //ctor
    this->gm = gm;
    init(gm->getWindow());
}

OptionStateView::~OptionStateView()
{
    //dtor
    delete sliderVolume;
}

OptionStateView::OptionStateView(const OptionStateView& other)
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
    sliderVolume = new SliderSFML(window->getSize().x/2-50,100);
    sliderVolume->create(0, 100);
    sliderVolume->setSliderValue(50.);
}
void OptionStateView::run(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        gm->getSound()->setVolume(sliderVolume->getSliderValue());
    }

}
void OptionStateView::render(sf::RenderWindow* window)
{
    window->clear();
    sliderVolume->draw(*window);
    window->display();
}
void OptionStateView::destroy() {}
