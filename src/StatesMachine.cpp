#include "StateMachine.h"
#include "State.h"
#include <iostream>
#include <stdexcept>

using namespace std;

StateMachine::~StateMachine()
{
    Shutdown();
}

void StateMachine::Init(std::shared_ptr<State> s, sf::RenderWindow* window)
{
    view.ConnectWithRenderWindow((*window));
    
    Push(s);

    view.SetDefaultView();
}

void StateMachine::Shutdown()
{
    Peek()->Unload();
}


void StateMachine::Push(std::shared_ptr<State> s)
{
    std::shared_ptr<State> currentState = Peek();

    states.push(s);
    states.top()->ConnectWithViewManager(view);
    states.top()->Load(this);
}

void StateMachine::Pop()
{
    if(states.empty())
        throw std::runtime_error("Attempted to pop from an empty game state stack");

    states.pop();
}

void StateMachine::Switch(std::shared_ptr<State> s)
{
    std::shared_ptr<State> currentState = states.top();
    view.SetDefaultView();

    if(currentState)
        Pop();

    Push(s);
}

std::shared_ptr<State> StateMachine::Peek()
{
    if(!states.empty())
        return states.top();
    else
        return nullptr;
}