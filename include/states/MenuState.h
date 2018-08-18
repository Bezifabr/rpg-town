#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"
#include <iostream>
#include "HUD/Button.h"

class MenuState : public State {

	sf::Font titleFont;
	sf::Font textFont;
	sf::Text title;
	sf::Text author;
	sf::Text TBC;
	HUD::Button btnPlay;
	HUD::Button btnLoad;
	HUD::Button btnExit;
	sf::Texture texture;
	sf::Texture buttonTexture;

private:

	virtual void OnUpdate() override;
	virtual void OnHandleEvent() override;
	virtual void OnRender() override;

	virtual void OnLoad() override;
	virtual void OnUnload() override;
};

#endif // !MENU_STATE_H
