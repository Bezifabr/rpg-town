#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "HUD/Button.h"
#include "Town.h"
#include "HUD/Window.h"

class GameState : public State
{

    sf::Sprite topBar;
    sf::Texture topBarTexture;

    HUD::Button btnMenu;
    HUD::Button btnQuests;
    HUD::Button btnStats;
    sf::Font font;
    sf::Texture hudButtonTexture;

    HUD::Window* currentWindow = nullptr;

    sf::View camera;

    Town town;

    bool windowOpened = false;

private:
    void CheckCodes(std::string code);
    void CloseWindow();

    virtual void OnUpdate() override;
	virtual void OnHandleEvent() override;
	virtual void OnRender() override;

    virtual void OnLoad() override;
    virtual void OnUnload() override;
};

#endif //GAME_STATE_H
