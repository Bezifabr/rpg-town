#include "Components/ClickableComponent.h"

ClickableComponent::ClickableComponent(sf::FloatRect clickableArea, bool isClickable) 
    : clickableArea(clickableArea), isClickable(isClickable)
{

}

 void ClickableComponent::Refresh()
{
       isReleased = false;
}

void ClickableComponent::CheckIfIsClicked(sf::Event event, sf::Vector2i mousePosition)
{
    if(clickableArea.contains(sf::Vector2f(mousePosition.x, mousePosition.y)))
    {
        if(event.type == sf::Event::MouseButtonReleased)    
		{
			if(isPressed == true) 
				isReleased = true; 
			isPressed = false;
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			isPressed = true;
			isReleased = false;
		}
    }
	else
		isPressed = false;
}

bool ClickableComponent::IsPressed()
{
    return isPressed;
}

bool ClickableComponent::IsReleased()
{
    return isReleased;
}

void ClickableComponent::ChangeClickableArea(sf::FloatRect clickableArea)
{
    this->clickableArea = clickableArea;
}
