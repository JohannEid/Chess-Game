//
// Created by johann on 12/01/17.
//

#include "common.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

const std::pair<int, int> coordinateChoice() {
    std::string ix{" "};
    std::string iy{" "};
    int x{0};
    int y{0};

    while (true) {
        try {
            std::cin >> ix;
            std::cin >> iy;

            x = std::stoi(ix)-1 ;
            y = std::stoi(iy)-1;
            if ((x < board_width) && (x >= 0) && (y < board_height) && (y >= 0)) {
                return std::make_pair(x , y);
            } else { throw std::domain_error("Cannot select coordinates outside of board !"); };

        }
        catch (std::exception const &e) {
            std::cerr << "Error" << e.what() << std::endl;
        }
    }
}


void changeSideToPlay( int& index ) {
    (index == 0) ? index += 1 :
            index -= 1 ;
}

const std::pair<int, int> pawnSelection(Board & board, sf::RenderWindow & window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    for (int i{0}; i < board_width; ++i)
        for (int j{0}; j < board_height; ++j) {
            if ((board.getBoard(i, j)->getSprite_figure().
                    getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))) {
                return std::make_pair(i, j); }

        }
    return std::make_pair(88,88);
}
const std::pair<int, int> moveSelection (Board & board, sf::RenderWindow & window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    return std::make_pair(mouse_pos.x / board_width,mouse_pos.y / board_width);
}