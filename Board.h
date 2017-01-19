//
// Created by johann on 20/12/16.
//

#ifndef CHESS_GAME_BOARD_H
#define CHESS_GAME_BOARD_H

#include "Header.h"
#include "object.h"
class Object;
const int board_width = 8;
const int board_height = 8;


using matrice =  std::vector<std::vector<std::unique_ptr<Object>>>;

class Board {
private:
    matrice board;
    int number_of_turns = 0;
    bool game = true;
    Player_side winner;
    std::unique_ptr<Object> createPawn (const Player_side&,const char& );
    sf::Texture texture_board;
    sf::Texture texture_figure;
    sf::Sprite sprite_board;
    bool isNewQueen(const int &, const int &, const int &,
                    const int &);
    void winGame(const int &, const int &, const int &,
                 const int &);



public:
    explicit Board();

    const std::unique_ptr<Object> & getBoard
            (const  int& i ,const  int& j) const {
        return board[i][j];
    }

    void displayGame (sf::RenderWindow&);

    int getNumber_of_turns() const {
        return number_of_turns;
    }

    void incrNumberOfTurns() {
        ++ number_of_turns;
    }

    void setBoard (const int& from_x,const int& from_y,
                   const int& to_x , const int& to_y);
    bool isGame() const {
        return game;
    }

    void setGame(bool game) {
        Board::game = game;
    }
    Player_side getWinner() const {
        return winner;
    }

    void setWinner(Player_side winner) {
        Board::winner = winner;
    }

    const sf::Sprite &getSprite_board() const {
        return sprite_board;
    }



};


#endif //CHESS_GAME_BOARD_H
