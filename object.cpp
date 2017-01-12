//
// Created by johann on 20/12/16.
//

#include "object.h"
#include "Board.h"


std::pair<int, int> Object::inputCoordinates(Board &board) {
    std::string ix{" "};
    std::string iy{" "};
    int x{0};
    int y{0};
    while (true) {
        std::cout << "Please select a pawn to move " << std::endl;
        try {
            std::cin >> ix;
            std::cin >> iy;

            x = std::stoi(ix) - 1;
            y = std::stoi(ix) - 1;

            if ((x < board_width) && (x >= 0) && (y < board_height) && (y >= 0)) {
                if (board.getBoard(x, y)->getSide() == getSide()) {
                    throw std::domain_error("You cannot move on one of your pawns  !");
                } else
                    break;
            } else
                throw std::domain_error("Invalid coordinates outside of board  !");


        }
        catch (std::exception const &e) {
            std::cerr << "Error" << e.what() << std::endl;
        }

    }
    return std::make_pair(x, y);
}

void Object::move(Board &board, const int &x, const int &y) {
    inputCoordinates(board);

}

const char Object::sideToChar() {
    if (getSide() == Player_side::LEFT) { return 'l'; }
    else if (getSide() == Player_side::RIGHT) { return 'r'; }
    else { return ' '; }
}

void Pawn::move(Board &board, const int &x, const int &y) {
    std::vector<std::pair<int, int>> my_moves{getMovePossibilites(board, x, y)};


}

int Pawn::sideToDirection() {

    if (getSide() == Player_side::LEFT) { return 1; }
    return -1;
}

const std::vector<std::pair<int, int >> Pawn::getMovePossibilites(const Board &board, const int &x, const int &y) {
    std::vector<std::pair<int, int>> my_moves;
    int to_move_x_two = x + (2 * sideToDirection());
    int to_move_x_one = x + (1 * sideToDirection());
    if ((((x == left_pawn_starting) && (getSide() == Player_side::LEFT))
         || ((x == right_pawn_starting) && (getSide() == Player_side::RIGHT))) &&
        (board.getBoard(to_move_x_two, y)->getSide() == Player_side::NONE)) {
        my_moves.push_back(std::make_pair(to_move_x_two, y));
    }
    if (((to_move_x_one > 0) && (to_move_x_one < board_width)) &&
        (board.getBoard(to_move_x_one, y)->getSide() == Player_side::NONE)) {
        my_moves.push_back(std::make_pair(to_move_x_one, y));
    };
    if ((((to_move_x_one > 0) && (to_move_x_one < board_width)) && (y + 1 < board_height))
        && (board.getBoard(to_move_x_one, y + 1)->getSide() != Player_side::NONE
            && board.getBoard(to_move_x_one, y + 1)->getSide() != getSide())) {
        my_moves.push_back(std::make_pair(to_move_x_one, y + 1));
    }
    if ((((to_move_x_one > 0) && (to_move_x_one < board_width)) && (y - 1 > 0))
        && (board.getBoard(to_move_x_one, y - 1)->getSide() != Player_side::NONE
            && board.getBoard(to_move_x_one, y - 1)->getSide() != getSide())) {
        my_moves.push_back(std::make_pair(to_move_x_one, y - 1));
    }
    return my_moves;
}

void Pawn::displayMovePossibilities(const std::vector<std::pair<int, int>> &my_moves) {
    if (my_moves.empty()) { std::cout << "You cannot move with this pawn!"; }
    else {
        for (const auto &elem : my_moves) {
            std::cout << "You can move in x: " << elem.first << std::endl << "y:" << elem.second;
        }
    }
}


void King::move(Board &, const int &x, const int &y) {

}

void Tower::move(Board &, const int &x, const int &y) {
}

void Knight::move(Board &, const int &x, const int &y) {
}


void Crazy::move(Board &, const int &x, const int &y) {
}

void Queen::move(Board &, const int &x, const int &y) {
}

