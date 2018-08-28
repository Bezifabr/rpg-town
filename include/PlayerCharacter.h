#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include "StructureType.h"
#include "AnimatedSprite.h"

class PlayerCharacter
{
    StructureType currentStructureType = StructureType::nothing;
    int speed;

    std::string nick;

    bool isMoving = true;
public:
    PlayerCharacter();

    AnimatedSprite sprite;
    sf::Texture texture;
    sf::Text nickText;

    void SetSpeed(int speed);
    int GetSpeed();

    void SetStructureType(StructureType type);
    StructureType GetStructureType();

    void SetMoving(bool moving);
    bool IsMoving();

    void SetNick(const std::string& name);
    const std::string& GetNick();

    void SetFont(sf::Font& font);
    const sf::Font* GetFont();

    void Update(sf::Time deltaTime);

private:
    void Move(sf::Time deltaTime);
};

#endif // PLAYER_CHARACTER_H