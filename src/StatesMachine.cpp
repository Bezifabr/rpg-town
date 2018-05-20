#include "StatesMachine.h"
#include "State.h"
#include <iostream>

StatesMachine::StatesMachine()
{

}

StatesMachine::~StatesMachine()
{
    shutdown();
}

void StatesMachine::init(State * s, sf::RenderWindow* window)
{
    this->window = window;
    setCurrent(s);
    isRunning = true;
}

void StatesMachine::shutdown()
{
    if(isRunning)
        current->Unload();
}

void StatesMachine::setCurrent(State * s)
{
    window->setView(window->getDefaultView());
   if(isRunning == true)
           current->Unload();

    this->current = s;
    this->current->Load(this);
    current->Update(sf::Time::Zero);
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

void StatesMachine::setView(const sf::View& view)
{
    window->setView(view);
}

sf::Vector2f StatesMachine::ConvertToCoordinate(sf::Vector2i position)
{
    return window->mapPixelToCoords(position);
}