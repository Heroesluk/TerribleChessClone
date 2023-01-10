#include "Game.h"
#include "cmath"
#include "iostream"
#include <typeinfo>

void Game::ClickToBoardCoords(uInt mouse_x, uInt mouse_y) {
    boardX = floor(mouse_x / PIECE_WIDTH);
    boardY = floor(mouse_y / PIECE_HEIGHT);

}

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "My window") {

    board.SetupBoardPieces();

}



void Game::Draw(const std::vector<std::shared_ptr<Piece>>& piece_map, sf::RenderWindow &Window) {
    auto[window_width,window_height] =  Window.getSize();


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


    sf::Texture texture;

    std::string piece_name = "Pawn";
    std::string file_type = ".png";
    if(!texture.loadFromFile(piece_name+file_type)){
        std::cout<<'huj';
        exit(2);
    }
    auto[texture_width, texture_height] = texture.getSize();


    for (auto &it: piece_map) {
        if (it != nullptr) {
            //sf::RectangleShape piece_sprite(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
            sf::Sprite piece_sprite;
            piece_sprite.setTexture(texture);

            float width_scale = (float) ((float) window_width/8)/(float) texture_width;
            float height_scale = (float) ((float) window_height/8)/(float) texture_height;

            piece_sprite.setScale(width_scale,height_scale);

            int y = it->pos_y;
            int x = it->pos_x;
            piece_sprite.setPosition(x * PIECE_WIDTH, y * PIECE_WIDTH);

//            if (it->GetColor()) {
//                piece_sprite.setFillColor(colors.white_piece);
//            } else piece_sprite.setFillColor(colors.black_piece);
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

                bool moved = board.MakeAction(boardX, boardY, turn % 2);
                if (moved) {
                    turn += 1;
                }


            }
        }

        window.clear();
        
        Draw(board.ReturnAllPieces(), window);

        window.display();
    }


}




