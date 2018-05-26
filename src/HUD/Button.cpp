#include "HUD/Button.h"
#include <string>

HUD::Button::Button()
{
	init();
}

HUD::Button::Button(const std::string string, sf::Font & font, sf::Vector2f position)
{
	setString(string);
	setFont(font);
	setPosition(position);
	init();
}

bool HUD::Button::isPressed()
{
	if(buttonPressed)
	{
		buttonPressed = false;
		return true;
	}
	return false;
}

void HUD::Button::setColor(sf::Color color)
{
	text.setFillColor(color);
}

void HUD::Button::setSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void HUD::Button::setString(std::string text)
{
	this->text.setString(text);
}

void HUD::Button::setFont(sf::Font& font)
{
	this->font = font;
	text.setFont(this->font);
}

void HUD::Button::setPosition(sf::Vector2f position)
{
	setPosition(position.x, position.y);
}

void HUD::Button::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
	setTextPosition();
}

void HUD::Button::setTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);;
}

void HUD::Button::update()
{
	setTextPosition();

}

void HUD::Button::handleEvent(sf::Event & event, sf::Vector2f mousePosition)
{	

	bool mouseInSprite = sprite.getGlobalBounds().contains(mousePosition);

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && mouseInSprite == true)
	{
		buttonPressed = true;
	}
}

void HUD::Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
	target.draw(text,states);
}

void HUD::Button::init()
{
	text.setString("Sample text");
	setTextPosition();
}

void HUD::Button::setTextPosition()
{
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2,
	 sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2 - 10);
}

sf::Vector2f HUD::Button::getPosition()
{
	return sprite.getPosition();
}

sf::FloatRect HUD::Button::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void HUD::Button::setOriginToCenter()
{
	sf::Vector2f center = sf::Vector2f(
		sprite.getLocalBounds().left + sprite.getLocalBounds().width/2, 
		sprite.getLocalBounds().top + sprite.getLocalBounds().height/2);
	sprite.setOrigin(center);
}

const std::string& HUD::Button::getCode()
{
	return code;
}

void HUD::Button::setCode(const std::string& code)
{
	this->code = code;
}