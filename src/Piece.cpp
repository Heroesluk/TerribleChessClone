//
// Created by heroesluk on 17.12.22.
//

#include "Piece.h"

Piece::Piece(uInt pos_x, uInt pos_y, bool color) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->color = color;
}

std::vector<std::tuple<int, int>> Piece::LegalMoves() {
    std::vector<std::tuple<int,int>> moves;
    for(auto i=0; i<3;i++){
        moves.emplace_back(i,i);
    }

    return moves;
}

std::vector<std::tuple<int, int>> Piece::LegalTakes() {
    std::vector<std::tuple<int,int>> moves;
    for(auto i=0; i<3;i++){
        moves.emplace_back(pos_x,pos_y);
    }

    return moves;
}




std::tuple<int,int> Piece::GetPos() {
    return std::make_tuple(pos_x,pos_y);
}

bool Piece::GetColor(){
    return this->color;
}

void Piece::Move(uInt pos_x, uInt pos_y) {

}
