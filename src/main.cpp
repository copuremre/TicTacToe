#include "Game.h"
#include <iostream>

#ifdef _WIN32
	#include <windows.h>
#endif

int main() {
	#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
	#endif

	char answer;
	do {
		Game game;
        game.runGameLoop();
		std::cout << "Restart: R  Quit: Q  -> ";
		std::cin >> answer;	
	} while (answer == 'r' || answer == 'R');

	return 0;
}
