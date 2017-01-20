//
// Created by johann on 21/12/16.
//

#ifndef CHESS_GAME_PLAYER_H
#define CHESS_GAME_PLAYER_H

#include "object.h"
#include "Board.h"

class Player {
private:
    Player_side  side;
    std::string name;
public:

    Player(Player_side side) : side(side) {initName();}

    void choice_of_action ( Board&  , sf::RenderWindow&,const std::pair <int,int>& my_coordinates);

    Player_side getSide() const {
        return side;
    }

    const std::string &getName() const {
        return name;
    }
    void initName();


};


#endif //CHESS_GAME_PLAYER_H
