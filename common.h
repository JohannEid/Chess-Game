//
// Created by johann on 12/01/17.
//

#ifndef CHESS_GAME_COMMON_H
#define CHESS_GAME_COMMON_H

#include "Header.h"
const std:: pair <int,int> coordinateChoice();
inline const std::pair<int,int> reverse(const std::pair<int,int>&to_reverse)
{return std::make_pair(to_reverse.second,to_reverse.first);}

#endif //CHESS_GAME_COMMON_H
