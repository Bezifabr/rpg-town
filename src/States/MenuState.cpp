#include "states/MenuState.h"
#include "states/GameState.h"
#include "StateMachine.h"
#include <iostream>
#include "Components/SpriteComponent.h"
#include "Components/TextComponent.h"

using std::cout;
using std::endl;

void MenuState::OnLoad()
{
	titleFont.loadFromFile("resources/Title font.ttf");
	textFont.loadFromFile("resources/Text font.ttf");

	title.setFont(titleFont);
	title.setCharacterSize(60);
	title.setStyle(sf::Text::Bold);
	title.setString("RPG Town project");
	title.setPosition(300, 50);

	author.setFont(textFont);
	author.setCharacterSize(35);
	author.setPosition(75, 650);
	author.setString("Bezifabr");

	TBC.setFont(textFont);
	TBC.setCharacterSize(35);
	TBC.setPosition(700, 650);
	TBC.setString("To be continued...");

	texture.loadFromFile("resources/grass.png");
	buttonTexture.loadFromFile("resources/btnText.png");


	btnPlay.setTexture(buttonTexture);
	btnLoad.setTexture(buttonTexture);
	btnExit.setTexture(buttonTexture);

	btnExit.setPosition(350, 400);
	btnExit.setFont(textFont);
	btnExit.setString("Exit");

	btnLoad.setPosition(350, 300);
	btnLoad.setFont(textFont);
	btnLoad.setString("Load");

	btnPlay.setPosition(350, 200);
	btnPlay.setFont(textFont);
	btnPlay.setString("Play");
	
	container.Add("BICO_LOAD");
	auto load = container.GetLastAddedEntity().lock();
	load->AddComponent<SpriteComponent>("resources/btnText.png");
	load->GetComponent<SpriteComponent>().sprite.setPosition(350, 300);
	load->AddComponent<TextComponent>("Load", &textFont, sf::Vector2f(350,300));

	cout << "Menu loaded" << endl;
}

void MenuState::OnUnload()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::OnUpdate()
{
	btnPlay.Update(deltaTime);
//	btnLoad.Update(deltaTime);
	btnExit.Update(deltaTime);

	if (btnExit.IsPressed())
	{	
		isGameFinished = true;
	}

	if (btnPlay.IsPressed())
	{
		transition->Switch(std::shared_ptr<State>(new GameState));
	}

}

void MenuState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}

	sf::Vector2f mousePos = view->ConvertToCoordinate(sf::Mouse::getPosition((*renderWindow)));
//		btnLoad.HandleEvent(event, mousePos);
		btnExit.HandleEvent(event, mousePos);
		btnPlay.HandleEvent(event, mousePos);

}

void MenuState::OnRender()
{
		renderWindow->draw(title);
		renderWindow->draw(author);
		renderWindow->draw(TBC);
		renderWindow->draw(btnExit);
//		renderWindow->draw(btnLoad);
		renderWindow->draw(btnPlay);
}

