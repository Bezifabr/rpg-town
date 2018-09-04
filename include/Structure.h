#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "StructureType.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Structure
{
    StructureType type;

    uint8_t cost = 10;
public:
    sf::Sprite sprite;

    void SetType(StructureType type);
    StructureType GetType();

    void SetCost(uint8_t cost);
    uint8_t GetCost();
};

#endif // STRUCTURE_H