#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"

int main() {
    Board my_board;
    /*
    Player a(Player_side::LEFT);
    Player b(Player_side::RIGHT);

    a.choice_of_action(my_board);
    b.choice_of_action(my_board);

*/
    my_board.display();
    return 0;
}