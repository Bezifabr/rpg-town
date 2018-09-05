#include "StructureMold.h"

void StructureMold::Change(sf::Keyboard::Key key)
{
	sprite.setColor(sf::Color(255, 255, 255, 100));
	sprite.setOrigin(256 / 2, 256 / 2);
    
    switch (key)
    {
	case sf::Keyboard::Num1 :
	    sprite.setTexture(textures->GetTexture("BLD_Hut"));
	    SetCost(10);
        SetType(StructureType::hut);
        break;
	case sf::Keyboard::Num2 :
	    sprite.setTexture(textures->GetTexture("BLD_Main"));
	    SetCost(50);
        SetType(StructureType::main);
        break;
	case sf::Keyboard::Num3 :
	    sprite.setTexture(textures->GetTexture("BLD_Shop"));
	    SetCost(10);
        SetType(StructureType::shop);
        break;
    }




}

void StructureMold::LoadTextures(TextureHolder& holder)
{
    this->textures = &holder;
    
	textures->LoadTexture("BLD_Hut","Test/hut");
	textures->LoadTexture("BLD_Main","Test/main");
	textures->LoadTexture("BLD_Shop","Test/shop");
}