#include "StateUpdater.h"
#include <stdexcept>

void StateUpdater::ConnectWithAccessor(StateAccessor& accessor)
{
    this->accessor = &accessor;
}

bool StateUpdater::IsRunning()
{
    return isRunning;
}

void StateUpdater::Update(sf::Time deltaTime)
{
    accessor->Peek()->Update(deltaTime);

    if(accessor->Peek()->IsGameFinished() == true)
        isRunning = false;

}

void StateUpdater::HandleEvent(sf::Event event, const sf::Window& window)
{
    accessor->Peek()->HandleEvent(event);
}

void StateUpdater::Draw(sf::RenderTarget& renderTarget)
{
    accessor->Peek()->Render();
}

void StateUpdater::Refresh()
{
    accessor->Peek()->Refresh();
}