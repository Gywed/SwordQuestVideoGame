#include "SliderSFML.h"


SliderSFML::SliderSFML(int x, int y)
{
	xCord = x;
	yCord = y;
	axisHeight = 20;
	axisWidth = 1000;
	sliderWidth = 30;
	sliderHeight = 50;

	if (!font.loadFromFile("Fonts/Berlin_Sans_FB_Demi_Bold.ttf"))
		std::cout << "Error loading font\n";

	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2.);

	axis.setPosition(x, y);
	axis.setOrigin(0, axisHeight / 2);
	axis.setSize(sf::Vector2f(axisWidth, axisHeight));
	axis.setFillColor(sf::Color(63,63,63));
	slider.setPosition(x, y);
	slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
	slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
	slider.setFillColor(sf::Color::White);
    slider.setOutlineColor(sf::Color::Black);
    slider.setOutlineThickness(2.);
}

sf::Text SliderSFML::returnText(int x, int y, std::string z, int fontSize)
{
	text.setCharacterSize(fontSize);
	text.setPosition(x, y);
	text.setString(z);
	return text;
}

void SliderSFML::create(int min, int max)
{
	sliderValue = min;
	minValue = min;
	maxValue = max;
}

void SliderSFML::logic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        setSliderValue(sliderValue+5);
        sleep(sf::milliseconds(100));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        setSliderValue(sliderValue-5);
        sleep(sf::milliseconds(100));
    }

//	if (slider.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
//		&& sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
//	{
//		if (sf::Mouse::getPosition(window).x >= xCord && sf::Mouse::getPosition(window).x <= xCord + axisWidth)
//		{
//			slider.setPosition(sf::Mouse::getPosition(window).x, yCord);
//			sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
//		}
//	}
}

float SliderSFML::getSliderValue()
{
	return sliderValue;
}

int SliderSFML::getSliderWith() const
{
    return sliderWidth;
}

void SliderSFML::setSliderValue(float newValue)
{
	if (newValue >= minValue && newValue <= maxValue)
	{
		sliderValue = newValue;
		float diff = maxValue - minValue;
		float diff2 = newValue - minValue;
		float zzz = axisWidth / diff;
		float posX = zzz*diff2;
		posX += xCord;
		slider.setPosition(posX, yCord);
	}
}

void SliderSFML::setSliderPercentValue(float newPercentValue)
{
	if (newPercentValue >= 0 && newPercentValue <= 100)
	{
		sliderValue = newPercentValue / 100 * maxValue;
		slider.setPosition(xCord + (axisWidth*newPercentValue / 100), yCord);
	}
}

void SliderSFML::draw(sf::RenderWindow &window)
{
	logic(window);
	window.draw(returnText(xCord - 10, yCord + 5, std::to_string(minValue), 20));
	window.draw(axis);
	window.draw(returnText(xCord + axisWidth - 10, yCord + 5, std::to_string(maxValue), 20));
	window.draw(slider);
	window.draw(returnText(slider.getPosition().x - sliderWidth, slider.getPosition().y - (sliderHeight+5),
		std::to_string((int)sliderValue), 15));
}
