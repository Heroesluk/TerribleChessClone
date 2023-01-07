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

    std::vector<uInt> legal_moves;

public:
    uInt pos_x;
    uInt pos_y;

    Piece(uInt pos_x, uInt pos_y, bool color);

    void UpdateLegalMoves();

    virtual std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) =0;

    bool CheckIfLegalMove(uInt moveX, uInt moveY);

    virtual std::vector<int> LegalTakes() = 0;

    bool CheckIfLegalTake(uInt takeX, uInt takeY);

    virtual void Move(uInt pos_x, uInt pos_y) = 0;

    bool GetColor();

    uInt GetPosIndex();

};

#endif //INC_Chess_PIECE_H
