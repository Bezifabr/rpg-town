#ifndef STRUCTURE_MOLD_H
#define STRUCTURE_MOLD_H

#include "Structure.h"
#include "StructureType.h"
#include "TextureHolder.h"
#include <memory>
#include <SFML/Window/Keyboard.hpp>

class StructureMold : public Structure
{
    TextureHolder* textures;
public:
    void Change(sf::Keyboard::Key key);

    void LoadTextures(TextureHolder& holder);
};


#endif // STRUCTURE_MOLD_H