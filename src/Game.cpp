#include "Game.h"
#include <iostream>
#include <format>
#include <stdexcept>
#include <cstddef>
#include <cctype>

Game::Game()
	: board()
{}


Game::Game(int length)
	: board(length)
{}


std::string Game::requestMove() { 
	int maxIndex = board.getLength() * board.getLength();
	std::cout << std::format("Please enter a cell number in range 1-{} -> ", maxIndex);

	std::string move;
	std::cin >> move;
	return move;
}

std::pair<int, int> Game::decodeMove(const std::string& move) {
	size_t pos;
	int inputNum = std::stoi(move, &pos);
	if (pos != move.length()) {
		throw std::invalid_argument("non-digit char");
	}

	int maxIndex = board.getLength() * board.getLength();
	if (inputNum < 1 || inputNum > maxIndex) {
		throw std::out_of_range("number not in board range");
	}
	
	int cellNum = inputNum - 1;

	int row = cellNum / board.getLength();
	int col = cellNum % board.getLength();

	return {row, col};
}


void Game::makeMove(std::pair<int, int> pos) { 
	char letter = (board.getMoveCount() % 2 == 0) ? 'X' : 'O';
	board.setCell(pos.first, pos.second, letter);
}

void Game::runGameLoop() {
	printBoard();
	while (!isGameOver()) {
		try {
			std::string move = requestMove();
			std::pair<int, int> pos = decodeMove(move);
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


bool Game::isGameOver() {
	return board.isGameOver();
}


void Game::printBoard() {
	board.print();
}


void Game::printGameOver() {
	std::cout << "GAME OVER" << std::endl;
	if (board.isFull()) {
		std::cout << "Draw!" << std::endl;	
	}
	else {
		std::cout << std::format("Winner: {}!", (board.getMoveCount() % 2 == 0) ? 'O' : 'X') << std::endl;
		std::cout << std::format("Turns: {}", board.getMoveCount()) << std::endl;
	}
}
