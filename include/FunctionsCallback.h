#ifndef FUNCTIONS_CALLBACK_H
#define FUNCTIONS_CALLBACK_H

#include <vector>
#include <list>
#include <functional>
#include <SFML/System/Time.hpp>

class FunctionsCallback
{
	std::vector<std::function<void()>> callbackVector;
	const std::list<int>* pressedButtons;
public:
	void ConnectWithPressedButtons(const std::list<int>* pressedButtons);

	void AddFunction(std::function<void()> function);
	void Clear();

	void Update(sf::Time deltaTime);
};

#endif // !FUNCTIONS_CALLBACK_H
