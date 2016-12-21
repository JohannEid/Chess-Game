#include "Header.h"
#include "object.h"
#include "Board.h"

int main() {
//    my_board.display();
std:: unique_ptr<Object> otr = std:: make_unique<Object> ();
    otr->display();
    return 0;
}