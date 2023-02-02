#include "ColorPalette.h"


ColorPalette::ColorPalette() {
    black_tile = sf::Color(102, 204, 102);
    white_tile = sf::Color(255, 243, 230);
    pos_move = sf::Color(255, 43, 103);
    black_piece = sf::Color(38, 38, 38);

}

ColorPalette::ColorPalette(sf::Color bt, sf::Color wt, sf::Color wp, sf::Color bp) {
        black_tile = bt;
        black_piece = bp;
        white_tile = wt;
    pos_move = wp;

};
