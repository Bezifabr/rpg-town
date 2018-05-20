#include "states/IntroState.h"
#include "StatesMachine.h"
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
    statesMachine->setCurrent(new MenuState);
}

void IntroState::OnUnload()
{
    cout << "Intro unload" << endl;
}

void IntroState::HandleEvent(sf::Event event, const sf::Window& window)
{

}

void IntroState::Render(sf::RenderTarget& renderTarget)
{
    
}