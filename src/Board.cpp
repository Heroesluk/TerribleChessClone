#include "Board.h"
#include <bits/stdc++.h>

#include <utility>
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
void Board::SetupBoardPieces() {

    piece_table2.clear();

    piece_table2[0] = std::make_shared<Rook>(0, 0, true,   "Rook");
    piece_table2[1] = std::make_shared<Knight>(1, 0, true, "Knight");
    piece_table2[2] = std::make_shared<Bishop>(2, 0, true, "Bishop");
    piece_table2[3] = std::make_shared<King>(3, 0, true,   "King");
    piece_table2[4] = std::make_shared<Queen>(4, 0, true,  "Queen");
    piece_table2[5] = std::make_shared<Bishop>(5, 0, true, "Bishop");
    piece_table2[6] = std::make_shared<Knight>(6, 0, true, "Knight");
    piece_table2[7] = std::make_shared<Rook>(7, 0, true,   "Rook");

    piece_table2[8] = std::make_shared<Pawn>(0,  1, true, "Pawn");
    piece_table2[9] = std::make_shared<Pawn>(1,  1, true, "Pawn");
    piece_table2[10] = std::make_shared<Pawn>(2, 1, true, "Pawn");
    piece_table2[11] = std::make_shared<Pawn>(3, 1, true, "Pawn");
    piece_table2[12] = std::make_shared<Pawn>(4, 1, true, "Pawn");
    piece_table2[13] = std::make_shared<Pawn>(5, 1, true, "Pawn");
    piece_table2[14] = std::make_shared<Pawn>(6, 1, true, "Pawn");
    piece_table2[15] = std::make_shared<Pawn>(7, 1, true, "Pawn");


    piece_table2[56] = std::make_shared<Rook>(0, 7,   false, "Rook");
    piece_table2[57] = std::make_shared<Knight>(1, 7, false, "Knight");
    piece_table2[58] = std::make_shared<Bishop>(2, 7, false, "Bishop");
    piece_table2[59] = std::make_shared<King>(3, 7,   false, "King");
    piece_table2[60] = std::make_shared<Queen>(4, 7,  false, "Queen");
    piece_table2[61] = std::make_shared<Bishop>(5, 7, false, "Bishop");
    piece_table2[62] = std::make_shared<Knight>(6, 7, false, "Knight");
    piece_table2[63] = std::make_shared<Rook>(7, 7,   false, "Rook");

    piece_table2[48] = std::make_shared<Pawn>(0, 6, false, "Pawn");
    piece_table2[49] = std::make_shared<Pawn>(1, 6, false, "Pawn");
    piece_table2[50] = std::make_shared<Pawn>(2, 6, false, "Pawn");
    piece_table2[51] = std::make_shared<Pawn>(3, 6, false, "Pawn");
    piece_table2[52] = std::make_shared<Pawn>(4, 6, false, "Pawn");
    piece_table2[53] = std::make_shared<Pawn>(5, 6, false, "Pawn");
    piece_table2[54] = std::make_shared<Pawn>(6, 6, false, "Pawn");
    piece_table2[55] = std::make_shared<Pawn>(7, 6, false, "Pawn");





    currently_held_piece = nullptr;
}

bool Board::MakeAction(uInt board_cursorX, uInt board_cursorY, bool color_to_move) {
    //function returns true if player makes any real movement on the board
    //swapping held piece does not count
    bool made_move = false;


    auto pc_at_click = GetPiece(board_cursorX, board_cursorY);

    if (pc_at_click != nullptr) {
        if (currently_held_piece == nullptr && pc_at_click->GetColor() == color_to_move) { //set a held piece if not holding anything
            SetCurrentPiece(pc_at_click);
        }

        //swap piece or castle
        else if (currently_held_piece != nullptr) {

            if (pc_at_click->GetColor() == currently_held_piece->GetColor())
            {
                if(currently_held_piece->GetPieceName()=="King"&&pc_at_click->GetPieceName()=="Rook"){
                    if(CheckIfLegalMove(board_cursorX,board_cursorY)){
                        exit(1);
                    }
                }
                else{
                    SetCurrentPiece(pc_at_click);
                }
            }
            else if (currently_held_piece->GetColor() == color_to_move) { //take an enemy piece, replace with own
                if (CheckIfLegalTake(board_cursorX, board_cursorY)) {
                    currently_held_piece->Move(board_cursorX, board_cursorY);
                    SetCurrentPiece(nullptr);
                    RemovePieceAt(board_cursorX, board_cursorY);
                    made_move =  true;


                }

            }
        }

    }

    else if (currently_held_piece != nullptr) {
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

const std::vector<std::shared_ptr<Piece>> Board::ReturnAllPieces() {
    std::vector<std::shared_ptr<Piece>> pieces;
    for(auto pair: piece_table2){
        pieces.push_back(pair.second);
    }

    return pieces;
}

uInt Board::GetPieceIndex(uInt posx, uInt posy) {
    return posx + (8 * posy);
}

bool Board::CheckIfLegalMove(uInt moveX, uInt moveY){
    auto moves = currently_held_piece->LegalMoves(ReturnPiecesPositions());

//    auto position = moveX + (moveY+8);
//    bool a = std::any_of(moves.begin(),moves.end(),[position](uInt move){return position == move;});
//
//    return a;

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

std::shared_ptr<Piece> Board::GetCurrentlyHeld() {
    return currently_held_piece;
}

void Board::ResetBoard() {
    SetupBoardPieces();


}
