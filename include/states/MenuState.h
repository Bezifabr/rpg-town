#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"
#include <iostream>
#include "Button.h"

class MenuState : public State {

	sf::Font titleFont;
	sf::Font textFont;
	sf::Text title;
	sf::Text author;
	sf::Text TBC;
	UI::Button btnPlay;
	UI::Button btnLoad;
	UI::Button btnExit;
	sf::Texture texture;
	sf::Texture buttonTexture;
public:

	virtual void HandleEvent(sf::Event event, const sf::Window& window);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnUpdate();
	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !MENU_STATE_H