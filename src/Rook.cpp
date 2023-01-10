//
// Created by heroesluk on 06.01.23.
//
#include "Rook.h"

Rook::Rook(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {
    }

std::vector<uInt> Rook::LegalMoves(std::vector<int> pieces_positions) {


    std::vector<uInt> moves;

    for (int y = (int) pos_y; y < 8; y++) {
        if(pieces_positions[pos_x + (8*y)]!=-1 && pos_y!=y){
            break;
        }
        else(moves.emplace_back(pos_x + (8 * (y))));
    }

    for (int y = (int) pos_y; y >= 0; y--) {
        if(pieces_positions[pos_x + (8*y)]!=-1 && pos_y!=y){
            break;
        }
        moves.emplace_back(pos_x + (8 * (y)));
    }

    for (int x = (int) pos_x; x < 8; x++) {
        if(pieces_positions[x + (8*pos_y)]!=-1 && pos_x!=x){
            break;
        }
        else(moves.emplace_back(x + (8 * (pos_y))));
    }

    for (int x = (int) pos_x; x >= 0; x--) {
        if(pieces_positions[x + (8*pos_y)]!=-1 && pos_x!=x){
            break;
        }
        moves.emplace_back(x + (8 * (pos_y)));
    }

    return moves;

}

std::vector<uInt> Rook::LegalTakes(std::vector<int> pieces_positions) {


    //color = pieces_positions[pos_x+(8*pos_y)];

    std::vector<uInt> moves;


    for (int y = (int) pos_y; y < 8; y++) {
        if(pieces_positions[pos_x + (8*y)]!=-1){
            if(pieces_positions[pos_x+(8*y)]!=color){
                moves.emplace_back(pos_x + (8 * (y)));
                break;
            }
        }
    }

    for (int y = (int) pos_y; y >= 0; y--) {
        if(pieces_positions[pos_x + (8*y)]!=-1){
            if(pieces_positions[pos_x+(8*y)]!=color){
                moves.emplace_back(pos_x + (8 * (y)));
                break;
            }
        }
    }

    for (int x = (int) pos_x; x < 8; x++) {
        if(pieces_positions[x + (8*pos_y)]!=-1){
            if(pieces_positions[x+(8*pos_y)]!=color){
                moves.emplace_back(x + (8 * (pos_y)));
                break;
            }
        }
    }

    for (int x = (int) pos_x; x>=0; x--) {
        if(pieces_positions[x + (8*pos_y)]!=-1){
            if(pieces_positions[x+(8*pos_y)]!=color){
                moves.emplace_back(x + (8 * (pos_y)));
                break;
            }
        }
    }


    return moves;
}



