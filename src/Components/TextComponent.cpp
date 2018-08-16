#include "Components/TextComponent.h"

TextComponent::TextComponent(const std::string & string, sf::Font* font)
		: font(font)
{
	text.setString(string);
	text.setFont((*font));
}

TextComponent::TextComponent(const std::string & string, sf::Font* font, sf::Vector2f position)
	: TextComponent(string, font)
{ 
    text.setPosition(position); 
}

TextComponent::TextComponent(const std::string & string, sf::Font* font, sf::Vector2f position, uint8_t fontSize)
	: TextComponent(string, font, position)
{
	text.setCharacterSize(fontSize);
}

TextComponent::TextComponent(const std::string & string, sf::Font* font, sf::Vector2f position, uint8_t fontSize, sf::Color fontColor)
	: TextComponent(string, font, position, fontSize)
{
	text.setFillColor(fontColor);
}

void TextComponent::SetString(const std::string & string)
{
	text.setString(string);
}

void TextComponent::SetPosition(sf::Vector2f pos)
{
	text.setPosition(pos);
}

void TextComponent::SetFont(sf::Font* font)
{
	this->font = font;
	text.setFont((*font));
}

void TextComponent::SetFontSize(uint8_t fontSize)
{
	text.setCharacterSize(fontSize);
}

void TextComponent::SetColor(sf::Color color)
{
	text.setFillColor(color);
}

void TextComponent::Draw(sf::RenderTarget & target)
{
	target.draw(text);
}