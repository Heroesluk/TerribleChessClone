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


std::vector<int> Piece::LegalTakes() {

    int direction;
    if(color){
        direction = 1;
    } else{
        direction = -1;
    }

    std::vector<int> moves;
    moves.emplace_back(pos_x+1 + ((pos_y+direction)*8));
    moves.emplace_back(pos_x-1 + ((pos_y+direction)*8));


    return moves;
}

bool Piece::CheckIfLegalTake(uInt takeX, uInt takeY) {
    auto legal_takes = LegalTakes();

    for(auto take_index: legal_takes){
        if(take_index==takeX+(takeY*8)){

            return true;
        }
    }

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

