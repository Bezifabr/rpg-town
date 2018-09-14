#include "Button.h"
#include <iostream>
using namespace std;

bool Button::HandleClick(sf::Event event)
{
    clicked = false;
    if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && event.mouseButton.button == sf::Mouse::Left)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            pressed = true;
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (pressed)
                clicked = true;
            pressed = false;
        }
    }

    return clicked;
}

void Button::Refresh()
{
	clicked = false;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void Button::SetPosition(sf::Vector2f pos)
{
    SetPosition(pos.x, pos.y);
}

void Button::SetPosition(float x, float y)
{
    sprite.setPosition(x,y);
}

void Button::SetTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
}