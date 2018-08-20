#ifndef HUD_TEXT_BUTTON_H
#define HUD_TEXT_BUTTON_H

#include "HUD/EntityButton.h"
#include <SFML/Graphics/Font.hpp>

namespace HUD {

	class TextButton : public EntityButton
	{
	public:
		TextButton(const std::string& name, const std::string& textureSource);

		void SetString(const std::string& string);
		void SetFont(sf::Font* font);
		void SetFontSize(uint8_t fontSize);
		void SetColor(sf::Color color);

		void SetTextToCenter();
	};
}

#endif // HUD_TEXT_BUTTON_H