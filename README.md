# TicTacToe

A simple Tic-Tac-Toe-game written in C++20

## Overview

This project is a Tic-Tac-Toe game, implemented in C++20 with a class-based modular architecture. The project contains a Makefile for building and running the application. The goal of this project is to improve my Git workflow and practice applying software engineering principles.


## Features

- Straightforward game logic
- Strict input validation
- Clean Text-based User Interface


## Requirements

- C++20 compatible compiler:
    - GCC/G++ 10+ 
    - Clang 12+
    - Visual Studio 2022 (MSVC 19.3X+)
- CMake 3.16+


## Build & Run

- Clone the repository:
```bash
git clone "https://github.com/copuremre/TicTacToe.git"
```

- Go inside the folder:
```bash
cd TicTacToe
```

- Build the project using CMake:
```bash
cmake -S . -B build
cmake --build build
```

- To run the game:
    - Windows
    ```bash
    ./build/bin/TicTacToe.exe
    ```
    - Linux/Mac
    ```bash
    ./build/bin/TicTacToe
    ```


## Project Structure

```bash
TicTacToe/
├── src/          # Source Files (.cpp)
├── include/      # Header Files (.h)
├── build/        # Build artifacts (generated)
├── CMakeLists.txt
└── README.md
```

## How To Play

This is a local multiplayer game designed for 2 players sharing the same computer. Before the game starts, players must decide their mark, either **X** or **O**.

When the game starts, a 3x3 empty board is created. Starting with **X**, players take turns placing their marks on empty cells by entering the cell number. The cell numbers and their corresponding cells are shown below:
```
┌─┬─┬─┐
│1│2│3│
├─┼─┼─┤
│4│5│6│
├─┼─┼─┤
│7│8│9│
└─┴─┴─┘
```

At any point of the game, if a row, column or diagonal of the board contains only **X** or only **O**, the player with that mark wins and the game ends. However, if the board fills up without any player achieving this, game ends in a draw.

After the game ends, players can restart or quit the game by entering **R** or **Q** respectively.


## Implementation Notes

- The board is represented by a 2D matrix using ```std:: vector```.
- Empty cells are represented with the space (' ') character.
- In ```Game::decodeMove()```, the ``` pos``` variable returned by ```std::stoi``` is compared with the input length to ensure user input only consists of digits, aside from any leading whitespaces.


## Licensing

© 2026 Emre Çöpür, All rights reserved.