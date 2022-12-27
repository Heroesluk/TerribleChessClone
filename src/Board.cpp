#include "Board.h"
#include <bits/stdc++.h>

std::shared_ptr<Piece> Board::GetPiece(uInt posx, uInt posy) {

    return table[posx + (posy * 8)];
}

bool Board::MakeAction(uInt board_cursorX, uInt board_cursorY) {
    auto ifpc = PieceAt(board_cursorX,board_cursorY);
    if(ifpc){
        auto piece = GetPiece(board_cursorX,board_cursorY);
        SetCurrentPiece(piece);
    }
    else if(currently_held_piece!= nullptr){

    }

}

int Board::PieceAt(uInt posx, uInt posy) {
    //search dictionary for occurrence of a piece at location 0 if not found 1 if found
    auto pc = table.at((posx * 8) + posy);

    if (pc != nullptr) {
        auto piece = GetPiece(posx, posy);
        if (piece->GetColor() == 1) {
            return 1;
        } else if (piece->GetColor() == 0) {
            return 2;
        }

    }

    return 0;

}


void Board::RemovePieceAt(uInt board_index) {
    auto index = pieces_locations[board_index];
    board_table.erase(board_table.begin() + index);
}

void Board::SetCurrentPiece(std::shared_ptr<Piece> location) {
    currently_held_piece = std::move(location);

}

uint Board::CheckForWin() {
    return 0;
}

void Board::Castle() {

}

void Board::UpdateTable() { //called every time a piece move
    //construct a hash lookup table where key is numeric index of board from 0 to 63
    //assigned value is an index of a pieces vector
    pieces_locations.clear();

    for (uInt index = 0; index < board_table.size(); ++index) {
        uInt location = board_table[index]->GetPosIndex();
        pieces_locations[location] = index;
    }

}

void Board::SetupBoardPieces() {
    board_table.push_back(std::make_shared<Piece>(0, 0, true));
    board_table.push_back(std::make_shared<Piece>(1, 0, true));
    board_table.push_back(std::make_shared<Piece>(2, 0, true));
    board_table.push_back(std::make_shared<Piece>(3, 0, true));
    board_table.push_back(std::make_shared<Piece>(4, 0, true));
    board_table.push_back(std::make_shared<Piece>(5, 0, true));
    board_table.push_back(std::make_shared<Piece>(6, 0, true));
    board_table.push_back(std::make_shared<Piece>(7, 0, true));

    board_table.push_back(std::make_shared<Piece>(0, 7, false));
    board_table.push_back(std::make_shared<Piece>(1, 7, false));
    board_table.push_back(std::make_shared<Piece>(2, 7, false));
    board_table.push_back(std::make_shared<Piece>(3, 7, false));
    board_table.push_back(std::make_shared<Piece>(4, 7, false));
    board_table.push_back(std::make_shared<Piece>(5, 7, false));
    board_table.push_back(std::make_shared<Piece>(6, 7, false));
    board_table.push_back(std::make_shared<Piece>(7, 7, false));


    for (int i = 0; i < 64; i++) {
        table.push_back(nullptr);
    }

    for (auto pc: board_table) {
        auto index = pc->GetPosIndex();
        table.at(index) = pc;

    }


    Board::UpdateTable();
    currently_held_piece = nullptr;
}


std::vector<std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    return table;
}

std::vector<int> Board::ReturnPiecesPositions() {
    std::vector<int> positions;
    for (auto pc: table) {
        if (pc == nullptr) {
            positions.push_back(-1);
        } else if (pc->GetColor()) {
            positions.push_back(1);
        } else {
            positions.push_back(0);
        }
    }

    return positions;
}

std::shared_ptr<Piece> Board::GetCurrentlyHeldPiece() {
    return currently_held_piece;
}

//td
bool Board::HoldingPiece() {
    return false;
}

//td
uint Board::CheckForCheck() {
    return 0;
}