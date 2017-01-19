//
// Created by johann on 21/12/16.
//

#include "Player.h"
#include "common.h"

void Player::choice_of_action(Board &board, sf::RenderWindow &window) {
    std::pair<int, int> my_coordinates = pawnSelection(board, window);
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

const std::pair<int, int> Player::pawnSelection(Board &board, sf::RenderWindow &window) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

            for (int i{0}; i < board_width; ++i)

                for (int j{0}; j < board_height; ++j) {
                    if ((board.getBoard(i, j)->getSprite_figure().
                            getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) &&
                        (board.getBoard(i, j)->getSide() == getSide())) {

                        std::cout << i << std::endl << j << std::endl;
                        return std::make_pair(i, j);
                    }
                }

        }






