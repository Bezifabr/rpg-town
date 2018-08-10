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
	ViewManager view;
public:
	~StateMachine();

	void Init(std::shared_ptr<State> s, sf::RenderWindow* window);

	virtual void Push(std::shared_ptr<State> s) override;
	virtual void Switch(std::shared_ptr<State> s) override;
	virtual void Pop() override;

	virtual std::shared_ptr<State> Peek() override;

private:
	void Shutdown();

};


#endif
