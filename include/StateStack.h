#ifndef STATE_STACK_H
#define STATE_STACK_H

#include <stack>
#include <memory>
#include "StateTransition.h"
#include "StateAccessor.h"
#include <SFML/Graphics/RenderWindow.hpp>

class StateStack : public StateTransition, public StateAccessor
{
    std::stack<std::shared_ptr<State>> states;
	std::shared_ptr<sf::RenderWindow> renderWindow;
public:
	void ConnectWithRenderWindow(std::shared_ptr<sf::RenderWindow> renderWindow);

    virtual void Push(std::shared_ptr<State> state) override;
    virtual void Pop() override;
    virtual void Switch(std::shared_ptr<State> state) override;
    virtual std::shared_ptr<State> Peek() override;

};

#endif // STATE_STACK_H
