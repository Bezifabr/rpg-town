#include "gui/TextButtonFactory.h"

namespace gui {
	TextButtonFactory::TextButtonFactory(const gui::TextButton & prototype)
	{
		this->prototype = prototype;
	}

	std::unique_ptr<TextButton> gui::TextButtonFactory::Create(const std::string & textString, sf::Vector2f position)
	{
		return Create(textString, position.x, position.y);
	}

	std::unique_ptr<TextButton> gui::TextButtonFactory::Create(const std::string & textString, float x_pos, float y_pos)
	{
		auto result = std::make_unique<TextButton>(prototype);
		result->SetTextString(textString);
		result->SetPosition(x_pos, y_pos);
		return result;
	}
}