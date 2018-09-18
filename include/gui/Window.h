#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "ButtonFunctionConnector.h"
#include <list>

namespace gui {
	class Window : public ButtonFunctionConnector
	{
		std::list<std::shared_ptr<sf::Drawable>> sprites;
	public:
		using ButtonFunctionConnector::Add;

		virtual void Add(std::shared_ptr<sf::Drawable> sprite);
		void Draw(std::shared_ptr<sf::RenderWindow> renderWindow);
	};
}

#endif // GUI_WINDOW_H
