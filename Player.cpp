//
// Created by johann on 21/12/16.
//

#include "Player.h"

void Player::choice_of_action(const Board &) {

}

void Player::initName() {
    std::string name;

    std::cout << "Please choose a name"<<std::endl;
    std::cin >> name;
    Player :: name = name;


}
