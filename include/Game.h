//
// Created boardY heroesluk on 17.12.22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#define HEIGHT 800
#define WIDTH 800
#define PIECE_HEIGHT (HEIGHT/8)
#define PIECE_WIDTH (WIDTH/8)

#include "Board.h"
#include "SFML/Graphics.hpp"
#include "ColorPalette.h"

using uInt = unsigned int;


class Game {
private:
    uInt mx;
    uInt my;
    uInt boardX;
    uInt boardY;
    ColorPalette palette;
    Board board;

    sf::RenderWindow window;
    bool current_player;


public:
    Game();

    void GameLoop();

    void ClickToBoardCoords(uInt mouse_x, uInt mouse_y);


    void ChangeTurn();

    void Draw(const std::vector<std::shared_ptr<Piece>> &pieces, sf::RenderWindow &Window);


};

#endif //CHESS_GAME_H
