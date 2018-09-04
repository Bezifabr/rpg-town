#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "StructureType.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Structure
{
    StructureType type;
public:
    sf::Sprite sprite;

    void SetType(StructureType type);
    StructureType GetType();
};

#endif // STRUCTURE_H