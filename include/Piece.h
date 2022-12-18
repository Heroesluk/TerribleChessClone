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
    Piece(uInt pos_x, uInt pos_y, bool color);

    std::vector<std::tuple<int,int>> LegalMoves();
    std::vector<std::tuple<int,int>> LegalTakes();
    void Move();

    std::tuple<int,int> GetPos();

};

#endif //INC_Chess_PIECE_H
