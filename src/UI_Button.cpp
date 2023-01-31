#include "UI_Button.h"


Button::Button(uInt posx, uInt posy, uInt sizex, uInt sizey, std::string text_str, int button_number){
    this->posx = posx;
    this->posy = posy;
    this->sizex = sizex;
    this->sizey = sizey;
    this->text_str = text_str;
    this->button_number = button_number;


    btn_rect.setSize(sf::Vector2f(sizex,sizey));
    btn_rect.setPosition(sf::Vector2f(posx,posy));
    btn_rect.setFillColor(sf::Color::White);

    text_color = sf::Color(0,0,0);
    btext.setCharacterSize(24);
    btext.setFillColor(sf::Color::Black);
    btext.setString(text_str);
    btext.setStyle(sf::Text::Bold);
    btext.setPosition(posx,posy);






}

sf::Text Button::ReturnText() {
    return btext;
}

sf::RectangleShape Button::ReturnButton(){
    return btn_rect;

}

int Button::CheckIfClicked(uInt mx, uInt my) {
    if(mx<posx+sizex && mx>posx && my<sizey+posy && my>posy){

        return button_number;
    }

    return 0;
}
