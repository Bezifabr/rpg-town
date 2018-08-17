#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace HUD
{

	class Button : public sf::Drawable
	{
		sf::Text text;
		sf::Font font;
		sf::Sprite sprite;
		std::string code;

		bool buttonPressed = false;

	public:
		Button(const std::string& name = "");
		Button(const std::string& name, const std::string string, sf::Font& font, sf::Vector2f position);
		Button(const std::string string, sf::Font& font, sf::Vector2f position);

		bool IsPressed();

		const std::string& GetCode();
		void SetCode (const std::string& code);

		void setOriginToCenter();

		void setColor(sf::Color color);
		void setSize(unsigned int size);
		void setString(std::string text);
		void setFont(sf::Font& font);

		void setPosition(sf::Vector2f position);
		void setPosition(float x, float y);

		sf::Vector2f getPosition();
		sf::FloatRect getGlobalBounds();

		void setTexture(const sf::Texture& texture);

		void HandleEvent(sf::Event& event, sf::Vector2f mousePosition);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		virtual void Update(sf::Time deltaTime);
	private:

		void Init();

		void SetTextPosition();

	protected:
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const {}
		
		virtual void OnSetPosition() {}
	};
}

#endif