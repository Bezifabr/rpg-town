#include "HUD/TextButton.h"
#include "Components/TextComponent.h"
#include "Components/SpriteComponent.h"

HUD::TextButton::TextButton(const std::string & name, const std::string & textureSource)
	: EntityButton(name, textureSource)
{
	AddComponent<TextComponent>();
}

void HUD::TextButton::SetString(const std::string & string)
{
	GetComponent<TextComponent>().SetString(string);
}

void HUD::TextButton::SetFont(sf::Font * font)
{
	GetComponent<TextComponent>().SetFont(font);
}

void HUD::TextButton::SetFontSize(uint8_t fontSize)
{
	GetComponent<TextComponent>().SetFontSize(fontSize);
}

void HUD::TextButton::SetColor(sf::Color color)
{
	GetComponent<TextComponent>().SetColor(color);
}

void HUD::TextButton::SetTextToCenter()
{
	GetComponent<TextComponent>().SetPositionToCenter(GetComponent<SpriteComponent>().sprite.getGlobalBounds());
}