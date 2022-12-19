#include "Game.h"
#include "math.h"

void Game::OnClick(uInt mouse_x, uInt mouse_y) {
    bx = floor(mouse_x/PIECE_WIDTH);
    by = floor(mouse_y/PIECE_HEIGHT);

}

bool Game::MakeAction() {

    return 0;

}

void Game::ChangeTurn() {

}


Game::Game(): window(sf::VideoMode(WIDTH, HEIGHT), "My window")  {

    board.SetupBoardPieces();

}

void Game::Draw(const std::vector<std::shared_ptr<Piece>> &pieces, sf::RenderWindow &Window) {
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

    for (auto piece: pieces) {
        sf::RectangleShape piece_sprite(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
        auto [x, y] = piece->GetPos();
        piece_sprite.setPosition(x * PIECE_WIDTH, y * PIECE_WIDTH);
        if (piece->GetColor()) {
            piece_sprite.setFillColor(colors.white_piece);
        } else piece_sprite.setFillColor(colors.black_piece);

        Window.draw(piece_sprite);
    }
}

void Game::GameLoop() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            else if(event.type == sf::Event::MouseButtonReleased){
                OnClick(event.mouseButton.x, event.mouseButton.y);

                mx = event.mouseButton.x ;
                my = event.mouseButton.y;

                MakeAction();


            }
        }

        window.clear();
        Draw(board.ReturnAllPieces(), window);

        window.display();
    }


}




