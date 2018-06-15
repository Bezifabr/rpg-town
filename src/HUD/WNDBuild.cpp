#include "HUD/WNDBuild.h"

void HUD::WNDBuild::OnInitialize()
{
    textureBTN.loadFromFile("resources/BuildingSlot.png");

    test.setTexture(textureBTN);
    test.setOriginToCenter();
    test.setPosition(getCenterPosition().x, convertToWindowPosition(200,250).y);
    test.loadBuildingTexture("resources/Test/House.png");
}

void HUD::WNDBuild::update()
{
    test.update();
}

void HUD::WNDBuild::handleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
    test.handleEvent(event,mousePosition);
}

void HUD::WNDBuild::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(test,states);
}