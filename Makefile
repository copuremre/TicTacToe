CXX = g++
FLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic

SRC = main.cpp Game.cpp Board.cpp
OBJ = $(SRC:.cpp=.o)

BIN = TicTacToe


all: $(BIN)


$(BIN): $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@


%.o: %.cpp
	$(CXX) -c $(FLAGS) $^ -o $@


run: $(BIN)
	./$(BIN)


clean:
	rm -f $(BIN) $(OBJ)


.PHONY: all run clean
