#include "Board.h"

std::shared_ptr<Piece> Board::GetPiece() {

    return nullptr;
}

bool Board::PieceAt() {


    return false;
}

void Board::RemovePiece(std::tuple<int> location) {

}

void Board::SetCurrentPiece(std::shared_ptr<Piece> location) {

}

uint Board::CheckForWin() {
    return 0;
}

void Board::Castle() {

}

void Board::UpdateTable() {

}

void Board::SetupBoardPieces() {
    board_table.push_back(std::make_shared<Piece>(1,1,true));
    board_table.push_back(std::make_shared<Piece>(3,3,false));
    board_table.push_back(std::make_shared<Piece>(5,2,false));
    board_table.push_back(std::make_shared<Piece>(4,7,true));

}

uint Board::CheckForCheck() {
    return 0;
}

std::vector<std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    return board_table;
}
