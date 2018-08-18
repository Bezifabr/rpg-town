#include "states/IntroState.h"
#include "StateMachine.h"
#include "states/MenuState.h"
#include <iostream>

using std::cout;
using std::endl;

void IntroState::OnLoad()
{
    cout << "Intro load" << endl;
}

void IntroState::OnUpdate()
{
    transition->Switch(std::shared_ptr<State>(new MenuState));
}

void IntroState::OnUnload()
{
    cout << "Intro unload" << endl;
}

void IntroState::OnHandleEvent()
{
}

void IntroState::OnRender()
{
    
}