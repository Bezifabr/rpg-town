#include "ButtonFunctionConnector.h"

ButtonFunctionConnector::ButtonFunctionConnector()
{
	buttonsHandler.ConnectWithPressedButtons(&pressedButtons);
	functionsCallback.ConnectWithPressedButtons(&pressedButtons);
}

void ButtonFunctionConnector::Add(std::shared_ptr<gui::Button> btn, std::function<void()> function)
{
	buttonsHandler.AddButton(btn);
	functionsCallback.AddFunction(function);
}

void ButtonFunctionConnector::HandleEvent(sf::Event event)
{
	buttonsHandler.HandleEvent(event);
}

void ButtonFunctionConnector::Update(sf::Time deltaTime)
{
	functionsCallback.Update(deltaTime);
	pressedButtons.clear();
}

void ButtonFunctionConnector::Draw(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	buttonsHandler.Draw(renderWindow);
}

void ButtonFunctionConnector::Clear()
{
	buttonsHandler.Clear();
	functionsCallback.Clear();
}
