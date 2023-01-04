#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "unordered_map"
#include "memory"
#include "Piece.h"
#include "tuple"


using uInt = unsigned int;


class Board {
private:
    std::vector<Piece> pieces;
    std::shared_ptr<Piece> currently_held_piece;
    std::vector<std::shared_ptr<Piece>>piece_table;

    std::unordered_map<uInt,std::shared_ptr<Piece>> piece_table2;

    bool moved;

public:
    uInt GetPieceIndex(uInt posx, uInt posy);

    std::shared_ptr<Piece> GetPiece(uInt posx, uInt posy);

    bool MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move);

    int PieceAt(uInt posx, uInt posy);

    void RemovePieceAt(uInt posx, uInt posy);

    void SetCurrentPiece(std::shared_ptr<Piece> cur_piece);

    void UpdateTable();

    void SetupBoardPieces();

    std::vector<int> ReturnPiecesPositions();

    uInt CheckForWin();
    void Castle();
    std::unordered_map<uInt,std::shared_ptr<Piece>> ReturnAllPieces();
    uInt CheckForCheck();

};

#endif //CHESS_BOARD_H
