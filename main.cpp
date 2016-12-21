#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"

int main() {
    Board my_board;
    Player a(Player_side::LEFT);
    Player b(Player_side::RIGHT);


    my_board.display();
    return 0;
}