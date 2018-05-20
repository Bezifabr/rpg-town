#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <SFML\Graphics.hpp>

class State;

class StatesMachine {
	State* current;
public:
	StatesMachine();
	~StatesMachine();

	void init(State* s);
	void shutdown();

	void setCurrent(State* s);
	void handleEvent(sf::Event event, const sf::Window& window);
	void render(sf::RenderTarget& renderTarget);

	void Update(sf::Time deltaTime);

	bool IsRunning();

private:
	bool isRunning = false;
};


#endif