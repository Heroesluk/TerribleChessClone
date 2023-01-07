#include "King.h"

King::King(uInt posx, uInt posy, bool color) : Piece(posx, posy, color) {

}

std::vector<uInt> King::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;
    std::vector<int> delta_moves = {-1, 1, 8, -8, 9, 7, -8, -9, -7};
    for(auto mv: delta_moves){
        int move = GetPosIndex()+mv;
        if(move>=0){
            if(pieces_positions[move]==-1){
                moves.emplace_back(mv+GetPosIndex());
            }

        }

    }

    return moves;
}

std::vector<uInt> King::LegalTakes(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;
    std::vector<int> delta_moves = {-1, 1, 8, -8, 9, 7, -8, -9, -7};
    for(auto mv: delta_moves){
        if(pieces_positions[GetPosIndex()+mv]!=color){
            moves.emplace_back(mv+GetPosIndex());
        }
    }

    return moves;

}

