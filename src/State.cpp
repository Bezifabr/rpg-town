#include "State.h"

void State::Load(StatesMachine * statesMachine)
{
	this->statesMachine = statesMachine;
	OnLoad();
}

void State::Update(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
	OnUpdate();
}

void State::Unload()
{
	statesMachine = nullptr;
	OnUnload();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
