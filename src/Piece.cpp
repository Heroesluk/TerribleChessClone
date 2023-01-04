//
// Created boardY heroesluk on 17.12.22.
//

#include "Piece.h"
#include "algorithm"

Piece::Piece(uInt pos_x, uInt pos_y, bool color): pos_x{pos_x}, pos_y{pos_y}, color{color} {}

std::vector<uInt> Piece::LegalMoves() {
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

bool Piece::CheckIfLegalMove(uInt posx, uInt posy){
    auto moves = LegalMoves();

    for(auto move_index: moves){
        if(move_index==posx+(posy*8)){


            return true;
        }
    }

    return false;


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

