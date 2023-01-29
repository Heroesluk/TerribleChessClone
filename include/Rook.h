//
// Created by heroesluk on 06.01.23.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"
using uInt = unsigned int;


class Rook: public Piece{
public:
    Rook(uInt posx, uInt posy, bool color, std::string piece_name);

    bool moved;

    std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) override;
    std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) override;



};



#endif //CHESS_ROOK_H
