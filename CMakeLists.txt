    cmake_minimum_required(VERSION 3.16)
    project(TicTacToe LANGUAGES CXX)

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(TicTacToe 
        src/main.cpp
        src/Board.cpp
        src/Game.cpp
    )
    
    set_target_properties(TicTacToe PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<0:>
    )
    
    target_include_directories(TicTacToe PRIVATE include)

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(TicTacToe PRIVATE -Wall -Wextra -Wpedantic)
    elseif (MSVC)
        target_compile_options(TicTacToe PRIVATE /W4)
    endif()