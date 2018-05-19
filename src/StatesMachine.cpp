#include "StatesMachine.h"
#include "State.h"
#include <iostream>

StatesMachine::StatesMachine()
{

}

void StatesMachine::setCurrent(State * s)
{
 //  if(this->current)
     //   current->Unload();
    this->current = s;
    this->current->Load(this);
    isRunning = true;
}

void StatesMachine::Update(sf::Time deltaTime)
{
    current->Update(deltaTime);
    if(current->IsGameFinished() == true)
        isRunning = false;
}

void StatesMachine::render(sf::RenderTarget & renderTarget)
{
    current->Render(renderTarget);
}

void StatesMachine::handleEvent(sf::Event event, const sf::Window& window)
{
    current->HandleEvent(event, window);
}

bool StatesMachine::IsRunning()
{
    return isRunning;
}