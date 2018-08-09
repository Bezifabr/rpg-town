#ifndef GAME_H
#define GAME_H

#include "StateMachine.h"
#include "StateUpdater.h"
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
    sf::RenderWindow window;
    StateMachine stateMachine;
    StateUpdater updater;
public:
    void Init(std::shared_ptr<State> state);
    void Start();

private:
    void RunLoop();

};

#endif // GAME_H