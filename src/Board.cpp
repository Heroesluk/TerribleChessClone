#include "Board.h"
#include <bits/stdc++.h>

#include <utility>

std::shared_ptr<Piece> Board::GetPiece(uInt posx, uInt posy) {
    auto clicked = piece_table.at(posx + (posy * 8));

    return clicked;
}

bool Board::MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move) {
    //function returns true if it makes any real movement on the board
    //swapping held piece does not count


    auto pc_at_click = GetPiece(board_cursorX, board_cursorY);
    if (pc_at_click != nullptr) {
        if(currently_held_piece==nullptr && pc_at_click->GetColor()==color_to_move){ //set a held piece if not holding anything
            SetCurrentPiece(pc_at_click);
        }
        else if(currently_held_piece != nullptr) {
            if (pc_at_click->GetColor() == currently_held_piece->GetColor()) { //swap currently held piece if matches held piece
                SetCurrentPiece(pc_at_click);
            }
            else if(currently_held_piece->GetColor()==color_to_move){ //take an enemy piece, replace with own
                currently_held_piece->Move(board_cursorX, board_cursorY);
                SetCurrentPiece(nullptr);
                RemovePieceAt(board_cursorX+(board_cursorY*8));
                UpdateTable();
                return true;

            }
        }

    }
    else if (currently_held_piece != nullptr) {
        if(currently_held_piece->GetColor()==color_to_move){ //move piece to empty square
            if(currently_held_piece->CheckIfLegalMove(std::make_tuple(board_cursorX,board_cursorY))){
                currently_held_piece->Move(board_cursorX, board_cursorY);
                SetCurrentPiece(nullptr);
                UpdateTable();
                return true;
            }
        }
    }


    UpdateTable();
    return false;

}

int Board::PieceAt(uInt posx, uInt posy) {
    //search dictionary for occurrence of a piece at location 0 if not found 1 if found
    auto pc = piece_table.at((posy * 8) + posx);

    if (pc != nullptr) {
        return 1;
    }

    return 0;

}


void Board::RemovePieceAt(uInt board_index) {
    piece_table.at(board_index) = nullptr;
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
    for (int ind = 0; ind < piece_table.size(); ind++) {
        auto pc = piece_table.at(ind);
        if (pc != nullptr) {
            if (pc->GetPosIndex() != ind) {
                piece_table[pc->GetPosIndex()] = pc;
                piece_table[ind] = nullptr;
            }

        }

    }

}

void Board::SetupBoardPieces() {

    pieces.emplace_back(Piece(0, 0, true));
    pieces.emplace_back(Piece(1, 0, true));
    pieces.emplace_back(Piece(2, 0, true));
    pieces.emplace_back(Piece(3, 0, true));
    pieces.emplace_back(Piece(4, 0, true));
    pieces.emplace_back(Piece(5, 0, true));
    pieces.emplace_back(Piece(6, 0, true));
    pieces.emplace_back(Piece(7, 0, true));
    pieces.emplace_back(Piece(0, 7, false));
    pieces.emplace_back(Piece(1, 7, false));
    pieces.emplace_back(Piece(2, 7, false));
    pieces.emplace_back(Piece(3, 7, false));
    pieces.emplace_back(Piece(4, 7, false));
    pieces.emplace_back(Piece(5, 7, false));
    pieces.emplace_back(Piece(6, 7, false));
    pieces.emplace_back(Piece(7, 7, false));


    for (int i = 0; i < 64; i++) {
        piece_table.push_back(nullptr);
    }

    for (auto pc: pieces) {
        auto index = pc.GetPosIndex();
        piece_table.at(index) = std::make_shared<Piece>(pc);
    }

    currently_held_piece = nullptr;
}


std::vector<std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    return piece_table;
}

std::vector<int> Board::ReturnPiecesPositions() {
    std::vector<int> positions;
    for (auto pc: piece_table) {
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