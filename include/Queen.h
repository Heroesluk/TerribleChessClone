//
// Created by heroesluk on 07.01.23.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Piece.h"

class Queen: public Piece{
public:
    Queen(uInt posx, uInt posy, bool color, std::string piece_name);

    std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) override;
    std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) override;


};

#endif //CHESS_QUEEN_H
