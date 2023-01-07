#include "Board.h"
#include <bits/stdc++.h>

#include <utility>
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
void Board::SetupBoardPieces() {



    piece_table2[0] = std::make_shared<Rook>(0, 0, true);
    piece_table2[1] = std::make_shared<Knight>(1, 0, true);
    piece_table2[2] = std::make_shared<Bishop>(2, 0, true);
    piece_table2[3] = std::make_shared<Pawn>(3, 0, true);
    piece_table2[4] = std::make_shared<Queen>(4, 0, true);
    piece_table2[5] = std::make_shared<Bishop>(5, 0, true);
    piece_table2[6] = std::make_shared<Knight>(6, 0, true);
    piece_table2[7] = std::make_shared<Rook>(7, 0, true);
    piece_table2[56] = std::make_shared<Rook>(0, 7, false);
    piece_table2[57] = std::make_shared<Knight>(1, 7, false);
    piece_table2[58] = std::make_shared<Bishop>(2, 7, false);
    piece_table2[59] = std::make_shared<Pawn>(3, 7, false);
    piece_table2[60] = std::make_shared<Queen>(4, 7, false);
    piece_table2[61] = std::make_shared<Bishop>(5, 7, false);
    piece_table2[62] = std::make_shared<Knight>(6, 7, false);
    piece_table2[63] = std::make_shared<Rook>(7, 7, false);

    for (int i = 0; i < 64; i++) {
        piece_table2.emplace(i, nullptr);
    }


    currently_held_piece = nullptr;
}

bool Board::MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move) {
    //function returns true if it makes any real movement on the board
    //swapping held piece does not count
    bool made_move = false;


    auto pc_at_click = GetPiece(board_cursorX, board_cursorY);

    if (pc_at_click != nullptr) {
        if (currently_held_piece == nullptr && pc_at_click->GetColor() == color_to_move) { //set a held piece if not holding anything
            SetCurrentPiece(pc_at_click);
        } else if (currently_held_piece != nullptr) {
            if (pc_at_click->GetColor() ==
                currently_held_piece->GetColor()) { //swap currently held piece if matches held piece
                SetCurrentPiece(pc_at_click);
            } else if (currently_held_piece->GetColor() == color_to_move) { //take an enemy piece, replace with own
                if (CheckIfLegalTake(board_cursorX, board_cursorY)) {
                    currently_held_piece->Move(board_cursorX, board_cursorY);
                    SetCurrentPiece(nullptr);
                    RemovePieceAt(board_cursorX, board_cursorY);
                    made_move =  true;


                }

            }
        }

    } else if (currently_held_piece != nullptr) {
        if (currently_held_piece->GetColor() == color_to_move) { //move piece to empty square
            if (CheckIfLegalMove(board_cursorX, board_cursorY)) {
                currently_held_piece->Move(board_cursorX, board_cursorY);
                SetCurrentPiece(nullptr);
                made_move = true;
            }
        }
    }


    UpdateTable();
    return made_move;

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

const std::unordered_map<uInt, std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    return piece_table2;
}

uInt Board::GetPieceIndex(uInt posx, uInt posy) {
    return posx + (8 * posy);
}

bool Board::CheckIfLegalMove(uInt moveX, uInt moveY){
    auto moves = currently_held_piece->LegalMoves(ReturnPiecesPositions());

    for (auto move_index: moves) {
        if (move_index == moveX + (moveY * 8)) {
            return true;
        }
    }


    return false;


}


bool Board::CheckIfLegalTake(uInt takeX, uInt takeY) {

    auto takes = currently_held_piece->LegalTakes(ReturnPiecesPositions());

    for (auto take_index: takes) {
        if (take_index == takeX + (takeY * 8)) {

            return true;
        }
    }

    return false;

}