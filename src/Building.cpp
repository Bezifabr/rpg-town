#include "Building.h"

Building::Building(const Building& b)
{
    texture = b.texture;
    sprite = b.sprite;
    sprite.setTexture(texture);
}

sf::Drawable& Building::GetDrawable()
{
    return sprite;
}

void Building::LoadTexture(const std::string& source)
{
    texture.loadFromFile(source);
    sprite.setTexture(texture);
}

sf::Transformable& Building::GetTranformable()
{
    return sprite;
}