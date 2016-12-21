//
// Created by johann on 21/12/16.
//

#include "Player.h"

void Player::choice_of_action(Board &board) {
    std::pair<int, int> my_coordinates = pawnSelection(board);
    int x{my_coordinates.first};
    int y{my_coordinates.second};
    board.getBoard(x, y)->move(board);

}

void Player::initName() {
    std::string name;

    std::cout << "Please choose a name" << std::endl;
    std::cin >> name;
    Player::name = name;


}

const std::pair<int, int> Player::pawnSelection(Board &board) {
    std::string ix{" "};
    std::string iy{" "};
    int x{0};
    int y{0};

    while (true) {
        std::cout << "Please select a pawn to move " << std::endl;
        try {
            std::cin >> ix;
            std::cin >> iy;

            x = std::stoi(ix);
            y = std::stoi(ix);

            if (board.getBoard(x, y)->getSide() == getSide()) {
                break;
            } else
                throw std::domain_error("Please select valid coordinates !");


        }
        catch (std::exception const &e) {
            std::cerr << "Error" << e.what() << std::endl;
        }
    }
    return std::make_pair(x, y);


}
