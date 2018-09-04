#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Structure.h"
#include "IngameMode.h"
#include "PlayerCharacter.h"
#include <vector>
#include "AnimatedSprite.h"
#include <SFML/Graphics/Text.hpp>

class GameState : public State
{
    Structure bld_hut;
    Structure bld_main;
    Structure bld_shop;

	StructureType currentStructureType;

    sf::Sprite topBar;
    sf::Texture topBarTexture;

	Structure* previewStructure;

    std::vector<Structure> structures;

    std::vector<Structure>::iterator selStructure;
    bool selected = false;

    IngameMode ingameMode = IngameMode::selecting;

    sf::View view;

    sf::Vector2f globalMousePos;
    sf::Vector2f localMousePos;

    PlayerCharacter player;

    int cash;

    sf::Font font;

    sf::Text cashText;

    int sizeOfTown;
    int limitOfStructures;

private:

    void PlaceStructure();
    bool IntersectsWithStructures(const sf::FloatRect& rect);
    bool ContainedByStructure(const sf::Vector2f& point);

	void ChangeCurrentStructure();
    void ChangeIngameMode();

    void RemoveSelectedStructure();

    void SelectStructure(std::vector<Structure>::iterator itr);
    void UnselectStructure();

	virtual void OnHandleEvent() override;
    virtual void OnUpdate() override;
	virtual void OnDraw() override;

    virtual void OnEnter() override;
    virtual void OnLeave() override;

    void SetupPlayer();
};

#endif //GAME_STATE_H
