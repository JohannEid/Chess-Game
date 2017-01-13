//
// Created by johann on 20/12/16.
//

#include "object.h"
#include "Board.h"
#include "common.h"


void Object::move(Board &board, const int &x, const int &y) {

}

const char Object::sideToChar() {
    if (getSide() == Player_side::LEFT) { return 'l'; }
    else if (getSide() == Player_side::RIGHT) { return 'r'; }
    else { return ' '; }
}

void Pawn::move(Board &board, const int &x, const int &y) {
    std::pair<int, int> my_move;
    std::vector<std::pair<int, int>> my_moves{getMovePossibilites(board, x, y)};
    displayMovePossibilities(my_moves);
    my_move = selectPositionToMove(my_moves);
    board.setBoard(x, y, my_move.first, my_move.second);
}

int Pawn::sideToDirection() {

    if (getSide() == Player_side::LEFT) { return 1; }
    return -1;
}

const std::vector<std::pair<int, int >> Pawn::getMovePossibilites
        (const Board &board, const int &x, const int &y) {
    std::vector<std::pair<int, int>> my_moves;
    int to_move_x_two = x + (2 * sideToDirection());
    int to_move_x_one = x + (1 * sideToDirection());

    if ((((x == left_pawn_starting) && (getSide() == Player_side::LEFT))
         || ((x == right_pawn_starting) && (getSide() == Player_side::RIGHT))) &&
        (board.getBoard(to_move_x_two, y)->getSide() == Player_side::NONE)) {
        my_moves.push_back(std::make_pair(to_move_x_two, y));
    }
    if ((to_move_x_one > 0) && (to_move_x_one < board_width)) {
        if ((board.getBoard(to_move_x_one, y)->getSide() == Player_side::NONE))
            my_moves.push_back(std::make_pair(to_move_x_one, y));


        if (((y + 1 < board_height)) && (board.getBoard(to_move_x_one, y + 1)->getSide() != Player_side::NONE &&
                                         board.getBoard(to_move_x_one, y + 1)->getSide() != getSide()))
            my_moves.push_back(std::make_pair(to_move_x_one, y + 1));

        if (((y - 1 >= 0)) && (board.getBoard(to_move_x_one, y - 1)->getSide() != Player_side::NONE
                               && board.getBoard(to_move_x_one, y - 1)->getSide() != getSide()))
            my_moves.push_back(std::make_pair(to_move_x_one, y - 1));
    }
    return my_moves;
}

void Pawn::displayMovePossibilities(const std::vector<std::pair<int, int>> &my_moves) {
    if (my_moves.empty()) { std::cout << "You cannot move with this pawn!"; }
    else {
        for (const auto &elem : my_moves) {
            std::cout << "You can move in x: " << elem.first + 1
                      << std::endl << "y:" << elem.second + 1 << std::endl << std::endl;
        }
    }
}

const std::pair<int, int> Pawn::selectPositionToMove
        (const std::vector<std::pair<int, int>> &my_possibilities) {

    std::pair<int, int> coordinates;
    while (true) {
        std::cout << "Please select the spot to move into!" << std::endl;
        coordinates = coordinateChoice();
        try {
            for (const auto &elem : my_possibilities) {
                if (elem == coordinates) { return coordinates; }
            }
            throw std::domain_error("Please select a spot you can move into ! ");
        }
        catch (std::exception const &e) {
            std::cerr << "Error : " << e.what() << std::endl;
        }
    }
}


const std::vector<std::pair<int, int >> Tower::getMovePossibilites
        (const Board &board, const int &x_from, const int &y_from) {
    std::vector<std::pair<int, int>> my_moves;
    int x_path{x_from};
    int y_path{y_from};
    while ((x_path + 1 < board_width) && (board.getBoard(x_path + 1, y_path)->getSide() != getSide())) {
        ++x_path;
        my_moves.push_back(std::make_pair(x_path, y_path));
    }
    x_path = x_from;
    while ((x_path - 1 >= 0) && (board.getBoard(x_path - 1, y_path)->getSide() != getSide())) {
        --x_path;
        my_moves.push_back(std::make_pair(x_path, y_path));
    }
    x_path = x_from;
    while ((y_path + 1 < board_height) && (board.getBoard(x_path, y_path + 1)->getSide() != getSide())) {
        ++y_path;
        my_moves.push_back(std::make_pair(x_path, y_path));
    }
    y_path = y_from;
    while ((y_path -1 >= 0) && (board.getBoard(x_path, y_path -1)->getSide() != getSide())) {
        --y_path;
        my_moves.push_back(std::make_pair(x_path, y_path));
    }
    return my_moves;

}



