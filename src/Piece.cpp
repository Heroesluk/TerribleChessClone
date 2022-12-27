//
// Created boardY heroesluk on 17.12.22.
//

#include "Piece.h"
#include "algorithm"

Piece::Piece(uInt pos_x, uInt pos_y, bool color) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->color = color;
}

std::vector<std::tuple<int, int>> Piece::LegalMoves() {
    int direction;
    if(color){
        direction = 1;
    } else{
        direction = -1;
    }

    std::vector<std::tuple<int,int>> moves;
    moves.emplace_back(pos_x, pos_y+(direction));

    return moves;
}

bool Piece::CheckIfLegalMove(std::tuple<int,int> move){
    auto moves = Piece::LegalMoves();
    return std::find(moves.begin(), moves.end(),move)!=moves.end();

}


std::vector<std::tuple<int, int>> Piece::LegalTakes() {

    int direction;
    if(color){
        direction = 1;
    } else{
        direction = -1;
    }

    std::vector<std::tuple<int,int>> moves;
    moves.emplace_back(pos_x+1, pos_y+(direction));
    moves.emplace_back(pos_x-1, pos_y+(direction));


    return moves;
}

bool Piece::GetColor(){
    return color;
}

void Piece::Move(uInt posx, uInt posy) {
    pos_x = posx;
    pos_y = posy;
}

uInt Piece::GetPosIndex() {
    return pos_x+(8*pos_y);
}

