#include "ButtonsHandler.h"

void ButtonsHandler::ConnectWithPressedButtons(std::list<int>* pressedButtons)
{
	this->pressedButtons = pressedButtons;
}

void ButtonsHandler::AddButton(std::shared_ptr<gui::Button> button)
{
	buttons.emplace_back(button);
}

void ButtonsHandler::Clear()
{
	buttons.erase(buttons.begin(), buttons.end());
}

void ButtonsHandler::HandleEvent(sf::Event event)
{
	for (int x = 0; x < buttons.size(); x++)
		if (buttons[x]->HandleClick(event))
		{
			pressedButtons->push_back(x);
			buttons[x]->Refresh();
		}
}

void ButtonsHandler::Draw(std::shared_ptr<sf::RenderWindow>& renderWindow)
{
	for (auto btn : buttons)
		renderWindow->draw(*btn);
}
