#include "gui/TextButton.h"

namespace gui {
	void TextButton::SetPosition(sf::Vector2f pos)
	{
		SetPosition(pos.x, pos.y);
	}

	void TextButton::SetPosition(float x, float y)
	{
		sprite.setPosition(x, y);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		text.setPosition(
			sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2,
			sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2);
	}

	void TextButton::SetTextFont(const sf::Font& font)
	{
		text.setFont(font);
	}

	void TextButton::SetTextColor(sf::Color color)
	{
		text.setFillColor(color);
	}

	void TextButton::SetTextSize(unsigned int size)
	{
		text.setCharacterSize(size);
	}

	void TextButton::SetTextString(const std::string& string)
	{
		text.setString(string);
	}

	void TextButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(sprite, states);
		target.draw(text, states);
	}
}