//
// Created boardY heroesluk on 17.12.22.
//

#include "Piece.h"
#include "algorithm"

Piece::Piece(uInt pos_x, uInt pos_y, bool color): pos_x{pos_x}, pos_y{pos_y}, color{color} {}

//std::vector<uInt> Piece::LegalMoves() {};


bool Piece::GetColor(){
    return color;
}



uInt Piece::GetPosIndex() {
    return pos_x+(8*pos_y);
}


