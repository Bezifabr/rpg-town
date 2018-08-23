#include "PlayerCharacter.h"

void PlayerCharacter::SetSpeed(int speed)
{
    this->speed = speed;
}

int PlayerCharacter::GetSpeed()
{
    return this->speed;
}

void PlayerCharacter::Move(sf::Time deltaTime)
{
    this->sprite.move(speed * deltaTime.asSeconds(),0);
}