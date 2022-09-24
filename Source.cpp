#include <iostream>
#include "Game.h"
#include <time.h>

using namespace std;

int main() 
{
	srand(static_cast<unsigned int>(time(0)));
	Game game;
	game.run();

	return 0;
}