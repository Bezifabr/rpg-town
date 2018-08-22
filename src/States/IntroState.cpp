#include "states/IntroState.h"
#include "StateTransition.h"
#include "states/GameState.h"
#include <iostream>

using std::cout;
using std::endl;

void IntroState::OnEnter()
{
	cout << "Intro load" << endl;
}

void IntroState::OnLeave()
{
	cout << "Intro unload" << endl;
}

void IntroState::OnUpdate()
{
    transition->Switch(std::unique_ptr<State>(new GameState));
}