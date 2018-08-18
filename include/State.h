#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "ViewManager.h"
#include <EntityContainer.h>

class StateTransition;
class State {
public:

	void ConnectWithStateTransition(StateTransition* transition);
	void ConnectWithRenderWindow(sf::RenderWindow* renderWindow);

	virtual void Load();
	virtual void Unload();

	virtual void Update(sf::Time deltaTime);
	virtual void HandleEvent(sf::Event event);
	virtual void Render();
	virtual void Refresh();

	bool IsGameFinished();

	void ConnectWithViewManager(ViewManager& viewMgr);
protected:
	virtual void OnUpdate() = 0;
	virtual void OnLoad() = 0;
	virtual void OnUnload() = 0;
	virtual void OnRender() = 0;
	virtual void OnHandleEvent() = 0;

	bool isGameFinished = false; 

	ViewManager* view;
	StateTransition* transition;
	EntityContainer container;
	
	sf::Time deltaTime;
	sf::Event event;
	sf::RenderWindow* renderWindow;
};

#endif // !STATE_H
