//
// Created by johann on 20/12/16.
//

#ifndef CHESS_GAME_BOARD_H
#define CHESS_GAME_BOARD_H

#include "Header.h"
#include "object.h"

const int board_width = 8;
const int board_height = 8;


using matrice =  std::vector<std::vector<std::unique_ptr<Object>>>;

class Board {
private:
    matrice board;
public:
    explicit Board();

    Board(const Board &) = delete;

    Board &operator=(const Board &) = delete;

    ~Board() = default;

    void display();


    const std::unique_ptr<Object>&getBoard
            (const  int& i ,const  int& j) const {
        return board[i][j];
    }


};


#endif //CHESS_GAME_BOARD_H
