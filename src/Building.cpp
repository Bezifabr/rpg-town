#include "Building.h"

Building::Building(const Building& b)
{
    texture = b.texture;
    sprite = b.sprite;
    sprite.setTexture(texture);
//    sprite.setOrigin(
//        sprite.getGlobalBounds().left + sprite.getGlobalBounds().height,
//        sprite.getGlobalBounds().top + sprite.getGlobalBounds().width);

//sprite.setOrigin(0, sprite.getLocalBounds().height);

//sprite.setOrigin(0, sprite.getTexture()->getSize().y);
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