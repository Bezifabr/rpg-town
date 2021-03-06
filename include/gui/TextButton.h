#ifndef GUI_TEXT_BUTTON_H
#define GUI_TEXT_BUTTON_H

#include <SFML/Graphics/Text.hpp>
#include "Button.h"

namespace gui {
	class TextButton : public Button
	{
		sf::Text text;
	public:

		virtual void SetPosition(float x, float y) override;
		virtual void SetPosition(sf::Vector2f pos) override;

		void SetTextFont(const sf::Font& font);
		void SetTextColor(sf::Color color);
		void SetTextSize(unsigned int size);
		void SetTextString(const std::string& string);


		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	};
}
#endif // GUI_TEXT_BUTTON_H