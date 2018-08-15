#ifndef CLICKABLE_COMPONENT_H
#define CLICKABLE_COMPONENT_H

#include "Component.h"

class ClickableComponent : public Component
{
    sf::FloatRect clickableArea;
    bool isClickable;

    bool isPressed = false;
    bool isReleased = false;
public:
    ClickableComponent(sf::FloatRect clickableArea = {0,0,0,0}, bool isClickable = true);

    virtual void Refresh();

    void CheckIfIsClicked(sf::Event event, sf::Vector2i mousePosition);
        
    bool IsPressed();
    bool IsReleased();

    void ChangeClickableArea(sf::FloatRect clickableArea);
};

#endif // CLICKABLE_COMPONENT_H