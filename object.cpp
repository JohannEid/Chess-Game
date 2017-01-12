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
    std::vector <std::pair<int,int>> my_moves {getMovePossibilites(x,y)};

/*
    std::pair<int, int> my_way{(0, 0)};
    Player_side my_side{board.getBoard(x, y)->getSide()};
    std::vector<std::pair<int, int>> possible_coordinates;
    std::pair<int, int> target_dioganoal_two{};
    (my_side == Player_side::LEFT) ? my_way.first = 1 : my_way.first = -1;
    int x_to{x + my_way.first};

    if ((x_to < board_width) && (x_to >= 0)) {
        std::pair<int, int> front_target{(x_to, y)};
        (board.getBoard(front_target.first, front_target.second)->getSide() == Player_side::NONE) ?
        possible_coordinates.push_back(front_target) : ' ';
    }
    if (y + 1 < board_height) {
        std::pair<int, int> target_diagonal_one{x_to, y + 1};
        board.getBoard(target_diagonal_one.first, target_diagonal_one.second)->getSide() == Player_side::NONE) ?
        possible_coordinates.push_back(target_diagonal_one) : ' ';
    }
    if (y + -1 >= 0) {
        std::pair<int, int> target_diagonal_one{x_to, y + -1};
        board.getBoard(front_target.first, front_target.second)->getSide() == Player_side::NONE) ?
        possible_coordinates.push_back(front_target) : ' ';
    }
*/
}

int Pawn::sideToDirection() {

    if (getSide() == Player_side::LEFT) { return 1; }
    return -1;
}

const std::vector<std::pair<int, int >> Pawn::getMovePossibilites(const int &x, const int &y) {
    std::vector<std::pair<int, int>> my_moves;
    int to_move_x = x + (1 * sideToDirection());
    if (((x == left_pawn_starting) && (getSide() == Player_side::LEFT))
        || ((x == right_pawn_starting) && (getSide() == Player_side::RIGHT))) {
        my_moves.push_back(std::make_pair(x + (2 * sideToDirection()), y));
    }
    if ((to_move_x> 0)&&(to_move_x < board_width )){my_moves.push_back(std::make_pair(to_move_x, y));};
    return my_moves;
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

