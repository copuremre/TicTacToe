CXX = g++
FLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic -I$(INCLUDE_FOLDER) -MMD -MP

SRC_FOLDER = src
INCLUDE_FOLDER = include
BUILD_FOLDER = build

SRC_PATH = $(wildcard $(SRC_FOLDER)/*.cpp)

OBJ_PATH = $(patsubst $(SRC_FOLDER)/%.cpp, $(BUILD_FOLDER)/%.o, $(SRC_PATH))

BIN = TicTacToe
BIN_PATH = $(BUILD_FOLDER)/$(BIN)


all: $(BIN_PATH)


$(BIN_PATH): $(OBJ_PATH)
	$(CXX) $(FLAGS) $^ -o $@


$(BUILD_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp | $(BUILD_FOLDER)
	$(CXX) -c $(FLAGS) $< -o $@


$(BUILD_FOLDER):
	mkdir -p $(BUILD_FOLDER)


run: $(BIN_PATH)
	./$(BIN_PATH)


clean:
	rm -rf $(BUILD_FOLDER)


-include $(OBJ_PATH:.o=.d)


.PHONY: all run clean
