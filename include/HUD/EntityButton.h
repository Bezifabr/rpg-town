#ifndef HUD_ENTITY_BUTTON_H
#define HUD_ENTITY_BUTTON_H

#include "Entity.h"

namespace HUD {

	class EntityButton : public Entity
	{
		std::string code;
	public:
		EntityButton(const std::string& name, const std::string& textureSource);

		void SetPosition(sf::Vector2f position);
		void SetPosition(float x, float y);

		void CheckIfIsClicked(sf::Event event, sf::Vector2i mousePosition);
		void ChangeClickableArea(sf::FloatRect clickableArea);

		bool IsPressed();
		bool IsReleased();

	private:
		virtual void OnRefresh() override;

	};
}

#endif // HUD_ENTITY_BUTTON_H