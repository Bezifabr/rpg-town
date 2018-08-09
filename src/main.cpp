#include "StateMachine.h"
#include "StateUpdater.h"
#include "states/IntroState.h"
#include "Game.h"
#include "config.h"
#include <fstream>

using namespace std;

int main()
{

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

	Game game;
	game.Init(std::shared_ptr<State>(new IntroState));
	game.Start();

	return 0;
}
