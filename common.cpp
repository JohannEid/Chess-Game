//
// Created by johann on 12/01/17.
//

#include "common.h"
#include "Board.h"

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

