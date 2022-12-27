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
    bool moved;

public:
    std::shared_ptr<Piece> GetPiece(uInt posx, uInt posy);

    bool MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move);

    int PieceAt(uInt posx, uInt posy);

    void RemovePieceAt(uInt board_index);

    void SetCurrentPiece(std::shared_ptr<Piece> location);

    bool HoldingPiece();

    std::shared_ptr<Piece> GetCurrentlyHeldPiece();

    uInt CheckForWin();

    void Castle();

    void UpdateTable();

    std::vector<std::shared_ptr<Piece>> ReturnAllPieces();

    void SetupBoardPieces();

    uInt CheckForCheck();

    std::vector<int> ReturnPiecesPositions();

};

#endif //CHESS_BOARD_H
