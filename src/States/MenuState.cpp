#include "states/MenuState.h"
#include "states/GameState.h"
#include "StateMachine.h"
#include <iostream>

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
	
	cout << "Menu loaded" << endl;
}

void MenuState::OnUnload()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::OnUpdate()
{
	btnPlay.update();
	btnLoad.update();
	btnExit.update();

	if (btnExit.isPressed())
	{	
		isGameFinished = true;
	}

	if (btnPlay.isPressed())
	{
		stateMachine->Switch(std::shared_ptr<State>(new GameState));
	}

}

void MenuState::HandleEvent(sf::Event event, const sf::Window& window)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}

	sf::Vector2f mousePos = stateMachine->ConvertToCoordinate(sf::Mouse::getPosition(window));
		btnLoad.handleEvent(event, mousePos);
		btnExit.handleEvent(event, mousePos);
		btnPlay.handleEvent(event, mousePos);

}

void MenuState::Render(sf::RenderTarget & renderTarget)
{
		renderTarget.draw(title);
		renderTarget.draw(author);
		renderTarget.draw(TBC);
		renderTarget.draw(btnExit);
		renderTarget.draw(btnLoad);
		renderTarget.draw(btnPlay);
}

