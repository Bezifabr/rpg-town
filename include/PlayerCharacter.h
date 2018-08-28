#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "StructureType.h"
#include "AnimatedSprite.h"

class PlayerCharacter : public sf::Drawable
{
    StructureType currentStructureType = StructureType::nothing;
    int speed;

    std::string nick;
    sf::Text nickText;

    bool isMoving = true;
public:
    PlayerCharacter();

    AnimatedSprite sprite;
    sf::Texture texture;

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
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void Move(sf::Time deltaTime);
};

#endif // PLAYER_CHARACTER_H