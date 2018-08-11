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

public:

    virtual void HandleEvent(sf::Event event, const sf::Window& window);
    virtual void Render(sf::RenderTarget& renderTarget);

private:
    void CheckCodes(std::string code);
    void CloseWindow();

    virtual void OnUpdate();
    virtual void OnLoad();
    virtual void OnUnload();
};

#endif //GAME_STATE_H
