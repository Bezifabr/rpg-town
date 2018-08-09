#ifndef STATE_UPDATER_H
#define STATE_UPDATER_H

#include "StateAccessor.h"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class StateUpdater
{
    bool isRunning = true;
    StateAccessor* accessor = nullptr;
public:
    void ConnectWithAccessor(StateAccessor& accessor);
    void Update(sf::Time elapsedTime);
    void HandleEvent(sf::Event event, const sf::Window& window);
    void Draw(sf::RenderTarget& renderTarget);

    bool IsRunning();
};

#endif // STATE_UPDATER_H