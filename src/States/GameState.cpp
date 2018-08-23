#include "states/GameState.h"
#include "StateTransition.h"
#include <iostream>

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	structures.reserve(128);

	topBarTexture.loadFromFile("resources/Top Bar.png");
	topBar.setTexture(topBarTexture);

	house.texture.loadFromFile("resources/Test/House.png");
	house.sprite.setTexture(house.texture);
	house.sprite.setOrigin(256 / 2, 256 / 2);

	buildingPattern.setSize(sf::Vector2f(256, 256));
	buildingPattern.setFillColor(sf::Color(10, 255, 10, 50));
	buildingPattern.setPosition(-600, 600);
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

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		cout << localMousePos.x << ", " << localMousePos.y << "\n";
		cout << globalMousePos.x << " " << globalMousePos.y << "\n";

		if (ingameMode == IngameMode::building && DoesItIntersectWithStructures(buildingPattern.getGlobalBounds()) == false)
			PlaceStructure();

		if (ingameMode == IngameMode::select)
			for (auto itr = structures.begin(); itr != structures.end(); itr++)
				if (itr->sprite.getGlobalBounds().contains(globalMousePos))
					if (selected == false)
					{
						selStructure = itr;
						itr->sprite.setColor(sf::Color(200, 200, 200, 255));
						selected = true;
						break;
					}

		if (selected == true && !selStructure->sprite.getGlobalBounds().contains(globalMousePos))
		{
			selected = false;
			selStructure->sprite.setColor(sf::Color(255, 255, 255, 255));
		}


	}

	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			renderWindow->close();
			break;
		case sf::Keyboard::A:
			ingameMode = IngameMode::select;
			break;
		case sf::Keyboard::S:
			ingameMode = IngameMode::building;
			break;
		}
	}



}

void GameState::OnUpdate()
{
	auto globalMousePos = renderWindow->mapPixelToCoords(sf::Mouse::getPosition((*renderWindow)));

	if (DoesItIntersectWithStructures(buildingPattern.getGlobalBounds()) && ingameMode == IngameMode::building)
		buildingPattern.setFillColor(sf::Color(255, 10, 10, 50));
	else
		buildingPattern.setFillColor(sf::Color(10, 255, 10, 50));
	}
}

void GameState::OnDraw()
{
	renderWindow->draw(topBar);

	if (ingameMode == IngameMode::building)
		renderWindow->draw(buildingPattern);

	for (auto s : structures)
		renderWindow->draw(s.sprite);
}

bool GameState::DoesItIntersectWithStructures(const sf::FloatRect& rect)
{
	for (auto s : structures)
		if (rect.intersects(s.sprite.getGlobalBounds()))
			return true;
	return false;
}

bool GameState::IsItContainedByStructure(const sf::Vector2f& point)
{
	for (auto s : structures)
		if (s.sprite.getGlobalBounds().contains(point))
			return true;
	return false;
}

void GameState::PlaceStructure()
{
	house.sprite.setPosition(buildingPattern.getPosition());
	structures.push_back(house);
}