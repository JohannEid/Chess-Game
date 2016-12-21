//
// Created by johann on 21/12/16.
//

#ifndef CHESS_GAME_PLAYER_H
#define CHESS_GAME_PLAYER_H

#include "object.h"
class Board;


class Player {
private:
    Player_side  side;
    std::string name;
public:
    Player(Player_side side) : side(side) {initName();}

    void choice_of_action (const Board& );

    Player_side getSide() const {
        return side;
    }

    const std::string &getName() const {
        return name;
    }
    void initName();


};


#endif //CHESS_GAME_PLAYER_H
