#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"
#include <iostream>

class IntroState : public State {

public:

	virtual void HandleEvent(sf::Event event, const sf::Window& window);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnUpdate();
	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !INTRO_STATE_H
