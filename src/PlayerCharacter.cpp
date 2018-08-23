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

StructureType PlayerCharacter::GetStructureType()
{
    return this->currentStructureType;
}

void PlayerCharacter::SetStructureType(StructureType type)
{
    currentStructureType = type;
}

bool PlayerCharacter::IsMoving()
{
    return isMoving;
}

void PlayerCharacter::SetMoving(bool moving)
{
    isMoving = moving;
}