#ifndef BUTTON_FUNCTION_CONNECTOR_H
#define BUTTON_FUNCTION_CONNECTOR_H

#include "ButtonsHandler.h"
#include "FunctionsCallback.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>

class ButtonFunctionConnector
{
	ButtonsHandler buttonsHandler;
	FunctionsCallback functionsCallback;
	
	std::list<int> pressedButtons;
public:
	ButtonFunctionConnector();

	void Add(std::shared_ptr<gui::Button> btn, std::function<void()> function);

	void HandleEvent(sf::Event event);
	void Update(sf::Time deltaTime);
	void Draw(std::shared_ptr<sf::RenderWindow> renderWindow);

	void Clear();
};

#endif // !BUTTON_FUNCTION_CONNECTOR_H
