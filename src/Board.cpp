#include "Board.h"
#include <bits/stdc++.h>

#include <utility>

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
        piece_table2.emplace(i, nullptr);
    }

    for (auto pc: pieces) {
        auto index = pc.GetPosIndex();
        piece_table2[index] = std::make_shared<Piece>(pc);

    }

    currently_held_piece = nullptr;
}

bool Board::MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move) {
    //function returns true if it makes any real movement on the board
    //swapping held piece does not count


    auto pc_at_click = GetPiece(board_cursorX, board_cursorY);

    if (pc_at_click != nullptr) {
        if (currently_held_piece == nullptr &&
            pc_at_click->GetColor() == color_to_move) { //set a held piece if not holding anything
            SetCurrentPiece(pc_at_click);
        } else if (currently_held_piece != nullptr) {
            if (pc_at_click->GetColor() ==
                currently_held_piece->GetColor()) { //swap currently held piece if matches held piece
                SetCurrentPiece(pc_at_click);
            } else if (currently_held_piece->GetColor() == color_to_move) { //take an enemy piece, replace with own
                currently_held_piece->Move(board_cursorX, board_cursorY);
                SetCurrentPiece(nullptr);
                RemovePieceAt(board_cursorX, board_cursorY);
                UpdateTable();
                return true;

            }
        }

    } else if (currently_held_piece != nullptr) {
        if (currently_held_piece->GetColor() == color_to_move) { //move piece to empty square
            if (currently_held_piece->CheckIfLegalMove(board_cursorX, board_cursorY)) {
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

void Board::UpdateTable() { //called every time a piece move
    for (int ind = 0; ind < piece_table2.size(); ind++) {
        auto pc = piece_table2[ind];
        if (pc != nullptr) {
            if (pc->GetPosIndex() != ind) {
                piece_table2[pc->GetPosIndex()] = pc;
                piece_table2[ind] = nullptr;
            }

        }

    }

}

std::shared_ptr<Piece> Board::GetPiece(uInt posx, uInt posy) {
    uInt ind = GetPieceIndex(posx, posy);
    auto clicked = piece_table2[ind];

    return clicked;
}

void Board::RemovePieceAt(uInt posx, uInt posy) {
    piece_table2[GetPieceIndex(posx, posy)] = nullptr;
}

void Board::SetCurrentPiece(std::shared_ptr<Piece> location) {
    currently_held_piece = std::move(location);

}

std::vector<int> Board::ReturnPiecesPositions() {
    std::vector<int> positions;
    for (int i = 0; i < 64; i++) {
        if (piece_table2[i] == nullptr) {
            positions.push_back(-1);
        } else if (piece_table2[i]->GetColor()) {
            positions.push_back(1);
        } else {
            positions.push_back(0);
        }
    }

    return positions;
}


int Board::PieceAt(uInt posx, uInt posy) {
    //search dictionary for occurrence of a piece at location 0 if not found 1 if found
    auto pc = piece_table2[GetPieceIndex(posx, posy)];

    if (pc != nullptr) {
        return 1;
    }

    return 0;

}

uint Board::CheckForWin() {
    return 0;
}

void Board::Castle() {

}

std::unordered_map<uInt, std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    return piece_table2;
}

uInt Board::GetPieceIndex(uInt posx, uInt posy) {
    return posx + (8 * posy);
}

