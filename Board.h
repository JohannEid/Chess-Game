//
// Created by johann on 20/12/16.
//

#ifndef CHESS_GAME_BOARD_H
#define CHESS_GAME_BOARD_H

#include "Header.h"
#include "object.h"

using matrice =  std::vector < std::vector < std::unique_ptr<Object>>> ;

class Board {
private:
    matrice my_board;
public:
    Board();
    void display();


};


#endif //CHESS_GAME_BOARD_H
