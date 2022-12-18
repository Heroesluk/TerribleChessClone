//
// Created by heroesluk on 17.12.22.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "Board.h"
using uInt = unsigned int;



class Game{
private:
    uInt mx; uInt my;
    uInt bx; uInt by;

    std::shared_ptr<Board> game_bard;
    bool current_player;

public:
    void OnClick(uInt mouse_x, uInt mouse_y);
    bool MakeAction(uInt board_x, uInt board_y);
    void ChangeTurn();
    void Draw();

};

#endif //CHESS_GAME_H
