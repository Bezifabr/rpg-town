#include "Building.h"

Building::Building(const Building& b)
{
    texture = b.texture;
    sprite = b.sprite;
    sprite.setTexture(texture);
}

sf::Drawable& Building::getDrawable()
{
    return sprite;
}

void Building::loadTexture(const std::string& source)
{
    texture.loadFromFile(source);
    sprite.setTexture(texture);
}

sf::Transformable& Building::getTranformable()
{
    return sprite;
}