//
// Created by johann on 12/01/17.
//

#ifndef CHESS_GAME_COMMON_H
#define CHESS_GAME_COMMON_H

#include "Header.h"
#include <SFML/Graphics.hpp>
class Board;
enum class Player_side;


const std:: pair <int,int> coordinateChoice();
const std::pair<int, int> pawnSelection(Board &, sf::RenderWindow &);
void   changeSideToPlay(Player_side& );



#endif //CHESS_GAME_COMMON_H
