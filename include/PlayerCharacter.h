#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "StructureType.h"

class PlayerCharacter
{
    StructureType currentStructureType = StructureType::nothing;
    int speed;

    bool isMoving = true;
public:
    sf::Sprite sprite;
    sf::Texture texture;

    void SetSpeed(int speed);
    int GetSpeed();

    void Move(sf::Time deltaTime);

    void SetStructureType(StructureType type);
    StructureType GetStructureType();

    void SetMoving(bool moving);
    bool IsMoving();

};

#endif // PLAYER_CHARACTER_H