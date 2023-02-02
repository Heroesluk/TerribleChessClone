cmake_minimum_required(VERSION 3.13)
project(Chess)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES
        include/Piece.h
        include/Game.h
        include/Piece.h
        src/main.cpp
        src/Piece.cpp include/Board.h src/Board.cpp src/Game.cpp include/ColorPalette.h src/ColorPalette.cpp include/Pawn.h src/Pawn.cpp include/Rook.h src/Rook.cpp include/Bishop.h src/Bishop.cpp include/Queen.h src/Queen.cpp include/Knight.h src/Knight.cpp include/King.h src/King.cpp include/UI_Button.h src/UI_Button.cpp)



find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Chess ${SOURCE_FILES})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(Chess sfml-graphics sfml-audio)

#TESTs
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        test/TestFiles.cpp
        test/TestBoard.cpp
        src/Pawn.cpp
        src/Piece.cpp)


add_executable(TestProject ${SOURCE_TEST_FILES})

target_include_directories(TestProject PUBLIC include)

target_link_libraries (TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})