//
// Created boardY heroesluk on 17.12.22.
//

#include "Piece.h"
#include "algorithm"

Piece::Piece(uInt pos_x, uInt pos_y, bool color): pos_x{pos_x}, pos_y{pos_y}, color{color} {}

//std::vector<uInt> Piece::LegalMoves() {};





bool Piece::CheckIfLegalTake(uInt takeX, uInt takeY) {
    auto legal_takes = LegalTakes();

    for(auto take_index: legal_takes){
        if(take_index==takeX+(takeY*8)){

            return true;
        }
    }

    return false;

}


bool Piece::GetColor(){
    return color;
}



uInt Piece::GetPosIndex() {
    return pos_x+(8*pos_y);
}

bool Piece::CheckIfLegalMove(uInt moveX, uInt moveY) {

    auto moves = legal_moves;

    for (auto move_index: moves) {
        if (move_index == moveX + (moveY * 8)) {
            return true;
        }
    }


    return false;

}

