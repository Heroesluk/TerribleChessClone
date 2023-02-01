//
// Created by heroesluk on 07.01.23.
//
#include "Knight.h"

Knight::Knight(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {

}

std::vector<uInt> Knight::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;

    return LegalTakes(pieces_positions);

}

std::vector<uInt> Knight::LegalTakes(std::vector<int> pieces_positions) {

    std::vector<uInt> moves;
    std::vector<int> deltax = {1, -1, 1, -1, 2, -2, 2, -2};
    std::vector<int> deltay = {2, 2, -2, -2, -1, -1, 1, 1};

    for(int i=0; i<deltax.size(); i++){
        if(pos_x+deltax[i]>=0 && pos_y+deltay[i]>=0 && pos_x+deltax[i]<=7 && pos_y+deltay[i]<=7)
            if(color!=pieces_positions[pos_x+deltax[i]+((pos_y+deltay[i])*8)]){
                moves.emplace_back(pos_x+deltax[i] + (8*(pos_y+deltay[i])));
            }
    }


    return moves;
}

