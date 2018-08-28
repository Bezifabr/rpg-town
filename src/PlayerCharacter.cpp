#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
    nickText.setOrigin(nickText.getGlobalBounds().width/2, nickText.getGlobalBounds().height/2);
}

void PlayerCharacter::SetSpeed(int speed)
{
    this->speed = speed;
}

int PlayerCharacter::GetSpeed()
{
    return this->speed;
}

void PlayerCharacter::Update(sf::Time deltaTime)
{
    nickText.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 4, sprite.getPosition().y - 50);
    Move(deltaTime);
}

void PlayerCharacter::Move(sf::Time deltaTime)
{
    if(isMoving)
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

void PlayerCharacter::SetFont(sf::Font& font)
{
    nickText.setFont(font);
}

const sf::Font* PlayerCharacter::GetFont()
{
    return nickText.getFont();
}

void PlayerCharacter::SetNick(const std::string& name)
{
    nickText.setString(name);
}

const std::string& PlayerCharacter::GetNick()
{
    return nickText.getString();
}

void PlayerCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
    target.draw(nickText, states);
}