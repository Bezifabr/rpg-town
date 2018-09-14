#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "ButtonFunctionConnector.h"

namespace gui {
	class Window : public ButtonFunctionConnector
	{
		sf::Sprite background;
	public:
		void SetBackgroundTexture(const sf::Texture& texture);

		void Draw(std::shared_ptr<sf::RenderWindow> renderWindow);
	};
}

#endif // GUI_WINDOW_H
