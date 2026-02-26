#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <string>
#include <utility>

class Game {
	public:
		Game();
		Game(int length);

		std::string requestMove();
		std::pair<int, int> decodeMove(const std::string& move);
		void makeMove(std::pair<int, int> pos);

		void runGameLoop();

		bool isGameOver();
		void printBoard();
		void printGameOver();
	private:
		Board board;
};

#endif
