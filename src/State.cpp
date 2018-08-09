#include "State.h"

void State::ConnectWithViewManager(ViewManager& view)
{
	this->view = &view;
}

void State::Load(StateTransition * transition)
{
	this->transition = transition;
	OnLoad();
}

void State::Update(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
	OnUpdate();
}

void State::Unload()
{
	transition = nullptr;
	OnUnload();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
