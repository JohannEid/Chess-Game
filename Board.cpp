//
// Created by johann on 20/12/16.
//

#include "Board.h"

Board::Board() {
board.resize(board_width,std::vector<std::unique_ptr<Object>>
        (board_height,std::make_unique<Object>()));

}

void Board :: display()
{
    for (unsigned int i {0};i < board_width; i++)
    {
        for (unsigned int j {0}; j < board_height ; j++) {
getBoard(i,j)->display();

        }
    }
}