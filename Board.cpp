//
// Created by johann on 20/12/16.
//

#include "Board.h"

Board::Board() {
    for (int i=0; i<board_width; i++)
    {
        board.push_back(std::vector<std::unique_ptr<Object>>());
        for (int j=0; j<board_height; j++)
        {
            board[i].push_back(std::make_unique<Object>());
        }
    }



}

void Board::display() {
    for (unsigned int i{0}; i < board_width; i++) {
        for (unsigned int j{0}; j < board_height; j++) {
            getBoard(i, j)->display();

        }
    }
}