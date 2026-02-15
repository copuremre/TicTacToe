#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <string>
#include <utility>

class Game {
	public:
		Game();

		void runGameLoop();

		bool isGameOver() const;
		void printBoard() const;
		void printGameOver() const;
		void reset();
	private:
		Board board;

		std::string requestMove() const;
		std::pair<int, int> decodeMove(const std::string& move) const;
		void makeMove(std::pair<int, int> cell);
};

#endif
