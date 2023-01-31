//
// Created boardY heroesluk on 19.12.22.
//

#ifndef CHESS_COLORPALETTE_H
#define CHESS_COLORPALETTE_H

#include <SFML/Graphics/Color.hpp>

class ColorPalette {
public:
    sf::Color black_tile;
    sf::Color white_tile;
    sf::Color white_piece;
    sf::Color black_piece;
    sf::Color button_color;
    sf::Color text_color;

    ColorPalette();
    ColorPalette(sf::Color bt, sf::Color wt, sf::Color wp, sf::Color bp);

};


#endif //CHESS_COLORPALETTE_H
