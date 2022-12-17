cmake_minimum_required(VERSION 3.13)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Chess src/main.cpp headers/Piece.h headers/Board.h headers/Game.h src/Piece.cpp)
target_link_libraries(Chess sfml-graphics sfml-audio)