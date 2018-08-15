#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

struct SpriteComponent : public Component
{
    SpriteComponent(const std::string& textureSource);

    sf::Texture texture;
    sf::Sprite sprite;
    virtual void Draw(sf::RenderTarget& target) override;

};

#endif // SPRITE_COMPONENT_H