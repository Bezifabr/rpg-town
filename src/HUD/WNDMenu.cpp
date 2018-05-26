#include "HUD/WNDMenu.h"

void HUD::WNDMenu::OnInitialize()
{
    closeBTN.loadFromFile("resources/CloseWindowBTN.png");
    close.setTexture(closeBTN);

	sf::Vector2f closePos = convertToWindowPosition(450, 15);

    close.setPosition(closePos);
}

void HUD::WNDMenu::update()
{
    if(close.isPressed())
        setOpened(false);
}

void HUD::WNDMenu::handleEvent(sf::Event& event, sf::Vector2f mousePosition)
{
    
    
    close.handleEvent(event,mousePosition);
}

void HUD::WNDMenu::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(close,states);
}