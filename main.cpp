#include "Game.h"
#include <iostream>

int main() {
	char answer;
	do {
		Game game;
        game.runGameLoop();
		std::cout << "Restart: R  Quit: Q  -> ";
		std::cin >> answer;	
	} while (answer == 'r' || answer == 'R');

	return 0;
}
