#include "Components/TextComponent.h"
#include "Entity.h"
#include <stdexcept>

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
	text.setOrigin(0, 0);
	text.setPosition(pos);
}

void TextComponent::SetPositionToCenter(sf::FloatRect rect)
{
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(rect.left + rect.width / 2, rect.top + rect.height / 2 - 10);
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
	if (font != nullptr) {} else throw std::runtime_error("Text component from " + entity->GetName() + " has no font!");
	if (text.getString() != "") {} else throw std::runtime_error("Text component from " + entity->GetName() + " has no string!");

		target.draw(text);
}