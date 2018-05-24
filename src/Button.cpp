#include "Button.h"
#include <string>

UI::Button::Button()
{
	init();
}

UI::Button::Button(const std::string string, sf::Font & font, sf::Vector2f position)
{
	setString(string);
	setFont(font);
	setPosition(position);
	init();
}

bool UI::Button::isPressed()
{
	if(buttonPressed)
	{
		buttonPressed = false;
		return true;
	}
	return false;
}

void UI::Button::setColor(sf::Color color)
{
	text.setFillColor(color);
}

void UI::Button::setSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void UI::Button::setString(std::string text)
{
	this->text.setString(text);
}

void UI::Button::setFont(sf::Font& font)
{
	this->font = font;
	text.setFont(this->font);
}

void UI::Button::setPosition(sf::Vector2f position)
{
	setPosition(position);
}

void UI::Button::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
	setTextPosition();
}

void UI::Button::setTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);;
}

void UI::Button::update()
{
	setTextPosition();

}

void UI::Button::handleEvent(sf::Event & event, sf::Vector2f mousePosition)
{	

	bool mouseInSprite = sprite.getGlobalBounds().contains(mousePosition);

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && mouseInSprite == true)
	{
		buttonPressed = true;
	}
}

void UI::Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
	target.draw(text,states);
}

void UI::Button::init()
{
	text.setString("Sample text");
	setTextPosition();
}

void UI::Button::setTextPosition()
{
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height / 2 - 10);
}

sf::Vector2f UI::Button::getPosition()
{
	return sprite.getPosition();
}

sf::FloatRect UI::Button::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}