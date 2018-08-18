#include "State.h"
#include <stdexcept>

void State::ConnectWithViewManager(ViewManager& view)
{
	this->view = &view;
}

void State::ConnectWithStateTransition(StateTransition * transition)
{
	this->transition = transition;
}

void State::ConnectWithRenderWindow(sf::RenderWindow * renderWindow)
{
	this->renderWindow = renderWindow;
}

void State::Load()
{
	if (!transition) throw std::runtime_error("Cannot find StateTransition object");
	if (!renderWindow) throw std::runtime_error("Cannot find sf::RenderWindow object");

	OnLoad();
}

void State::Update(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;

	for(auto e : container.GetEntities())
	{
		e->Update(deltaTime);
	}

	OnUpdate();
}

void State::HandleEvent(sf::Event event)
{
	this->event = event;

	for (auto e : container.GetEntities())
	{
		e->HandleEvent(event);
	}

	OnHandleEvent();
}

void State::Render()
{
	for (auto e : container.GetEntities())
	{
		e->Draw((*renderWindow));
	}

	OnRender();
}

void State::Refresh()
{
	OnRender();
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
