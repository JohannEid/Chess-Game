//
// Created by johann on 20/12/16.
//

#include "object.h"
#include "Board.h"
#include "common.h"

const char Object::sideToChar() {
    if (getSide() == Player_side::LEFT) { return 'l'; }
    else if (getSide() == Player_side::RIGHT) { return 'r'; }
    else { return ' '; }
}

void Object::setSprite(const sf::Texture &texture, const sf::IntRect &rectangle) {
    sprite_figure.setTexture(texture);
    sprite_figure.setTextureRect(rectangle);
}



bool Pawn::move(Board &board, const int &x, const int &y,const int& x_to,const int& y_to,
                const std::vector< std::pair<int, int>>& my_moves) {
    std::cout << "YOYO " <<std::endl;
    std::pair<int, int> my_move;
    my_move = selectPositionToMove(my_moves,x_to,y_to);
    if (my_move != std::make_pair(0, 0)) { board.setBoard(x, y, my_move.first, my_move.second);
    return true;}
    else{return false;}
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
        if ((board.getBoard(to_move_x_one, y)->getSide() == Player_side::NONE)) {
            my_moves.push_back(std::make_pair(to_move_x_one, y));
        }


        if (((y + 1 < board_height)) && (board.getBoard(to_move_x_one, y + 1)->getSide() != Player_side::NONE &&
                                         board.getBoard(to_move_x_one, y + 1)->getSide() !=
                                         getSide())) { my_moves.push_back(std::make_pair(to_move_x_one, y + 1)); }

        if (((y - 1 >= 0)) && (board.getBoard(to_move_x_one, y - 1)->getSide() != Player_side::NONE
                               && board.getBoard(to_move_x_one, y - 1)->getSide() != getSide())) {
            my_moves.push_back(std::make_pair(to_move_x_one, y - 1));
        }
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
        (const std::vector<std::pair<int, int>> &my_possibilities,const int& x_to,const int& y_to) {

    std::pair<int, int> coordinates {std::make_pair(x_to,y_to)};
    if (!my_possibilities.empty()) {

                for (const auto &elem : my_possibilities) {
                    if (elem == coordinates) { return coordinates; }
                }

    }
    return std::make_pair(0, 0);
}

const std::vector<std::pair<int, int>> Pawn::checkPath
        (const Board &board, const std::vector<std::pair<int, int>> &coordinates_to_check, const int &x_from,
         const int &y_from) {
    int x_path{x_from};
    int y_path{y_from};
    std::vector<std::pair<int, int>> my_moves;
    for (const auto &elem : coordinates_to_check) {
        x_path = x_from;
        y_path = y_from;
        while (((x_path + elem.first >= 0) && (x_path + elem.first < board_width)
                && (y_path + elem.second >= 0) && (y_path + elem.second < board_height))
               && (board.getBoard(x_path + elem.first, y_path + elem.second)->getSide() != getSide())) {

            x_path += elem.first;
            y_path += elem.second;
            my_moves.push_back(std::make_pair(x_path, y_path));
            if (board.getBoard(x_path, y_path)->getSide() != Player_side::NONE) { break; }
        }
    }
    return my_moves;
}

const std::vector<std::pair<int, int>> Pawn::checkPosition
        (const Board &board, const std::vector<std::pair<int, int>> &coordinates_to_check,
         const int &x_from, const int &y_from) {
    int x_path{x_from};
    int y_path{y_from};
    std::vector<std::pair<int, int>> my_moves;
    for (const auto &elem : coordinates_to_check) {
        x_path = x_from + elem.first;
        y_path = y_from + elem.second;
        if ((x_path >= 0) && (x_path < board_width)
            && (y_path >= 0) && (y_path < board_height)
            && (board.getBoard(x_path, y_path)->getSide() != getSide())) {
            my_moves.push_back(std::make_pair(x_path, y_path));
        }
    }
    return my_moves;
}



const std::vector<std::pair<int, int >> Knight::getMovePossibilites
        (const Board &board, const int &x_from, const int &y_from) {
    std::vector<std::pair<int, int>> coordinates_to_check
            {std::make_pair(3, 2), std::make_pair(3, -2), std::make_pair(-3, 2),
             std::make_pair(-3, -2), std::make_pair(2, 3), std::make_pair(2, -3), std::make_pair(-2, 3),
             std::make_pair(-2, -3)};
    return checkPosition(board, coordinates_to_check, x_from, y_from);
}

const std::vector<std::pair<int, int >> Tower::getMovePossibilites
        (const Board &board, const int &x_from, const int &y_from) {
    std::vector<std::pair<int, int>> coordinates_to_check
            {std::make_pair(1, 0), std::make_pair(-1, 0),
             std::make_pair(0, 1), std::make_pair(0, -1)};
    return checkPath(board, coordinates_to_check, x_from, y_from);

}

const std::vector<std::pair<int, int >> Crazy::getMovePossibilites
        (const Board &board, const int &x_from, const int &y_from) {
    std::vector<std::pair<int, int>> coordinates_to_check
            {std::make_pair(1, 1), std::make_pair(1, -1),
             std::make_pair(-1, 1), std::make_pair(-1, -1)};
    return checkPath(board, coordinates_to_check, x_from, y_from);
}

const std::vector<std::pair<int, int >> Queen::getMovePossibilites
        (const Board &board, const int &x_from, const int &y_from) {
    std::vector<std::pair<int, int>> coordinates_to_check
            {std::make_pair(1, 1), std::make_pair(1, -1),
             std::make_pair(-1, 1), std::make_pair(-1, -1),
             std::make_pair(1, 0), std::make_pair(-1, 0),
             std::make_pair(0, 1), std::make_pair(0, -1)};
    return checkPath(board, coordinates_to_check, x_from, y_from);
}

const std::vector<std::pair<int, int >> King::getMovePossibilites
        (const Board &board, const int &x_from, const int &y_from) {
    std::vector<std::pair<int, int>> coordinates_to_check
            {std::make_pair(1, 1), std::make_pair(1, -1),
             std::make_pair(-1, 1), std::make_pair(-1, -1),
             std::make_pair(1, 0), std::make_pair(-1, 0),
             std::make_pair(0, 1), std::make_pair(0, -1)};
    return checkPosition(board, coordinates_to_check, x_from, y_from);
}
