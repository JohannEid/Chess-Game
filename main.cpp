#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"

int main() {

    Player lhs(Player_side::LEFT);
    Player rhs (Player_side::RIGHT);
    std::string name_of_winner{" "};
    Board my_board;
    while (my_board.isGame()) {

        my_board.display();
        lhs.choice_of_action(my_board);
        my_board.display();
        rhs.choice_of_action(my_board);
        my_board.display();
    }
    (my_board.getWinner()== Player_side::LEFT)?  name_of_winner = lhs.getName() : rhs.getName();
    std::cout << "Congratulation" << name_of_winner << "wins !! "<<std::endl;

    return 0;
}