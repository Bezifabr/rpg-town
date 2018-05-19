#include "MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void MenuState::OnLoad()
{
	cout << "Menu loaded" << endl;
}

void MenuState::OnUnload()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::OnUpdate()
{

}

void MenuState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;

	}
}

void MenuState::Render(sf::RenderTarget & renderTarget)
{
}

