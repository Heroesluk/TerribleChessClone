#include "UI_Button.h"


Button::Button(uInt posx, uInt posy, uInt sizex, uInt sizey){
    this->posx = posx;
    this->posy = posy;
    this->sizex = sizex;
    this->sizey = sizey;

    button_color = sf::Color(255,255,255);
    text_color = sf::Color(0,0,0);
    btext.setCharacterSize(24);
    btext.setFillColor(sf::Color::Black);
    btext.setString("DZiala");
    btext.setStyle(sf::Text::Bold);
    btext.setPosition(posx,posy);




    btn_rect.setSize(sf::Vector2f(sizex,sizey));
    btn_rect.setPosition(sf::Vector2f(posx,posy));
    btn_rect.setFillColor(sf::Color::White);

}

sf::Text Button::ReturnText() {
    return btext;
}

sf::RectangleShape Button::ReturnButton(){
    return btn_rect;

}
