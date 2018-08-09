#include "states/IntroState.h"
#include "Game.h"
#include "config.h"

using namespace std;

int main()
{
	Game game;
	game.Init(std::shared_ptr<State>(new IntroState));
	game.Start();

	return 0;
}
