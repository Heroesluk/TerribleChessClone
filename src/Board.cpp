#include "Board.h"
#include <bits/stdc++.h>
std::shared_ptr<Piece> Board::GetPiece(uInt posx, uInt posy) {

    auto index = pieces_locations[(posx * 8) + posy];
    return board_table[index];
}

bool Board::MakeAction(uInt board_cursorX, uInt board_cursorY) {
    int type_at_cursor = PieceAt(board_cursorX, board_cursorY); //0 -> no piece, 1 -> whitep, 2 -> blackp
    auto held_piece = GetCurrentlyHeldPiece(); //nullptr if no piece held_piece

    if (type_at_cursor == 0) { //if piece not found at x,y
        if (held_piece != nullptr) {
            for (auto mv: held_piece->LegalMoves()) {
                if (mv == std::make_tuple(board_cursorX, board_cursorY)) {
                    held_piece->Move(board_cursorX, board_cursorY);
                    //auto takes = held_piece->LegalTakes();
                    SetCurrentPiece(nullptr);
                }
            }

        };
        //if we don't hold any piece AND we click empty space, nothing happens

    }

    else if (type_at_cursor == 1) { //if white piece found
        auto piece_at_click = GetPiece(board_cursorX,board_cursorY);

        if (held_piece == nullptr) {
            SetCurrentPiece(piece_at_click);
        }

        else{
            for (auto mv: held_piece->LegalTakes()) {
                if (mv == std::make_tuple(board_cursorX, board_cursorY)) {
                    RemovePieceAt(piece_at_click->GetPosIndex());
                    held_piece->Move(board_cursorX, board_cursorY);
                    SetCurrentPiece(nullptr);
                }
            }
        }


    }


    else if (type_at_cursor == 2) { //if black piece found
        auto piece_at_click = GetPiece(board_cursorX,board_cursorY);

        if (held_piece == nullptr) {
            held_piece = GetPiece(board_cursorX, board_cursorY);
            SetCurrentPiece(held_piece);
        }

        else{
            for (auto mv: held_piece->LegalTakes()) {
                if (mv == std::make_tuple(board_cursorX, board_cursorY)) {
                    RemovePieceAt(piece_at_click->GetPosIndex());
                    held_piece->Move(board_cursorX, board_cursorY);
                    SetCurrentPiece(nullptr);
                }
            }
        }
    }

    UpdateTable();
    return false;

}


int Board::PieceAt(uInt posx, uInt posy) {

    auto found = pieces_locations.count((posx * 8) + posy);

    if (found == 1) {
        auto pc = GetPiece(posx, posy);
        if (pc->GetColor() == 1) {
            return 1;
        } else if (pc->GetColor() == 0) {
            return 2;
        }
    };
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


    Board::UpdateTable();
    currently_held_piece = nullptr;
}


std::vector<std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    return board_table;
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