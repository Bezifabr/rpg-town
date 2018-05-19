#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"
#include <iostream>

class MenuState : public State {

public:

	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnUpdate();
	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !MENU_STATE_H
