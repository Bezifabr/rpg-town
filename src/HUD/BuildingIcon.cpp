#include "HUD/BuildingIcon.h"


void HUD::BuildingIcon::OnSetPosition()
{
    sf::Vector2f newPosition = sf::Vector2f(
    getGlobalBounds().left + (graphic.getGlobalBounds().width / 100) * 10, 
    getGlobalBounds().top + (graphic.getGlobalBounds().height / 100) * 10);
    graphic.setPosition(newPosition);
}

void HUD::BuildingIcon::loadBuildingTexture(const std::string& source)
{
    this->texture.loadFromFile(source);
    graphic.setTexture(texture);
    OnSetPosition();
}

void HUD::BuildingIcon::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(graphic, states);
}