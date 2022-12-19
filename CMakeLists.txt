cmake_minimum_required(VERSION 3.13)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        include/Piece.h
        include/Game.h
        include/Piece.h
        src/main.cpp
        src/Piece.cpp include/Board.h src/Board.cpp src/Game.cpp include/ColorPalette.h src/ColorPalette.cpp)



find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Chess ${SOURCE_FILES})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include

)
target_link_libraries(Chess sfml-graphics sfml-audio)