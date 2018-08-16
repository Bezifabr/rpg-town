#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "ViewManager.h"
#include <EntityContainer.h>

class StateTransition;
class State {
public:

// Add Draw() and Refresh() methods
// Iterate entities from EntityContainer
	virtual void Load(StateTransition* stateMachine);
	virtual void Unload();

	virtual void Update(sf::Time deltaTime);
	virtual void HandleEvent(sf::Event event, const sf::Window& window) = 0;
	virtual void Render(sf::RenderTarget& renderTarget) = 0;
	virtual void Refresh() {}

	bool IsGameFinished();

	void ConnectWithViewManager(ViewManager& viewMgr);
protected:
	virtual void OnUpdate() = 0;
	virtual void OnLoad() = 0;
	virtual void OnUnload() = 0;

	bool isGameFinished = false; 

	ViewManager* view;
	StateTransition* transition;
	EntityContainer container;
	sf::Time deltaTime;
};

#endif // !STATE_H
