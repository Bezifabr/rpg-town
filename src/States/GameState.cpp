#include "states/GameState.h"
#include "StateTransition.h"
#include <iostream>
#include <string>
#include "Animation.h"

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	view = renderWindow->getDefaultView();

	structures.reserve(128);

	sizeOfTown = 1000;
	limitOfStructures = 5;

	textures.LoadTexture("GUI_TopBar","Top Bar");
	textures.LoadTexture("CHAR_Player", "PlayerTex");
	textures.LoadTexture("GUI_Btn", "btnTex");
	structureMold.LoadTextures(textures);
	font.loadFromFile("resources/Text font.ttf");

	topBar.setTexture(textures.GetTexture("GUI_TopBar"));

	structureMold.Change(sf::Keyboard::Num1);

	TextButton btn;
	btn.SetTexture(textures.GetTexture("GUI_Btn"));
	btn.SetTextFont(font);
	btn.SetTextString("Test");
	btn.SetPosition(250,50);

	SetupPlayer();


	cash = 100;
	cashText.setString(std::to_string(cash));
	cashText.setFont(font);

	buttonFunctionConnector.Add(std::make_shared<TextButton>(std::move(btn)), [] { cout << "Test" << endl;  });

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

	buttonFunctionConnector.HandleEvent(event);

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		// DEBUG
		cout << "Local: " << localMousePos.x << ", " << localMousePos.y << "\n";
		cout << "Global: " << globalMousePos.x << " " << globalMousePos.y << "\n";
		/* *** */

		if (ingameMode == IngameMode::building && IntersectsWithStructures(structureMold.sprite.getGlobalBounds()) == false)
			if(cash >= structureMold.GetCost() && structures.size() < limitOfStructures)
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

		if (ingameMode == IngameMode::building)
			structureMold.Change(event.key.code);
	}
}

void GameState::OnUpdate()
{
	buttonFunctionConnector.Update(deltaTime);

	structureMold.sprite.setPosition(globalMousePos.x, 600);

	if ((IntersectsWithStructures(structureMold.sprite.getGlobalBounds()) || cash < structureMold.GetCost()) && ingameMode == IngameMode::building)
		structureMold.sprite.setColor(sf::Color(255, 10, 10, 50));
	else
		structureMold.sprite.setColor(sf::Color(255, 255, 255, 50));

	if (selected == true && ingameMode != IngameMode::selecting)
		UnselectStructure();

	if (localMousePos.x >= renderWindow->getSize().x - 50 && view.getCenter().x <= sizeOfTown)
		view.move(350 * deltaTime.asSeconds(), 0);
	if (localMousePos.x <= 50 && view.getCenter().x >= sizeOfTown * -1)
		view.move(-350 * deltaTime.asSeconds(), 0);


	player.SetStructureType(StructureType::nothing);
	for (auto s : structures)
		if (player.sprite.getGlobalBounds().contains(s.sprite.getPosition()))
		{
			player.SetStructureType(s.GetType());
			if(player.IsInsideStructure() == false)
				{
					if(s.GetType() == StructureType::hut) cash -= 5;
					else if(s.GetType() == StructureType::shop) cash += 5;
					
				player.SetCurrentStructureBounds(s.sprite.getGlobalBounds());
				}
							
			break;
		}
		

	switch (player.GetStructureType())
	{
	case StructureType::main:
		player.SetMoving(false);
		player.sprite.SetCurrentAnimation(AnimationType::stand);
		break;
	case StructureType::nothing:
		player.SetMoving(true);
		player.sprite.SetCurrentAnimation(AnimationType::walk);
		break;
	}

	if(player.sprite.getPosition().x >= sizeOfTown) player.SetSpeed(player.GetSpeed() * -1);
	if(player.sprite.getPosition().x <= sizeOfTown*-1) player.SetSpeed(player.GetSpeed() * -1);

	player.Update(deltaTime);

	player.sprite.Update(deltaTime);

	cashText.setString(std::to_string(cash));
}

void GameState::OnDraw()
{
	renderWindow->setView(view);

	if (ingameMode == IngameMode::building)
		renderWindow->draw(structureMold.sprite);

	for (auto s : structures)
		renderWindow->draw(s.sprite);

	renderWindow->draw(player);

	renderWindow->setView(renderWindow->getDefaultView());

	renderWindow->draw(topBar);
//	renderWindow->draw(btn);
	buttonFunctionConnector.Draw(renderWindow);

	renderWindow->draw(cashText);

	renderWindow->setView(view);
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
	cash += selStructure->GetCost()/2;
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

bool GameState::IntersectsWithStructures(const sf::FloatRect &rect)
{
	for (auto s : structures)
		if (rect.intersects(s.sprite.getGlobalBounds()))
			return true;
	return false;
}

bool GameState::ContainedByStructure(const sf::Vector2f &point)
{
	for (auto s : structures)
		if (s.sprite.getGlobalBounds().contains(point))
			return true;
	return false;
}

void GameState::PlaceStructure()
{
	cash -= structureMold.GetCost();
	structureMold.sprite.setColor(sf::Color(255,255,255,255));
	structures.push_back(structureMold);
	structureMold.sprite.setColor(sf::Color(255,255,255,100));
}

void GameState::SetupPlayer()
{
	player.sprite.setTexture(textures.GetTexture("CHAR_Player"));
	player.sprite.setPosition(0, 600);
	player.SetSpeed(50);
	player.SetNick("Player");
	player.SetFont(font);
	
	Animation stand;
	stand.AddFrame(sf::IntRect(704, 0, 176, 176));
	stand.AddFrame(sf::IntRect(704, 176, 176, 176));
	stand.SetDelay(sf::seconds(0.5f));

	Animation walk;
	walk.AddFrame(sf::IntRect(880, 0, 176, 176));
	walk.AddFrame(sf::IntRect(880, 176, 176, 176));
	walk.SetDelay(sf::seconds(0.4f));

	Animation jump;
	jump.AddFrame(sf::IntRect(176, 0, 176, 176));
	jump.AddFrame(sf::IntRect(176, 0, 176, 176));
	jump.SetDelay(sf::seconds(0.01f));

	player.sprite.AddAnimation(AnimationType::stand,stand);
	player.sprite.AddAnimation(AnimationType::walk, walk);
	player.sprite.SetCurrentAnimation(AnimationType::stand);
}