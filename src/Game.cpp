#include "Game.h"
#include <iostream>
#include <format>
#include <stdexcept>
#include <cstddef>
#include <cctype>

Game::Game()
	: board()
{}


std::string Game::requestMove() const { 
	int maxIndex = board.getLength() * board.getLength();
	std::cout << std::format("Please enter a cell number in range 1-{} -> ", maxIndex);

	std::string moveStr;
	std::cin >> moveStr;
	return moveStr;
}


std::pair<int, int> Game::decodeMove(const std::string& move) const {
	//Parse user move and ensure it only contains digits
	size_t pos;
	int inputNum = std::stoi(move, &pos);
	if (pos != move.length()) {
		throw std::invalid_argument("non-digit char");
	}

	//Ensure the number is in the board range
	int maxInputNum = board.getLength() * board.getLength();
	if (inputNum < 1 || inputNum > maxInputNum) {
		throw std::out_of_range("number not in board range");
	}

	//Convert from 1-indexed user input to 0-indexed array position
	int cellNum = inputNum - 1;
	int row = cellNum / board.getLength();
	int col = cellNum % board.getLength();

	return {row, col};
}


void Game::makeMove(std::pair<int, int> cell) { 
	char mark = (board.getMoveCount() % 2 == 0) ? 'X' : 'O';
	board.setCell(cell.first, cell.second, mark);
}

void Game::runGameLoop() {
	printBoard();

	while (!isGameOver()) {
		try {
			std::string moveStr = requestMove();
			std::pair<int, int> pos = decodeMove(moveStr);
			makeMove(pos);
			printBoard();
		}
		catch (const std::out_of_range&) {
			std::cout << "Cell number out of bounds." << std::endl;
			continue;
		}
		catch (const std::invalid_argument&) {
			std::cout << "Incorrect input format." << std::endl;
			continue;
		}
		catch (const std::logic_error&) {
			std::cout << "Cell already occupied." << std::endl;
			continue;
		}
	}
	printGameOver();
}


bool Game::isGameOver() const {
	return board.isGameOver();
}


void Game::printBoard() const {
	board.print();
}


void Game::printGameOver() const {
	std::cout << "GAME OVER" << std::endl;
	if (board.isFull()) {
		std::cout << "Draw!" << std::endl;	
	}
	else {
		std::cout << std::format("Winner: {}!", (board.getMoveCount() % 2 == 0) ? 'O' : 'X') << std::endl;
		std::cout << std::format("Turns: {}", board.getMoveCount()) << std::endl;
	}
}

void Game::reset() {
	board.reset();
}
