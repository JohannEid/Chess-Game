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
void Pawn::move(Board &, const int &x, const int &y) {
    
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

