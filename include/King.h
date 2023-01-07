//
// Created by heroesluk on 07.01.23.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Piece.h"

class King: public Piece{
public:
    King(uInt posx, uInt posy, bool color);

    std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) override;
    std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) override;

};

#endif //CHESS_KING_H
