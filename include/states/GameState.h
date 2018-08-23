#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Structure.h"
#include "IngameMode.h"
#include <vector>

class GameState : public State
{
    Structure house;

    sf::Sprite topBar;
    sf::Texture topBarTexture;

    sf::RectangleShape buildingPattern;

    std::vector<Structure> structures;

    std::vector<Structure>::iterator selStructure;
    bool selected = false;

    IngameMode ingameMode = IngameMode::selecting;

    sf::View view;

    sf::Vector2f globalMousePos;
    sf::Vector2f localMousePos;

private:

    void PlaceStructure();
    bool IntersectsWithStructures(const sf::FloatRect& rect);
    bool ContainedByStructure(const sf::Vector2f& point);

    void ChangeIngameMode();

    void RemoveSelectedStructure();

    void SelectStructure(std::vector<Structure>::iterator itr);
    void UnselectStructure();

	virtual void OnHandleEvent() override;
    virtual void OnUpdate() override;
	virtual void OnDraw() override;

    virtual void OnEnter() override;
    virtual void OnLeave() override;
};

#endif //GAME_STATE_H
