#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <SFML\Graphics.hpp>

class State;

class StatesMachine {
	State* current;
public:
	StatesMachine();

	void setCurrent(State* s);


	void Update(sf::Time deltaTime);

};


#endif