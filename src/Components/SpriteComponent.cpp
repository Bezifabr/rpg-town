#include "Components/SpriteComponent.h"

SpriteComponent::SpriteComponent(const std::string& source)
{
    texture.loadFromFile(source);
    sprite.setTexture(texture);
}

void SpriteComponent::Draw(sf::RenderTarget& target)
{
    target.draw(sprite);
}