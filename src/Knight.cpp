//
// Created by heroesluk on 07.01.23.
//
#include "Knight.h"

Knight::Knight(uInt posx, uInt posy, bool color, std::string piece_name) :  Piece(posx, posy, color, piece_name) {

}

std::vector<uInt> Knight::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;


    return LegalTakes(pieces_positions);

}

std::vector<uInt> Knight::LegalTakes(std::vector<int> pieces_positions) {

    std::vector<uInt> moves;

    moves.emplace_back(pos_x+1+(8*(pos_y+2)));
    moves.emplace_back(pos_x-1+(8*(pos_y+2)));
    moves.emplace_back(pos_x+1+(8*(pos_y-2)));
    moves.emplace_back(pos_x-1+(8*(pos_y-2)));

    moves.emplace_back(pos_x+2+(8*(pos_y-1)));
    moves.emplace_back(pos_x-2+(8*(pos_y-1)));
    moves.emplace_back(pos_x+2+(8*(pos_y+1)));
    moves.emplace_back(pos_x-2+(8*(pos_y+1)));

    return moves;
}

