#include "StateMachine.h"
#include "states/IntroState.h"
#include "config.h"
#include <fstream>

using namespace std;

int main()
{
	StateMachine stateMachine;
	sf::RenderWindow window(sf::VideoMode(1000, 800), "RPG Town project");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	stateMachine.init(std::shared_ptr<State>(new IntroState), &window);


	ifstream file;
	ofstream error;
	error.open("startup-error.txt");

	file.open("libgcc_s_dw2-1.dll");
	if(!file.good())
		error << "Error: Missing file 'libgcc_s_dw2-1.dll'\n";
	file.close();

	file.open("libstdc++-6.dll");
	if(!file.good())
		error << "Error: Missing file 'libstdc++-6.dll'\n";
	file.close();

	file.open("sfml-graphics-2.dll");
	if(!file.good())
		error << "Error: Missing file 'sfml-graphics-2.dll'\n";
	file.close();

	file.open("sfml-system-2.dll");
	if(!file.good())
		error << "Error: Missing file 'sfml-system-2.dll'\n";
	file.close();

	file.open("sfml-window-2.dll");
	if(!file.good())
		error << "Error: Missing file 'sfml-window-2.dll'\n";
	file.close();

	error.close();

	ifstream errorFile("startup-error.txt");

	if(errorFile.peek() == std::ifstream::traits_type::eof())
		remove("startup-error.txt");


	while (window.isOpen())
	{
		if(!stateMachine.IsRunning())
			window.close();

		sf::Event event;
		sf::Time deltaTime;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			stateMachine.handleEvent(event, window);
		}

		stateMachine.Update(deltaTime);
		deltaTime = sf::Time::Zero;

		window.clear();
		stateMachine.render(window);
		window.display();
	}

	stateMachine.shutdown();

	return 0;
}
