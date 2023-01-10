//
// Created by heroesluk on 07.01.23.
//
#include "Queen.h"

Queen::Queen(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {

}

std::vector<uInt> Queen::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;

    {
    uInt x = pos_x;
    uInt y = pos_y;

    while (x < 7 && y < 7) {
        x++;
        y++;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y > 0) {
        x--;
        y--;
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y < 7) {
        x--;
        y++;
        moves.emplace_back(x + (y * 8));
    }

    x = pos_x;
    y = pos_y;
    while (x < 7 && y > 0) {
        x++;
        y--;
        moves.emplace_back(x + (y * 8));
    }
    }


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

std::vector<uInt> Queen::LegalTakes(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;

    {
        int x = pos_x;
        int y = pos_y;

        while (x < 7 && y < 7) {
            x++;
            y++;
            moves.emplace_back(x + (y * 8));
        }

    };
    {
        int x = pos_x;
        int y = pos_y;
        while (x > 0 && y > 0) {
            x--;
            y--;
            moves.emplace_back(x + (y * 8));
        }

    };
    {
        int x = pos_x;
        int y = pos_y;
        while (x > 0 && y < 7) {
            x--;
            y++;
            moves.emplace_back(x + (y * 8));
        }

    };
    {
        int x = pos_x;
        int y = pos_y;
        while (x < 7 && y > 0) {
            x++;
            y--;
            moves.emplace_back(x + (y * 8));
        }

    }

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

