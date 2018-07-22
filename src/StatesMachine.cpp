#include "StatesMachine.h"
#include "State.h"
#include <iostream>
#include <stdexcept>

using namespace std;

StatesMachine::StatesMachine()
{

}

StatesMachine::~StatesMachine()
{
    shutdown();
}

void StatesMachine::init(std::shared_ptr<State> s, sf::RenderWindow* window)
{
    this->window = window;
    
    Push(s);

    window->setView(window->getDefaultView());(s);
    isRunning = true;
}

void StatesMachine::shutdown()
{
    if(isRunning)
        Peek()->Unload();
}

void StatesMachine::Update(sf::Time deltaTime)
{
    if(states.empty())
        throw std::runtime_error("Tried to update with empty states stack");


    Peek()->Update(deltaTime);

    if(Peek()->IsGameFinished() == true)
        isRunning = false;
}

void StatesMachine::render(sf::RenderTarget & renderTarget)
{
    if(states.empty())
        throw std::runtime_error("Tried to render with empty states stack");

    Peek()->Render(renderTarget);
}

void StatesMachine::handleEvent(sf::Event event, const sf::Window& window)
{
    if(states.empty())
        throw std::runtime_error("Tried to handle event with empty states stack");

    Peek()->HandleEvent(event, window);
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
    return window->mapPixelToCoords(position, window->getView());
}

sf::Vector2i StatesMachine::ConvertToPixels(sf::Vector2f position)
{
    return window->mapCoordsToPixel(position);
}

void StatesMachine::Push(std::shared_ptr<State> s)
{
    std::shared_ptr<State> currentState = Peek();

    states.push(s);
    states.top()->Load(this);
}

void StatesMachine::Pop()
{
    if(states.empty())
        throw std::runtime_error("Attempted to pop from an empty game state stack");

    states.pop();
}

void StatesMachine::Switch(std::shared_ptr<State> s)
{
    std::shared_ptr<State> currentState = states.top();
    window->setView(window->getDefaultView());

    if(currentState)
        Pop();

    Push(s);
}

std::shared_ptr<State> StatesMachine::Peek()
{
    if(!states.empty())
        return states.top();
    else
        return nullptr;
}