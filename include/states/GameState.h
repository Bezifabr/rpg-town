#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState : public State
{

    sf::Sprite topBar;
    sf::Texture topBarTexture;

private:

	virtual void OnHandleEvent() override;
    virtual void OnUpdate() override;
	virtual void OnDraw() override;

    virtual void OnEnter() override;
    virtual void OnLeave() override;
};

#endif //GAME_STATE_H
