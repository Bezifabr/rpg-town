#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "ViewManager.h"

class StateMachine;
class State {
public:
	virtual void Load(StateMachine* stateMachine);
	virtual void Update(sf::Time deltaTime);
	virtual void Unload();

	virtual void HandleEvent(sf::Event event, const sf::Window& window) = 0;
	virtual void Render(sf::RenderTarget& renderTarget) = 0;

	bool IsGameFinished();

	void ConnectWithViewManager(ViewManager& viewMgr);
protected:
	virtual void OnUpdate() = 0;
	virtual void OnLoad() = 0;
	virtual void OnUnload() = 0;

	bool isGameFinished = false; 

	ViewManager* view;
	StateMachine* stateMachine;
	sf::Time deltaTime;
};

#endif // !STATE_H
