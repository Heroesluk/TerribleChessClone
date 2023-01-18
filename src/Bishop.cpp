//
// Created by heroesluk on 07.01.23.
//
#include "Bishop.h"

Bishop::Bishop(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {
}

std::vector<uInt> Bishop::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;


    uInt x = pos_x;
    uInt y = pos_y;

    //from left top corner
    while (x < 7 && y < 7) {
        x++;
        y++;
        if (pieces_positions[x + (y * 8)]!=-1){
            break;
        }
        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y > 0) {
        x--;
        y--;
        if (pieces_positions[x + (y * 8)]!=-1){
            break;
        }

        moves.emplace_back(x + (y * 8));
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y < 7) {
        x--;
        y++;
        if (pieces_positions[x + (y * 8)]!=-1){
            break;
        }

        moves.emplace_back(x + (y * 8));
    }

    x = pos_x;
    y = pos_y;
    while (x < 7 && y > 0) {
        x++;
        y--;
        if (pieces_positions[x + (y * 8)]!=-1){
            break;
        }

        moves.emplace_back(x + (y * 8));
    }


    return moves;


}


//null -> add and next
//own -> break
//enemy -> add and break

std::vector<uInt> Bishop::LegalTakes(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;


    uInt x = pos_x;
    uInt y = pos_y;

    while (x < 7 && y < 7) {
        x++;
        y++;

        if (pieces_positions[x + (y * 8)]==color){
            break;
        }
        else if(pieces_positions[x + (y * 8)]==-1){
            moves.emplace_back(x + (y * 8));

        }
        else{
            moves.emplace_back(x + (y * 8));
            break;

        }

    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y > 0) {
        x--;
        y--;
        if (pieces_positions[x + (y * 8)]==color){
            break;
        }
        else if(pieces_positions[x + (y * 8)]==-1){
            moves.emplace_back(x + (y * 8));

        }
        else{
            moves.emplace_back(x + (y * 8));
            break;

        }
    }


    x = pos_x;
    y = pos_y;
    while (x > 0 && y < 7) {
        x--;
        y++;
        if (pieces_positions[x + (y * 8)]==color){
            break;
        }
        else if(pieces_positions[x + (y * 8)]==-1){
            moves.emplace_back(x + (y * 8));

        }
        else{
            moves.emplace_back(x + (y * 8));
            break;

        }
    }


    x = pos_x;
    y = pos_y;
    while (x < 7 && y > 0) {
        x++;
        y--;
        if (pieces_positions[x + (y * 8)]==color){
            break;
        }
        else if(pieces_positions[x + (y * 8)]==-1){
            moves.emplace_back(x + (y * 8));

        }
        else{
            moves.emplace_back(x + (y * 8));
            break;

        }
    }


    return moves;
}

