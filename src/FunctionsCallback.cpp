#include "FunctionsCallback.h"

void FunctionsCallback::ConnectWithPressedButtons(const std::list<int>* pressedButtons)
{
	this->pressedButtons = pressedButtons;
}

void FunctionsCallback::AddFunction(std::function<void()> function)
{
	callbackVector.push_back(function);
}

void FunctionsCallback::Clear()
{
	callbackVector.erase(callbackVector.begin(), callbackVector.end());
}

void FunctionsCallback::Update(sf::Time deltaTime)
{
	for (int x : *pressedButtons)
		callbackVector[x]();
}
