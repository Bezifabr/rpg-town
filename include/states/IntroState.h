#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"
#include <iostream>

class IntroState : public State {
	
private:

	virtual void OnEnter() override;
	virtual void OnLeave() override;
	
	virtual void OnUpdate() override;
	
};

#endif // !INTRO_STATE_H
