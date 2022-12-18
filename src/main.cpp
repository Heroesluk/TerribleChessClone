#include <SFML/Graphics.hpp>
#include "iostream"

#include "Piece.h"
#include "Board.h"
#include "Game.h"
#define HEIGHT 800
#define WIDTH 800
#define PIECE_HEIGHT (HEIGHT/8)
#define PIECE_WIDTH (WIDTH/8)


void draw(Piece pc, sf::RenderWindow &Window){

    sf::RectangleShape piece(sf::Vector2f(PIECE_WIDTH, PIECE_HEIGHT));
    const auto[x,y] = pc.GetPos();


}

int main()
{
    Piece p1(3,3, true);

    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}