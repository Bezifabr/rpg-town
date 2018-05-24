#ifndef BUTTON_H
#define BUTTON_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace UI
{

	class Button : public sf::Drawable
	{
		sf::Text text;
		sf::Font font;
		sf::Sprite sprite;

		bool buttonPressed = false;

	public:
		Button();
		Button(const std::string string, sf::Font& font, sf::Vector2f position);

		bool isPressed();

		void setColor(sf::Color color);
		void setSize(unsigned int size);
		void setString(std::string text);
		void setFont(sf::Font& font);

		void setPosition(sf::Vector2f position);
		void setPosition(float x, float y);

		sf::Vector2f getPosition();

		void setTexture(const sf::Texture& texture);

		void update();
		void handleEvent(sf::Event& event, sf::Vector2f mousePosition);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		void init();

		void setTextPosition();
	};
}

#endif