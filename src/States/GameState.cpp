#include "states/GameState.h"
#include "StateTransition.h"
#include <iostream>

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	topBarTexture.loadFromFile("resources/Top Bar.png");
	topBar.setTexture(topBarTexture);

	cout << "Game loaded" << endl;
}

void GameState::OnLeave()
{
	cout << "Game unloaded" << endl;
}

void GameState::OnHandleEvent()
{
    sf::Vector2f globalMousePos = renderWindow->mapPixelToCoords(sf::Mouse::getPosition((*renderWindow)));
    sf::Vector2f localMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition((*renderWindow)));

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
       {
            cout << localMousePos.x << ", " << localMousePos.y << "\n";
            cout << globalMousePos.x << " " << globalMousePos.y << "\n";
       }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            renderWindow->close();
        }

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
    {
    }

}

void GameState::OnUpdate()
{
}

void GameState::OnDraw()
{
	renderWindow->draw(topBar);
}