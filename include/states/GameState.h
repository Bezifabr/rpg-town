#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Structure.h"
#include <vector>

class GameState : public State
{
    Structure house;

    sf::Sprite topBar;
    sf::Texture topBarTexture;

    sf::RectangleShape buildingPattern;

    std::vector<Structure> structures;

private:

    void PlaceStructure();
    bool DoesItIntersectWithStructures(const sf::FloatRect& rect);

	virtual void OnHandleEvent() override;
    virtual void OnUpdate() override;
	virtual void OnDraw() override;

    virtual void OnEnter() override;
    virtual void OnLeave() override;
};

#endif //GAME_STATE_H
