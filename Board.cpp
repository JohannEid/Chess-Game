//
// Created by johann on 20/12/16.
//

#include "Board.h"
#include "object.h"


const int raw_pawn_lhs = 1;
const int raw_pawn_rhs = 6;


Board::Board() {
    for (unsigned int i{0}; i < board_width; i++) {
        board.push_back(std::vector<std::unique_ptr<Object>>());
        for (unsigned int j{0}; j < board_height; j++) {
            board[i].push_back(std::make_unique<Object>());
        }
    }
    for (unsigned int j{0}; j < board_height; j++) {
        board[raw_pawn_lhs][j] = std::make_unique<Pawn>(Player_side::LEFT);
    }
    for (unsigned int j{0}; j < board_height; j++) {
        board[raw_pawn_rhs][j] = std::make_unique<Pawn>(Player_side::RIGHT);
    }
    board[raw_pawn_lhs - 1][0] = std::make_unique<Tower>(Player_side::LEFT);
    board[raw_pawn_lhs - 1][board_height - 1] = std::make_unique<Tower>(Player_side::LEFT);

    board[raw_pawn_rhs + 1][0] = std::make_unique<Tower>(Player_side::RIGHT);
    board[raw_pawn_rhs + 1][board_height - 1] = std::make_unique<Tower>(Player_side::RIGHT);

    board[raw_pawn_lhs - 1][1] = std::make_unique<Knight>(Player_side::LEFT);
    board[raw_pawn_lhs - 1][board_height - 2] = std::make_unique<Knight>(Player_side::LEFT);

    board[raw_pawn_rhs + 1][1] = std::make_unique<Knight>(Player_side::RIGHT);
    board[raw_pawn_rhs + 1][board_height - 2] = std::make_unique<Knight>(Player_side::RIGHT);

    board[raw_pawn_lhs - 1][2] = std::make_unique<Crazy>(Player_side::LEFT);
    board[raw_pawn_lhs - 1][board_height - 3] = std::make_unique<Crazy>(Player_side::LEFT);

    board[raw_pawn_rhs + 1][2] = std::make_unique<Crazy>(Player_side::RIGHT);
    board[raw_pawn_rhs + 1][board_height - 3] = std::make_unique<Crazy>(Player_side::RIGHT);

    board[raw_pawn_lhs - 1][3] = std::make_unique<King>(Player_side::LEFT);
    board[raw_pawn_lhs - 1][board_height - 4] = std::make_unique<Queen>(Player_side::LEFT);

    board[raw_pawn_rhs + 1][3] = std::make_unique<King>(Player_side::RIGHT);
    board[raw_pawn_rhs + 1][board_height - 4] = std::make_unique<Queen>(Player_side::RIGHT);


}

void Board::display() {
    for (unsigned int i{0}; i < board_width; i++) {
        for (unsigned int j{0}; j < board_height; j++) {
            getBoard(i, j)->display();

        }
        std::cout << std::endl;
    }
}

bool Board::isNewQueen(const int &from_x, const int &from_y, const int &to_x,
                       const int &to_y) {
    if ((board[from_x][from_y]->getName() == "Pawn") &&
        (((board[from_x][from_y]->getSide() == Player_side::RIGHT)
          && (to_x == 0)) || ((board[from_x][from_y]->getSide() == Player_side::LEFT)
                              && (to_x == board_width - 1)))) { return true; }
    else { return false; }

}

void Board::setBoard(const int &from_x, const int &from_y, const int &to_x,
                     const int &to_y) {
    std::unique_ptr<Object> empty = std::make_unique<Object>();


    board[to_x][to_y] = std::move(board[from_x][from_y]);
    board[from_x][from_y] = std::move(empty);
}
