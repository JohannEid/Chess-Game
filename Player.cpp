//
// Created by johann on 21/12/16.
//

#include "Player.h"
#include "common.h"

void Player::choice_of_action(Board &board) {
    std::pair<int, int> my_coordinates = pawnSelection(board);
    int x{my_coordinates.first};
    int y{my_coordinates.second};
    board.getBoard(x, y)->move(board, x, y);

}

void Player::initName() {
    std::string name;

    std::cout << "Please choose a name" << std::endl;
    std::cin >> name;
    Player::name = name;

}

const std::pair<int, int> Player::pawnSelection(Board &board) {
    int x{0};
    int y{0};
    std::pair<int,int> coordinates;
    while (true) {
        std::cout << "Please select a pawn to move " << std::endl;
        coordinates = coordinateChoice();
        x = coordinates.first;
        y = coordinates.second;

        try {
            if (board.getBoard(x, y)->getSide() == getSide()) {
                return std::make_pair(x,y);
            } else
                throw std::domain_error("Please select one of your pawns !");
         }
        catch (std::exception const &e) {
            std::cerr << "Error" << e.what() << std::endl;
        }
    }
}


