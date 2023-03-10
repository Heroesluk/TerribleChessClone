//
// Created by heroesluk on 27.12.22.
//

#include "Pawn.h"
#include "iostream"
#include "algorithm"


Pawn::Pawn(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {

}


std::vector<uInt> Pawn::LegalMoves(std::vector<int> pieces_positions) {

    std::vector<uInt> moves;
    int direction;
    if (color) {
        direction = 1;
    } else {
        direction = -1;
    }

    moves.emplace_back(pos_x + (8 * (pos_y + direction)));
    if(!moved){ //pawn can move 2 blocks if didnt move previously
        moves.emplace_back(pos_x + (8 * (pos_y + (2*direction))));
    }


    return moves;
}




std::vector<uInt> Pawn::LegalTakes(std::vector<int> pieces_positions) {

    int direction;
    if (color) {
        direction = 1;
    } else {
        direction = -1;
    }

    std::vector<uInt> moves;
    if(color!=pieces_positions[pos_x + 1 + ((pos_y + direction) * 8)]){
        moves.emplace_back(pos_x + 1 + ((pos_y + direction) * 8));

    }
    if(color!=pieces_positions[pos_x - 1 + ((pos_y + direction) * 8)]){
        moves.emplace_back(pos_x - 1 + ((pos_y + direction) * 8));

    }


    return moves;
}




