#include "states/GameState.h"
#include "StateTransition.h"
#include <iostream>

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	topBarTexture.loadFromFile("resources/Top Bar.png");
	topBar.setTexture(topBarTexture);

    house.texture.loadFromFile("resources/Test/House.png");
    house.sprite.setTexture(house.texture);
    house.sprite.setOrigin(256/2,256/2);

    buildingPattern.setSize(sf::Vector2f(256,256));
    buildingPattern.setFillColor(sf::Color(10,255,10,50));
    buildingPattern.setPosition(-600,600);
    buildingPattern.setOrigin(buildingPattern.getSize().x / 2, buildingPattern.getSize().y / 2);

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

    buildingPattern.setPosition(globalMousePos.x, buildingPattern.getPosition().y);

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
       {
            cout << localMousePos.x << ", " << localMousePos.y << "\n";
            cout << globalMousePos.x << " " << globalMousePos.y << "\n";

        if(DoesItIntersectWithStructures(buildingPattern.getGlobalBounds()) == false)
            PlaceStructure();

       }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            renderWindow->close();
        }

    
    if(DoesItIntersectWithStructures(buildingPattern.getGlobalBounds()))
        buildingPattern.setFillColor(sf::Color(255,10,10,50));
    else
        buildingPattern.setFillColor(sf::Color(10,255,10,50));


}

void GameState::OnUpdate()
{
}

void GameState::OnDraw()
{
	renderWindow->draw(topBar);

    renderWindow->draw(buildingPattern);

    for(auto s : structures)
        renderWindow->draw(s.sprite);
}

bool GameState::DoesItIntersectWithStructures(const sf::FloatRect& rect)
{
    for(auto s : structures)
        if(buildingPattern.getGlobalBounds().intersects(s.sprite.getGlobalBounds()))
            return true;
    return false;
}

void GameState::PlaceStructure()
{
    house.sprite.setPosition(buildingPattern.getPosition());
    structures.push_back(house);
}