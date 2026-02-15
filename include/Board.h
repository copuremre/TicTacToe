#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
	public:
		Board();

		int getLength() const;
		int getMoveCount() const;

		char getCell(int row, int col) const;
		bool isCellEmpty(int row, int col) const;
		void setCell(int row, int col, char mark);

		bool isFull() const;
		bool isGameOver() const;
		void print() const;
		void reset();
	private:
		std::vector<std::vector<char>> grid;
		const int length;
		int moveCount;
};

#endif
