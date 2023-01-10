//
// Created by heroesluk on 07.01.23.
//
#include "Bishop.h"

Bishop::Bishop(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {
}

std::vector<uInt> Bishop::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;


    uInt x = pos_x;
    uInt y = pos_y;

    while (x < 7 && y < 7) {
        x++;
        y++;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y > 0) {
        x--;
        y--;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y < 7) {
        x--;
        y++;
        moves.emplace_back(x + (y * 8));
    }

    x = pos_x;
    y = pos_y;
    while (x < 7 && y > 0) {
        x++;
        y--;
        moves.emplace_back(x + (y * 8));
    }


    return moves;


}

std::vector<uInt> Bishop::LegalTakes(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;


    uInt x = pos_x;
    uInt y = pos_y;

    while (x < 7 && y < 7) {
        x++;
        y++;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y > 0) {
        x--;
        y--;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y < 7) {
        x--;
        y++;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x < 7 && y > 0) {
        x++;
        y--;
        moves.emplace_back(x + (y * 8));
    }


    return moves;
}

