#ifndef GAME_H
#define GAME_H

#include "StateStack.h"
#include "StateUpdater.h"
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
    std::shared_ptr<sf::RenderWindow> renderWindow;
    StateStack stateStack;
    StateUpdater updater;
public:
    Game();
private:
    void RunLoop();

};

#endif // GAME_H