#include "Game.h"
#include "states/IntroState.h"
#include "config.h"

Game::Game()
{
	const std::string TITLE = RPG_TOWN_TITLE + " " + RPG_TOWN_VERSION_MAJOR + "." + RPG_TOWN_VERSION_MINOR + " " + RPG_TOWN_VERSION_RELEASE;

	renderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1000,800), TITLE);
	renderWindow->setFramerateLimit(60);
	renderWindow->setKeyRepeatEnabled(false);

	stateStack.ConnectWithRenderWindow(renderWindow);
	stateStack.Push(std::unique_ptr<State>(new IntroState()));
    updater.ConnectWithAccessor(stateStack);

	RunLoop();

}

void Game::RunLoop()
{
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;

    while (renderWindow->isOpen())
	{
		if(!updater.IsRunning())
			renderWindow->close();

		while (renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderWindow->close();
			updater.HandleEvent(event);
		}

		deltaTime = clock.getElapsedTime();
		updater.Update(deltaTime);
		clock.restart();

		renderWindow->clear();
		updater.Draw();
		renderWindow->display();
	}

}