//
// Created by heroesluk on 31.01.23.
//

#ifndef CHESS_UI_BUTTON_H
#define CHESS_UI_BUTTON_H
using uInt = unsigned int;
#include "ColorPalette.h"
#include "SFML/Graphics.hpp"

class Button{
public:
    uInt posx, posy;
    uInt sizex, sizey;
    sf::Color button_color;
    sf::Color text_color;
    sf::Text btext;
    sf::RectangleShape btn_rect;

    void on_click();

    Button(uInt posx, uInt posy, uInt sizex, uInt sizey);

    sf::Text ReturnText();
    sf::RectangleShape ReturnButton();


};

#endif //CHESS_UI_BUTTON_H
