#include "King.h"

King::King(uInt posx, uInt posy, bool color, std::string piece_name) : Piece(posx, posy, color, piece_name) {

}

std::vector<uInt> King::LegalMoves(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;
    std::vector<int> delta_moves = {-1, 1, 8, -8, 9, 7, -8, -9, -7};
    for (auto mv: delta_moves) {
        int move = GetPosIndex() + mv;
        if (move >= 0) {
            if (pieces_positions[move] == -1) {
                moves.emplace_back(mv + GetPosIndex());
            }

        }

    }

    if (LegalCastle(pieces_positions, 'l')) {
        if (color) {
            moves.emplace_back(56);
            moves.emplace_back(63);
        }
        else{
            moves.emplace_back(0);
            moves.emplace_back(7);

        }

    }

    return moves;
}

std::vector<uInt> King::LegalTakes(std::vector<int> pieces_positions) {
    std::vector<uInt> moves;
//    std::vector<int> delta_moves = {-1, 1, 8, -8, 9, 7, -8, -9, -7};
//    for (auto mv: delta_moves) {
//        if (pieces_positions[GetPosIndex() + mv] != color) {
//            moves.emplace_back(mv + GetPosIndex());
//        }
//    }

    return moves;

}

bool King::LegalCastle(std::vector<int> pieces_positions, char direction) {
    if (!moved) {
        if (color) { //for white
            if (pieces_positions[56] == color && pieces_positions[57] == -1 && pieces_positions[58] == -1) {
                return true;
            } else if (pieces_positions[63] == color && pieces_positions[62] == -1
                       && pieces_positions[61] == -1 && pieces_positions[60] == -1) {
                return true;
            }
        } else {
            if (pieces_positions[0] == color && pieces_positions[1] == -1 && pieces_positions[1] == -1) {
                return true;
            } else if (pieces_positions[7] == color && pieces_positions[6] == -1
                       && pieces_positions[5] == -1 && pieces_positions[4] == -1) {
                return true;
            }
        }
    }
    return false;

}

