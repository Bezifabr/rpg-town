#ifndef BUTTONS_HANDLER_H
#define BUTTONS_HANDLER_H

#include <list>
#include <vector>
#include <memory>
#include <string>
#include "Button.h"

#include <SFML/Graphics/RenderWindow.hpp>

class ButtonsHandler
{
	std::vector<std::shared_ptr<Button>> buttons;
	std::list<int>* pressedButtons;
public:
	void ConnectWithPressedButtons(std::list<int>* pressedButtons);

	void AddButton(std::shared_ptr<Button> button);
	void Clear();

	void HandleEvent(sf::Event event);

	void Draw(std::shared_ptr<sf::RenderWindow>& renderWindow);
};

#endif // !BUTTONS_HANDLER_H
