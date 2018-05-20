#include <SFML/Graphics.hpp>
#include "Button.h"
#include "StatesMachine.h"
#include "states/IntroState.h"

int main()
{
	StatesMachine statesMachine;
	sf::RenderWindow window(sf::VideoMode(1000, 800), "RPG Town project");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	statesMachine.init(new IntroState, &window);



	while (window.isOpen())
	{
		if(!statesMachine.IsRunning())
			window.close();

		sf::Event event;
		sf::Time deltaTime;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			statesMachine.handleEvent(event, window);
		}

		statesMachine.Update(deltaTime);
		deltaTime = sf::Time::Zero;

		window.clear();
		statesMachine.render(window);
		window.display();
	}

	statesMachine.shutdown();

	return 0;
}