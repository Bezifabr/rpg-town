#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "SFML/Graphics.hpp"
#include <memory>
#include <stack>

class State;

class StatesMachine
{
	std::stack<std::shared_ptr<State>> states;
	sf::RenderWindow* window;
	bool isRunning = false;
public:
	StatesMachine();
	~StatesMachine();

	void init(std::shared_ptr<State> s, sf::RenderWindow* window);
	void shutdown();

	void Push(std::shared_ptr<State> s);
	void Switch(std::shared_ptr<State> s);
	void Pop();

	std::shared_ptr<State> Peek();

	void handleEvent(sf::Event event, const sf::Window& window);
	void render(sf::RenderTarget& renderTarget);
	void Update(sf::Time deltaTime);

	bool IsRunning();

	void setView(const sf::View& view);
	sf::Vector2f ConvertToCoordinate(sf::Vector2i position);
	sf::Vector2i ConvertToPixels(sf::Vector2f position);
};


#endif
