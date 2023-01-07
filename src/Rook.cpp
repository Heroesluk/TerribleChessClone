//
// Created by heroesluk on 06.01.23.
//
#include "Rook.h"

Rook::Rook(uInt posx, uInt posy, bool color) : Piece(posx, posy, color) {
    std::vector<int> default_moves = {1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1,
                                      -1, -1, -1, -1, -1, -1, -1, -1,
                                      -1, -1, -1, -1, -1, -1, -1, -1,
                                      -1, -1, -1, -1, -1, -1, -1, -1,
                                      -1, -1, -1, -1, -1, -1, -1, -1,
                                      -1, -1, -1, -1, -1, -1, -1, -1,
                                      0, 0, 0, 0, 0, 0, 0, 0};
}

std::vector<uInt> Rook::LegalMoves(std::vector<int> pieces_positions) {

    //0 -> 1 -> 2 -> 3
    // 3 -> 4 -> 5 -> 6
    // 3 -> 2 -> 1 -> 0

    std::vector<uInt> moves;

    for (int y = pos_y; y < 8; y++) {
        if(pieces_positions[pos_x + (8*y)]!=-1 && pos_y!=y){
            break;
        }
        else(moves.emplace_back(pos_x + (8 * (y))));
    }

    for (int y = pos_y; y >= 0; y--) {
        if(pieces_positions[pos_x + (8*y)]!=-1 && pos_y!=y){
            break;
        }
        moves.emplace_back(pos_x + (8 * (y)));
    }

    for (int x = pos_x; x < 8; x++) {
        if(pieces_positions[x + (8*pos_y)]!=-1 && pos_x!=x){
            break;
        }
        else(moves.emplace_back(x + (8 * (pos_y))));
    }

    for (int x = pos_x; x >= 0; x--) {
        if(pieces_positions[x + (8*pos_y)]!=-1 && pos_x!=x){
            break;
        }
        moves.emplace_back(x + (8 * (pos_y)));
    }

    return moves;

}

std::vector<uInt> Rook::LegalTakes(std::vector<int> pieces_positions) {


    color = pieces_positions[pos_x+(8*pos_y)];

    std::vector<uInt> moves;


    for (int y = pos_y; y < 8; y++) {
        if(pieces_positions[pos_x + (8*y)]!=-1){
            if(pieces_positions[pos_x+(8*y)]!=color){
                moves.emplace_back(pos_x + (8 * (y)));
                break;
            }
        }
    }

    for (int y = pos_y; y >= 0; y--) {
        if(pieces_positions[pos_x + (8*y)]!=-1){
            if(pieces_positions[pos_x+(8*y)]!=color){
                moves.emplace_back(pos_x + (8 * (y)));
                break;
            }
        }
    }

    for (int x = pos_x; x < 8; x++) {
        if(pieces_positions[x + (8*pos_y)]!=-1){
            if(pieces_positions[x+(8*pos_y)]!=color){
                moves.emplace_back(x + (8 * (pos_y)));
                break;
            }
        }
    }

    for (int x = pos_x; x>=0; x--) {
        if(pieces_positions[x + (8*pos_y)]!=-1){
            if(pieces_positions[x+(8*pos_y)]!=color){
                moves.emplace_back(x + (8 * (pos_y)));
                break;
            }
        }
    }


    return moves;
}

void Rook::Move(uInt posX, uInt posY) {
    pos_x = posX;
    pos_y = posY;
}

