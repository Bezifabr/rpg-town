#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Button : public sf::Drawable
{
    bool clicked = false;
    bool pressed = false;
    sf::Sprite sprite;

  public:
    bool HandleClick(sf::Event event);
    bool IsClicked();

    void SetPosition(sf::Vector2f pos);
    void SetPosition(float x, float y);

    void SetTexture(const sf::Texture& texture);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // BUTTON_H