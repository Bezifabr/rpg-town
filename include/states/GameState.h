#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Button.h"
#include "Town.h"

class GameState : public State 
{
    UI::Button btnMenu;
    UI::Button btnQuests;
    UI::Button btnStats;
    sf::Font font;
    sf::Texture hudButtonTexture;

    sf::View camera;

    Town town;
    
public:

    virtual void HandleEvent(sf::Event event, const sf::Window& window);
    virtual void Render(sf::RenderTarget& renderTarget);

private:

    virtual void OnUpdate();
    virtual void OnLoad();
    virtual void OnUnload();
};

#endif //GAME_STATE_H