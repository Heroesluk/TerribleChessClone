#include <SFML/Graphics.hpp>
#include "iostream"

#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include "Pawn.h"
#include "SFML/Graphics/Color.hpp"

#define HEIGHT 800
#define WIDTH 800
#define PIECE_HEIGHT (HEIGHT/8)
#define PIECE_WIDTH (WIDTH/8)


int main() {

    Game game;
    game.GameLoop();

    return 0;
}