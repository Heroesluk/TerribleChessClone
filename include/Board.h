//
// Created by heroesluk on 17.12.22.
//


#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "unordered_map"
#include "memory"
#include "Piece.h"
#include "tuple"



using uInt = unsigned int;


class Board{
private:
    std::vector<std::shared_ptr<Piece>> board_table;
    std::shared_ptr<Piece> currently_held_piece;
public:
    std::shared_ptr<Piece> GetPiece();
    bool PieceAt();
    void RemovePiece(std::tuple<int> location);
    void SetCurrentPiece(std::shared_ptr<Piece> location);
    uInt CheckForWin();
    void Castle();
    void UpdateTable();
    std::vector<std::shared_ptr<Piece>> ReturnAllPieces();
    void SetupBoardPieces();
    uInt CheckForCheck();

};

#endif //CHESS_BOARD_H
