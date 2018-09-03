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

	topBarTexture.loadFromFile("resources/Top Bar.png");
	topBar.setTexture(topBarTexture);

	player.texture.loadFromFile("resources/PlayerTex.png");
	player.sprite.setTexture(player.texture);
	player.sprite.setPosition(0, 600);
	player.SetSpeed(50);
	player.SetNick("Player");
	player.SetFont(font);

	bld_hut.texture.loadFromFile("resources/Test/hut.png");
	bld_hut.sprite.setTexture(bld_hut.texture);
	bld_hut.sprite.setOrigin(256 / 2, 256 / 2);
	bld_hut.SetType(StructureType::hut);
	bld_hut.sprite.setColor(sf::Color(255, 255, 255, 100));

	bld_main.texture.loadFromFile("resources/Test/main.png");
	bld_main.sprite.setTexture(bld_main.texture);
	bld_main.sprite.setOrigin(256 / 2, 256 / 2);
	bld_main.SetType(StructureType::main);
	bld_main.sprite.setColor(sf::Color(255, 255, 255, 100));

	bld_shop.texture.loadFromFile("resources/Test/shop.png");
	bld_shop.sprite.setTexture(bld_shop.texture);
	bld_shop.sprite.setOrigin(256 / 2, 256 / 2);
	bld_shop.SetType(StructureType::shop);
	bld_shop.sprite.setColor(sf::Color(255, 255, 255, 100));

	currentStructureType = StructureType::hut;
	previewStructure = &bld_hut;

	CreateAnimationTester();

	font.loadFromFile("resources/Text font.ttf");

	cash = 100;
	cashText.setString(std::to_string(cash));
	cashText.setFont(font);

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

		if (ingameMode == IngameMode::building && IntersectsWithStructures(previewStructure->sprite.getGlobalBounds()) == false)
			if(cash >= 10 && structures.size() < limitOfStructures)
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
		TestAnimations();

		if (ingameMode == IngameMode::selecting)
			if (event.key.code == sf::Keyboard::Delete && selected == true)
				RemoveSelectedStructure();

		if (ingameMode == IngameMode::building)
			ChangeCurrentStructure();
	}
}

void GameState::OnUpdate()
{

	previewStructure->sprite.setPosition(globalMousePos.x, 600);

	if ((IntersectsWithStructures(previewStructure->sprite.getGlobalBounds()) || cash < 10) && ingameMode == IngameMode::building)
		previewStructure->sprite.setColor(sf::Color(255, 10, 10, 50));
	else
		previewStructure->sprite.setColor(sf::Color(255, 255, 255, 50));

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
			break;
		}

	switch (player.GetStructureType())
	{
	case StructureType::main:
		player.SetMoving(false);
		player.sprite.SetCurrentAnimation(AnimationType::stand);
		player.SetMoving(false);
		break;

	case StructureType::nothing:
		player.SetMoving(true);
		player.sprite.SetCurrentAnimation(AnimationType::walk);
		break;
	}

	if(player.sprite.getPosition().x >= sizeOfTown) player.SetSpeed(player.GetSpeed() * -1);
	if(player.sprite.getPosition().x <= sizeOfTown*-1) player.SetSpeed(player.GetSpeed() * -1);

	player.Update(deltaTime);

	aniSprite.Update(deltaTime);
	player.sprite.Update(deltaTime);

	cashText.setString(std::to_string(cash));
}

void GameState::OnDraw()
{
	renderWindow->setView(view);

	if (ingameMode == IngameMode::building)
		renderWindow->draw(previewStructure->sprite);

	for (auto s : structures)
		renderWindow->draw(s.sprite);

	renderWindow->draw(player);
	renderWindow->draw(aniSprite);

	renderWindow->setView(renderWindow->getDefaultView());

	renderWindow->draw(topBar);
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

void GameState::ChangeCurrentStructure()
{
	switch (event.key.code)
	{
	case sf::Keyboard::Num1:
		currentStructureType = StructureType::hut;
		previewStructure = &bld_hut;
		break;
	case sf::Keyboard::Num2:
		currentStructureType = StructureType::main;
		previewStructure = &bld_main;
		break;
	case sf::Keyboard::Num3:
		currentStructureType = StructureType::shop;
		previewStructure = &bld_shop;
		break;
	}
}

void GameState::RemoveSelectedStructure()
{
	selected = false;
	structures.erase(selStructure);
	cash += 5;
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

	cash -= 10;

	switch (currentStructureType)
	{
	case StructureType::main:
		bld_main.sprite.setColor(sf::Color(255, 255, 255, 255));
		structures.push_back(bld_main);
		bld_main.sprite.setColor(sf::Color(255, 255, 255, 100));
		break;
	case StructureType::hut:
		bld_hut.sprite.setColor(sf::Color(255, 255, 255, 255));
		structures.push_back(bld_hut);
		bld_hut.sprite.setColor(sf::Color(255, 255, 255, 100));
		break;
	case StructureType::shop:
		bld_shop.sprite.setColor(sf::Color(255, 255, 255, 255));
		structures.push_back(bld_shop);
		bld_shop.sprite.setColor(sf::Color(255, 255, 255, 100));
		break;
	}
}

void GameState::CreateAnimationTester()
{
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

	aniSprite.setTexture(player.texture);
	aniSprite.AddAnimation(AnimationType::stand, stand);
	aniSprite.AddAnimation(AnimationType::walk, walk);
	aniSprite.AddAnimation(AnimationType::jump, jump);
	aniSprite.SetCurrentAnimation(AnimationType::stand);

	player.sprite.AddAnimation(AnimationType::stand,stand);
	player.sprite.AddAnimation(AnimationType::walk, walk);
	player.sprite.SetCurrentAnimation(AnimationType::stand);
}

void GameState::TestAnimations()
{
	switch (event.key.code)
	{
	case sf::Keyboard::Q:
		aniSprite.SetCurrentAnimation(AnimationType::stand);
		break;
	case sf::Keyboard::W:
		aniSprite.SetCurrentAnimation(AnimationType::jump);
		break;
	case sf::Keyboard::E:
		aniSprite.SetCurrentAnimation(AnimationType::walk);
		break;
	}
}