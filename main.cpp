#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"

int main() {

    Player a(Player_side::LEFT);
    Player b(Player_side::RIGHT);
    Board my_board;
    while (1) {

        my_board.display();
        a.choice_of_action(my_board);
        my_board.display();
        b.choice_of_action(my_board);
        my_board.display();

    }


    return 0;
}