#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>

class TextComponent : public Component
{
	sf::Text text;
	sf::Font* font;
public:
	TextComponent(const std::string& string, sf::Font* font);
	TextComponent(const std::string& string, sf::Font* font, sf::Vector2f position);
	TextComponent(const std::string& string, sf::Font* font, sf::Vector2f position, uint8_t fontSize);
	TextComponent(const std::string& string, sf::Font* font, sf::Vector2f position, uint8_t fontSize, sf::Color fontColor);

	void SetString(const std::string& string);
	void SetPosition(sf::Vector2f pos);
	void SetFont(sf::Font* font);
	void SetFontSize(uint8_t fontSize);
	void SetColor(sf::Color color);

	virtual void Draw(sf::RenderTarget* target);
};


#endif // TEXT_COMPONENT_H