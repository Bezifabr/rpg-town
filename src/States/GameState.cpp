#include "states/GameState.h"
#include "StateTransition.h"
#include <iostream>

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	view = renderWindow->getDefaultView();

	structures.reserve(128);

	topBarTexture.loadFromFile("resources/Top Bar.png");
	topBar.setTexture(topBarTexture);

	player.texture.loadFromFile("resources/PlayerTex.png");
	player.sprite.setTexture(player.texture);
	player.sprite.setPosition(0,600);
	player.sprite.setTextureRect(sf::IntRect(0,0,128,256));
	player.SetSpeed(25);

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
	globalMousePos = renderWindow->mapPixelToCoords(sf::Mouse::getPosition((*renderWindow)));
	localMousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition((*renderWindow)));


	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		cout << localMousePos.x << ", " << localMousePos.y << "\n";
		cout << globalMousePos.x << " " << globalMousePos.y << "\n";

		if (ingameMode == IngameMode::building && IntersectsWithStructures(buildingPattern.getGlobalBounds()) == false)
			PlaceStructure();

		if (selected == true && !selStructure->sprite.getGlobalBounds().contains(globalMousePos))
			UnselectStructure();

		if (ingameMode == IngameMode::selecting)
			for (auto itr = structures.begin(); itr != structures.end(); itr++)
				if (itr->sprite.getGlobalBounds().contains(globalMousePos))
				{
					SelectStructure(itr);
					break;
				}
	}

	if (event.type == sf::Event::KeyReleased)
	{
		ChangeIngameMode();

		if (ingameMode == IngameMode::selecting)
			if (event.key.code == sf::Keyboard::Delete && selected == true)
				RemoveSelectedStructure();
	}

}

void GameState::OnUpdate()
{

	buildingPattern.setPosition(globalMousePos.x, buildingPattern.getPosition().y);

	if (IntersectsWithStructures(buildingPattern.getGlobalBounds()) && ingameMode == IngameMode::building)
		buildingPattern.setFillColor(sf::Color(255, 10, 10, 50));
	else
		buildingPattern.setFillColor(sf::Color(10, 255, 10, 50));

	if (selected == true && ingameMode != IngameMode::selecting)
		UnselectStructure();
		
	if(localMousePos.x >= renderWindow->getSize().x - 50) view.move(350 * deltaTime.asSeconds(), 0);
	if(localMousePos.x <= 50) view.move(-350 * deltaTime.asSeconds(), 0);
	player.Move(deltaTime);


}

void GameState::OnDraw()
{
	renderWindow->setView(view);

	renderWindow->draw(player.sprite);

	renderWindow->draw(topBar);

	if (ingameMode == IngameMode::building)
		renderWindow->draw(buildingPattern);

	for (auto s : structures)
			renderWindow->draw(s.sprite);
}

void GameState::ChangeIngameMode()
{
	switch (event.key.code)
	{
	case sf::Keyboard::Escape:
		renderWindow->close();
		break;
	case sf::Keyboard::A:
		ingameMode = IngameMode::selecting;
		break;
	case sf::Keyboard::S:
		ingameMode = IngameMode::building;
		break;
	}


}

void GameState::RemoveSelectedStructure()
{
	selected = false;
	structures.erase(selStructure);
}

void GameState::SelectStructure(std::vector<Structure>::iterator itr)
{
	selStructure = itr;
	itr->sprite.setColor(sf::Color(200, 200, 200, 255));
	selected = true;
}

void GameState::UnselectStructure()
{
	selected = false;
	selStructure->sprite.setColor(sf::Color(255, 255, 255, 255));
}

bool GameState::IntersectsWithStructures(const sf::FloatRect& rect)
{
	for (auto s : structures)
		if (rect.intersects(s.sprite.getGlobalBounds()))
			return true;
	return false;
}

bool GameState::ContainedByStructure(const sf::Vector2f& point)
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