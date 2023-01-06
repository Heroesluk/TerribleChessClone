//
// Created boardY heroesluk on 17.12.22.
//

#ifndef INC_Chess_PIECE_H
#define INC_Chess_PIECE_H

#include "tuple"
#include "vector"

using uInt = unsigned int;


class Piece {
protected:
    bool color;
    uInt pos_x;
    uInt pos_y;
    std::vector<uInt> legal_moves;

public:
    Piece(uInt pos_x, uInt pos_y, bool color);

    virtual std::vector<uInt> LegalMoves()=0;

    bool CheckIfLegalMove(uInt moveX, uInt moveY);

    virtual std::vector<int> LegalTakes() = 0;

    bool CheckIfLegalTake(uInt takeX, uInt takeY);

    virtual void Move(uInt pos_x, uInt pos_y) = 0;

    bool GetColor();

    uInt GetPosIndex();

};

#endif //INC_Chess_PIECE_H
