#include "Board.h"
#include <iostream>
#include <string>

Board::Board()
	: grid(3,std::vector<char>(3,' ')), length(3), moveCount(0)
{}


Board::Board(int length)
	: grid(length,std::vector<char>(length,' ')), length(length), moveCount(0)
{}


int Board::getLength() {
	return length;
}


int Board::getMoveCount() {
	return moveCount;
}


char Board::getCell(int row, int col) {
	return grid.at(row).at(col);
}


bool Board::isCellEmpty(int row, int col) {
	return (grid.at(row).at(col) == ' ');
}


void Board::setCell(int row, int col, char letter) {
	if (!isCellEmpty(row, col)) {
		throw std::logic_error("cell occupied");
	}
	grid.at(row).at(col) = letter;
	moveCount++;
}


bool Board::isFull() {
	for (int row = 0; row < length; row++) {
		for (int col = 0; col < length; col++) {
			if (grid[row][col] == ' ') {
				return false;
			}
		}
	}
	return true;
}


bool Board::isGameOver() {
	bool isMatch;

	for (int row = 0; row < length; row++) {
		isMatch = true;
		for (int col = 0; col < length - 1; col++) {
			if (getCell(row, col) == ' ' || getCell(row, col) != getCell(row, col + 1)) {
				isMatch = false;
				break;
			}
		}
		if (isMatch) {
			return true;
		}
	}

	for (int col = 0; col < length; col++) {
		isMatch = true;
		for (int row = 0; row < length - 1; row++) {
			if (getCell(row, col) == ' ' || getCell(row, col) != getCell(row + 1, col)) {
				isMatch = false;
				break;
			}
		}
		if (isMatch) {
			return true;
		}
	}

	isMatch = true;
	for (int i = 0; i < length - 1; i++) {
		if (getCell(i, i) == ' ' || getCell(i, i) != getCell(i + 1, i + 1)) {
			isMatch = false;
			break;
		}
	}
	if (isMatch) {
		return true;
	}


	isMatch = true;
	for (int i = 0; i < length - 1; i++) {
		if (getCell(i, length - 1 - i) == ' ' || getCell(i, length - 1 - i) != getCell(i + 1, length - 2 - i)) {
			isMatch = false;
			break;
		}
	}
	if (isMatch) {
		return true;
	}

	return isFull();

}


void Board::print() {
	std::string sprite_top = "┌";
	for (int i = 0; i < length - 1; i++) {
		sprite_top.append("─┬");
	}
	sprite_top.append("─┐\n");


	std::string sprite_bottom = "└";
	for (int i = 0; i < length - 1; i++) {
		sprite_bottom.append("─┴");
	}
	sprite_bottom.append("─┘");


	std::string sprite_horiz_splitter = "├";
	for (int i = 0; i < length - 1; i++) {
		sprite_horiz_splitter.append("─┼");
	}
	sprite_horiz_splitter.append("─┤\n");


	std::string sprite = sprite_top;
	for (int row = 0; row < length; row++) {
		sprite.append("│");
		for (int col = 0; col < length; col++) {
			sprite += grid[row][col];
			sprite.append("│");
		}
		sprite.append("\n");
		if (row < length - 1) {
			sprite.append(sprite_horiz_splitter);
		}
	}
	sprite.append(sprite_bottom);

	std::cout << sprite << std::endl;
}
