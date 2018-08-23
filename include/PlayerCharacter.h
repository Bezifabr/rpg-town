#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class PlayerCharacter
{
    int speed;
public:
    sf::Sprite sprite;
    sf::Texture texture;

    void SetSpeed(int speed);
    int GetSpeed();

    void Move(sf::Time deltaTime);

};

#endif // PLAYER_CHARACTER_H