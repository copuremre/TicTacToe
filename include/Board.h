#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
	public:
		Board();
		Board(int length);

		int getLength();
		int getMoveCount();

		char getCell(int row, int col);
		bool isCellEmpty(int row, int col);
		void setCell(int row, int col, char letter);

		bool isFull();
		bool isGameOver();
		void print();
	private:
		std::vector<std::vector<char>> grid;
		int length;
		int moveCount;
};



#endif
