#include "StatesMachine.h"
#include "State.h"
#include <iostream>

StatesMachine::StatesMachine()
{

}

void StatesMachine::setCurrent(State * s)
{
    this->current = s;
    this->current->Load(this);
}

void StatesMachine::Update(sf::Time deltaTime)
{
}