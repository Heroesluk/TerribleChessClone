//
// Created by heroesluk on 07.01.23.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Piece.h"
class Bishop: public Piece{
public:

    Bishop(uInt posx, uInt posy, bool color);

    std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) override;
    std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) override;


};

#endif //CHESS_BISHOP_H
