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


template<class TupType, size_t... I>
void print(const TupType& _tup, std::index_sequence<I...>)
{
    std::cout << "(";
    (..., (std::cout << (I == 0? "" : ", ") << std::get<I>(_tup)));
    std::cout << ")\n";
}

template<class... T>
void print (const std::tuple<T...>& _tup)
{
    print(_tup, std::make_index_sequence<sizeof...(T)>());
}

int main() {

    Game game;

    game.GameLoop();



    return 0;
}