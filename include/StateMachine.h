#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "SFML/Graphics.hpp"
#include "StateTransition.h"
#include "StateAccessor.h"
#include <memory>
#include <stack>

class State;

class StateMachine : public StateTransition, public StateAccessor
{
	std::stack<std::shared_ptr<State>> states;
	sf::RenderWindow* window;
	ViewManager view;
public:
	StateMachine();
	~StateMachine();

	void init(std::shared_ptr<State> s, sf::RenderWindow* window);
	void shutdown();

	virtual void Push(std::shared_ptr<State> s) override;
	virtual void Switch(std::shared_ptr<State> s) override;
	virtual void Pop() override;

	virtual std::shared_ptr<State> Peek() override;

};


#endif
