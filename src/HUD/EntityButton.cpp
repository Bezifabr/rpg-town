#include "HUD/EntityButton.h"
#include "Components/SpriteComponent.h"
#include "Components/ClickableComponent.h"


HUD::EntityButton::EntityButton(const std::string & name, const std::string & textureSource) : Entity(name)
{
	AddComponent<SpriteComponent>(textureSource);
	AddComponent<ClickableComponent>(GetComponent<SpriteComponent>().sprite.getGlobalBounds());
}

void HUD::EntityButton::SetPosition(sf::Vector2f position)
{
	SetPosition(position.x, position.y);
}

void HUD::EntityButton::SetPosition(float x, float y)
{
	GetComponent<SpriteComponent>().sprite.setPosition(x, y);
}

void HUD::EntityButton::CheckIfIsClicked(sf::Event event, sf::Vector2i mousePosition)
{
	GetComponent<ClickableComponent>().CheckIfIsClicked(event, mousePosition);
}

void HUD::EntityButton::ChangeClickableArea(sf::FloatRect clickableArea)
{
	GetComponent<ClickableComponent>().ChangeClickableArea(clickableArea);
}

bool HUD::EntityButton::IsPressed()
{
	return GetComponent<ClickableComponent>().IsPressed();
}

bool HUD::EntityButton::IsReleased()
{
	return GetComponent<ClickableComponent>().IsReleased();
}

void HUD::EntityButton::OnRefresh()
{
	GetComponent<ClickableComponent>().Refresh();
}
