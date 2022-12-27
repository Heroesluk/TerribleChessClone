#include "Game.h"
#include "cmath"
#include "iostream"

void Game::ClickToBoardCoords(uInt mouse_x, uInt mouse_y) {
    boardX = floor(mouse_x / PIECE_WIDTH);
    boardY = floor(mouse_y / PIECE_HEIGHT);

}


void Game::ChangeTurn() {

}


Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "My window") {

    board.SetupBoardPieces();
    current_player = true;

}

void Game::Draw(const std::vector<int> &pieces_locations, sf::RenderWindow &Window) {
    ColorPalette colors(sf::Color(102, 204, 102),
                        sf::Color(255, 243, 230),
                        sf::Color(255, 43, 103),
                        sf::Color(38, 38, 38));

    sf::RectangleShape tile(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            tile.setPosition(i * PIECE_WIDTH, j * PIECE_HEIGHT);

            if (i % 2 + j % 2 == 1) { tile.setFillColor(colors.white_tile); }
            else tile.setFillColor(colors.black_tile);
            Window.draw(tile);

        }


    }

    for (int ind = 0; ind<pieces_locations.size(); ind++) {
        if (pieces_locations[ind] != -1) {
            sf::RectangleShape piece_sprite(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
            int y = floor(ind/8);
            int x = ind%8;
            piece_sprite.setPosition(x * PIECE_WIDTH, y * PIECE_WIDTH);
            if (pieces_locations[ind]==1) {
                piece_sprite.setFillColor(colors.white_piece);
            } else piece_sprite.setFillColor(colors.black_piece);
            Window.draw(piece_sprite);

        }

    }
}

void Game::GameLoop() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed) {

                //
                ClickToBoardCoords(event.mouseButton.x, event.mouseButton.y);

                bool moved = board.MakeAction(boardX, boardY, turn%2);
                if(moved){
                    turn+=1;
                }



            }
        }

        window.clear();

        Draw(board.ReturnPiecesPositions(), window);

        window.display();
    }


}




