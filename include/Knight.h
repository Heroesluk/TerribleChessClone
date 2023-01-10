//
// Created by heroesluk on 07.01.23.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Piece.h"

class Knight: public Piece{
public:
    Knight(uInt posx, uInt posy, bool color, std::string piece_name);

    std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) override;
    std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) override;


};

#endif //CHESS_KNIGHT_H
