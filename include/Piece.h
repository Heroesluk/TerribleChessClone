//
// Created boardY heroesluk on 17.12.22.
//

#ifndef INC_Chess_PIECE_H
#define INC_Chess_PIECE_H

#include "tuple"
#include "vector"

using uInt = unsigned int;


class Piece {
private:
    std::string piece_name;
protected:
    bool color;

public:
    uInt pos_x;
    uInt pos_y;




    Piece(uInt pos_x, uInt pos_y, bool color, std::string piece_name);

    virtual std::vector<uInt> LegalMoves(std::vector<int> pieces_positions) =0;

    virtual std::vector<uInt> LegalTakes(std::vector<int> pieces_positions) = 0;

    void Move(uInt pos_x, uInt pos_y);

    bool GetColor();

    uInt GetPosIndex();

    std::string GetPieceName();

};

#endif //INC_Chess_PIECE_H
