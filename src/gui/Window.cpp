#include "gui\Window.h"

namespace gui {
	void Window::SetBackgroundTexture(const sf::Texture & texture)
	{
		this->background.setTexture(texture);
	}

	void Window::Draw(std::shared_ptr<sf::RenderWindow> renderWindow)
	{
		renderWindow->draw(background);
		ButtonFunctionConnector::Draw(renderWindow);
	}
}