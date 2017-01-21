//
// Created by johann on 12/01/17.
//

#ifndef CHESS_GAME_COMMON_H
#define CHESS_GAME_COMMON_H

#include "Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

class Board;
enum class Player_side;


const std:: pair <int,int> coordinateChoice();
const std::pair<int, int> pawnSelection(Board &, sf::RenderWindow &,const Player_side&);
void changeSideToPlay( int& index );
const std::pair<int, int> moveSelection (Board & , sf::RenderWindow & );




#endif //CHESS_GAME_COMMON_H
