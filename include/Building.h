#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>

class Building
{
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Building(){}
    Building(const Building& b);

    sf::Drawable& GetDrawable();
    sf::Transformable& GetTranformable();

    void LoadTexture(const std::string& source);


};

#endif //BUILDING_H
