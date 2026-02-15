#include "Game.h"
#include <iostream>

int main() {
	Game game;

	while (true) {
		game.runGameLoop();

		std::cout << "Restart: R  Quit: Q  -> ";
		char answer;
		std::cin >> answer;

		if (answer == 'r' || answer == 'R') {
			game.reset();
			continue;
		}
		else if (answer == 'q' || answer == 'Q') {
			break;
		}
	};

	return 0;
}
