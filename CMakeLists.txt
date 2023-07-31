cmake_minimum_required(VERSION 3.26)
project(blackjack_simulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(blackjack_simulation src/main.cpp
        src/Card.cpp
        src/Card.h
        src/CardStack.cpp
        src/CardStack.h
        src/GameSettings.h
        src/util.h
)
