#include <iostream>
#include <time.h>
#include "Game.h"

// main function of the program, creates an object of Game class, calls run()  function of game class

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	Game game;

	game.run();

	return 0;
}

