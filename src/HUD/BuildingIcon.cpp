#include "HUD/BuildingIcon.h"


void HUD::BuildingIcon::setBuildingPosition()
{
    sf::Vector2f newPosition = sf::Vector2f(
    getGlobalBounds().left, 
    getGlobalBounds().top);
    graphic.setPosition(newPosition);
}

void HUD::BuildingIcon::loadBuildingTexture(const std::string& source)
{
    this->texture.loadFromFile(source);
    graphic.setTexture(texture);
    setBuildingPosition();
}

void HUD::BuildingIcon::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(graphic, states);
}