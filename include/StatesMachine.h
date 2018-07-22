#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "SFML/Graphics.hpp"
#include <memory>

class State;

class StatesMachine {
	std::shared_ptr<State> current;
	sf::RenderWindow* window;
public:
	StatesMachine();
	~StatesMachine();

	void init(std::shared_ptr<State> s, sf::RenderWindow* window);
	void shutdown();

	void setCurrent(std::shared_ptr<State> s);
	void handleEvent(sf::Event event, const sf::Window& window);
	void render(sf::RenderTarget& renderTarget);

	void Update(sf::Time deltaTime);

	bool IsRunning();

	void setView(const sf::View& view);
	sf::Vector2f ConvertToCoordinate(sf::Vector2i position);
	sf::Vector2i ConvertToPixels(sf::Vector2f position);
private:
	bool isRunning = false;

};


#endif
