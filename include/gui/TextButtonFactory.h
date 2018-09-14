#ifndef TEXT_BUTTON_FACTORY_H
#define TEXT_BUTTON_FACTORY_H

#include "gui/TextButton.h"
#include <memory>

namespace gui {
	class TextButtonFactory
	{
		TextButton prototype;
	public:
		TextButtonFactory(const TextButton& prototype);

		std::unique_ptr<TextButton> Create(const std::string& textString, sf::Vector2f position);
		std::unique_ptr<TextButton> Create(const std::string& textString, float x_pos, float y_pos);
	};
}

#endif // !TEXT_BUTTON_FACTORY_H
