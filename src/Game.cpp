#include "Game.h"

void Game::Init(std::shared_ptr<State> state)
{
	window.create(sf::VideoMode(1000, 800), "RPG Town project");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
    stateMachine.Init(state,&window);
    updater.ConnectWithAccessor(stateMachine);
}

void Game::Start()
{
    RunLoop();
}

void Game::RunLoop()
{
    while (window.isOpen())
	{
		if(!updater.IsRunning())
			window.close();

		updater.Refresh();

		sf::Event event;
		sf::Time deltaTime;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			updater.HandleEvent(event, window);
		}

		updater.Update(deltaTime);
		deltaTime = sf::Time::Zero;

		window.clear();
		updater.Draw(window);
		window.display();
	}

}