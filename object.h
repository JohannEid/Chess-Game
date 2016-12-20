//
// Created by johann on 20/12/16.
//

#ifndef CHESS_GAME_OBJECT_H
#define CHESS_GAME_OBJECT_H

#include "Header.h"

class Board;

enum class Player_side {
    RIGHT,
    LEFT,
    NONE
};


class Object {
private:
    char widget = 'o';
    Player_side side = Player_side::NONE;


public:

    Object(char widget, Player_side side) : widget(widget), side(side) {}

    void display() {
        std::cout << getWidget() << " ";
    }

    char getWidget() const {
        return widget;
    }

    void setWidget(char widget) {
        Object::widget = widget;
    }

    Player_side getSide() const {
        return side;
    }

    void setSide(Player_side side) {
        Object::side = side;
    }


};

class Pawn : public Object {
private:
    bool on_board = true;


public:
    virtual ~Pawn() {}

    Pawn(Player_side side, char widget = 'P') : Object(widget, side), on_board(true) {}

    bool isOn_board() const {
        return on_board;
    }

    void setOn_board(bool on_board) {
        Pawn::on_board = on_board;
    }

    virtual void move(Board &);

};

class Tower : public Pawn {
public:

    Tower(Player_side side) : Pawn(side, 'T') {}

    void move(Board &);
};

class Knight : public Pawn {
public:
    Knight(Player_side side) : Pawn(side, 'N') {}

    void move(Board &);
};

class Crazy : public Pawn {
public:
    Crazy(Player_side side) : Pawn(side, 'C') {}

    void move(Board &);
};

class Queen : public Pawn {
public:
    Queen(Player_side side) : Pawn(side, 'Q') {}

    void move(Board &);
};

class King : public Pawn {
public:
    King(Player_side side) : Pawn(side, 'K') {}

    void move(Board &);
};


#endif //CHESS_GAME_OBJECT_H
