//
// Created by heroesluk on 06.01.23.
//
#include "Rook.h"

Rook::Rook(uInt posx, uInt posy, bool color) : Piece(posx, posy, color) {
    legal_moves = Rook::LegalMoves(std::vector<int>());
}

std::vector<uInt> Rook::LegalMoves(std::vector<int> pieces_positions) {
    int direction;
    if(color){
        direction = 1;
    } else{
        direction = -1;
    }

    std::vector<uInt> moves;
    moves.emplace_back(pos_x+(8*(pos_y+direction)));

    return moves;


}

std::vector<int> Rook::LegalTakes() {
    int direction;
    if(color){
        direction = 1;
    } else{
        direction = -1;
    }

    std::vector<int> moves;
    moves.emplace_back(pos_x + ((pos_y+direction)*8));


    return moves;
}

void Rook::Move(uInt posX, uInt posY) {
    pos_x = posX;
    pos_y = posY;
    legal_moves = Rook::LegalMoves(std::vector<int>());
}

