//
// Created by heroesluk on 27.12.22.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

using uInt = unsigned int;


class Pawn : public Piece {
public:

    Pawn(uInt posx, uInt posy, bool color);


    std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) override;
    std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) override;
//    bool CheckIfLegalMove(uInt moveX, uInt moveY) override;


};

#endif //CHESS_PAWN_H
