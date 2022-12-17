//
// Created by heroesluk on 17.12.22.
//

#ifndef INC_Chess_PIECE_H
#define INC_Chess_PIECE_H

#include "tuple"
#include "vector"

using uInt = unsigned int;


class Piece{
private:
    bool color;
    uInt pos_x;
    uInt pos_y;
public:
    Piece();

    std::vector<std::tuple<>> LegalMoves();
    std::vector<std::tuple<>> LegalTakes();
    void Move();

};

#endif //INC_Chess_PIECE_H
