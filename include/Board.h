#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "unordered_map"
#include "memory"
#include "Piece.h"
#include "tuple"


using uInt = unsigned int;


class Board {
private:
    std::shared_ptr<Piece> currently_held_piece;

    std::unordered_map<uInt,std::shared_ptr<Piece>> piece_table2;

    bool moved;

    int PieceAt(uInt posx, uInt posy);
    void RemovePieceAt(uInt posx, uInt posy);
    void SetCurrentPiece(std::shared_ptr<Piece> cur_piece);
    void UpdateTable();
    uInt CheckForWin();
    void Castle();
    uInt CheckForCheck();


public:
    const std::unordered_map<uInt,std::shared_ptr<Piece>> ReturnAllPieces();

    //move this to private once debugged
    uInt GetPieceIndex(uInt posx, uInt posy);
    std::shared_ptr<Piece> GetPiece(uInt posx, uInt posy);
    //

    bool CheckIfLegalMove(uInt moveX, uInt moveY);
    bool CheckIfLegalTake(uInt takeX, uInt takeY);


    void SetupBoardPieces();
    bool MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move);
    std::vector<int> ReturnPiecesPositions();



};

#endif //CHESS_BOARD_H
