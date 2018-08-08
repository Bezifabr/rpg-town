#include "State.h"

void State::Load(StateMachine * stateMachine)
{
	this->stateMachine = stateMachine;
	OnLoad();
}

void State::Update(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
	OnUpdate();
}

void State::Unload()
{
	stateMachine = nullptr;
	OnUnload();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
