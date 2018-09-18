#include "gui\Window.h"

namespace gui {
	void Window::Add(std::shared_ptr<sf::Drawable> sprite)
	{
		sprites.emplace_back(sprite);
	}

	void Window::Draw(std::shared_ptr<sf::RenderWindow> renderWindow)
	{
		for (std::shared_ptr<sf::Drawable> sprite : sprites)
			renderWindow->draw(*sprite);

		ButtonFunctionConnector::Draw(renderWindow);
	}
}