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
    uInt board_index;
public:
    Piece(uInt pos_x, uInt pos_y, bool color);

    std::vector<uInt> LegalMoves();
    bool CheckIfLegalMove(uInt posx, uInt posy);

    std::vector<std::tuple<int, int>> LegalTakes();
    bool CheckIfLegalTake();

    void Move(uInt pos_x, uInt pos_y);
    bool GetColor();
    uInt GetPosIndex();

};

#endif //INC_Chess_PIECE_H
