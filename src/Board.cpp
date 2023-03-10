#include "Board.h"
#include <bits/stdc++.h>

#include <utility>
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"

//pieces_input is in format of piece_name-color-piece_index
//where piece name is string, color is either 1(white) or 0, and index is from 0 to 63
void Board::SetupBoardPieces(std::vector<std::vector<std::string>> pieces_input) {

    piece_table2.clear();

    for(auto piece_info: pieces_input){
        std::string piece_type = piece_info.at(0);
        int piece_color = std::stoi(piece_info.at(1));
        uInt piece_position = std::stoi(piece_info.at(2));


        if(piece_type=="Rook"){
            piece_table2[piece_position] = std::make_shared<Rook>(piece_position%8, piece_position/8, piece_color, piece_type);
        }
        else if(piece_type=="Pawn"){
            piece_table2[piece_position] = std::make_shared<Pawn>(piece_position%8, piece_position/8, piece_color, piece_type);
        }
        else if(piece_type=="Knight"){
            piece_table2[piece_position] = std::make_shared<Knight>(piece_position%8, piece_position/8, piece_color, piece_type);
        }
        else if(piece_type=="King"){
            piece_table2[piece_position] = std::make_shared<King>(piece_position%8, piece_position/8, piece_color, piece_type);
        }
        else if(piece_type=="Queen"){
            piece_table2[piece_position] = std::make_shared<Queen>(piece_position%8, piece_position/8, piece_color, piece_type);
        }
        else if(piece_type=="Bishop"){
            piece_table2[piece_position] = std::make_shared<Bishop>(piece_position%8, piece_position/8, piece_color, piece_type);
        }


    }

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

}
