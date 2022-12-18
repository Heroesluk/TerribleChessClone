#include <SFML/Graphics.hpp>
#include "iostream"

#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include "SFML/Graphics/Color.hpp"

#define HEIGHT 800
#define WIDTH 800
#define PIECE_HEIGHT (HEIGHT/8)
#define PIECE_WIDTH (WIDTH/8)


class ColorPalette {
public:
    sf::Color black_tile;
    sf::Color white_tile;
    sf::Color white_piece;
    sf::Color black_piece;

    ColorPalette(sf::Color bt, sf::Color wt, sf::Color wp, sf::Color bp) {
        black_tile = bt;
        black_piece = bp;
        white_tile = wt;
        white_piece = wp;
    }
};


//void draw(const std::unordered_map<std::tuple<int, int>, std::shared_ptr<Piece>> &pieces, sf::RenderWindow &Window) {
//    ColorPalette colors(sf::Color(102, 204, 102),
//                        sf::Color(255, 243, 230),
//                        sf::Color(242, 242, 242),
//                        sf::Color(38, 38, 38));
//
//    sf::RectangleShape tile(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 9; j++) {
//            tile.setPosition(i * PIECE_WIDTH, j * PIECE_HEIGHT);
//
//            if (i % 2 + j % 2 == 1) { tile.setFillColor(colors.white_tile);}
//            else tile.setFillColor(colors.black_tile);
//            Window.draw(tile);
//
//        }
//
//
//    }
//
//    for(auto& [position, piece]: pieces){
//        sf::RectangleShape piece_sprite(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
//        const auto[x,y] = piece->GetPos();
//        piece_sprite.setPosition(x*PIECE_WIDTH,y*PIECE_WIDTH);
//        if(piece->GetColor()== false){
//            piece_sprite.setFillColor(colors.black_piece);
//        }
//        else piece_sprite.setFillColor(colors.white_piece);
//
//        Window.draw(piece_sprite);
//
//    }
//
//
//
//
//}


int main() {


    Piece p1(10,10,false);





    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
//        draw(p1, window);

        window.display();
    }


    return 0;
}