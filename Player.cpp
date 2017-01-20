//
// Created by johann on 21/12/16.
//

#include "Player.h"
#include "common.h"

void Player::choice_of_action(Board &board, sf::RenderWindow &window,const std::pair <int ,int>& my_coordinates) {

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








