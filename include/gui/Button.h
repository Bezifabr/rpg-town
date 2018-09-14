#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace gui {
	class Button : public sf::Drawable
	{
		bool clicked = false;
		bool pressed = false;

	public:
		virtual ~Button() {}

		bool HandleClick(sf::Event event);
		void Refresh();

		virtual void SetPosition(sf::Vector2f pos);
		virtual void SetPosition(float x, float y);

		void SetTexture(const sf::Texture &texture);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	protected:
		sf::Sprite sprite;
	};
}
#endif // GUI_BUTTON_H