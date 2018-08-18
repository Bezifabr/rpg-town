#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"
#include <iostream>

class IntroState : public State {
	
private:

	virtual void OnUpdate() override;
	virtual void OnLoad() override;
	virtual void OnUnload() override;
	virtual void OnRender() override;
	virtual void OnHandleEvent() override;
};

#endif // !INTRO_STATE_H
