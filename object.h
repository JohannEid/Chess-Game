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
    std::string name = "empty";
    Player_side side = Player_side::NONE;


public:

    explicit Object() {}

    Object(const Object &) = delete;

    Object &operator=(const Object &) = delete;

    ~Object() = default;


    explicit Object(char widget, Player_side side,std::string name) :
            Object :: widget(widget), Object :: side(side),Object :: name(name) {}

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

    const std::string &getName() const {
        return name;
    }


};

class Pawn : public Object {
private:


public:
    virtual ~Pawn() {}

    Pawn(Player_side side, char widget = 'P',std::string name = "Pawn") : Object(widget, side,name) {}

    virtual void move(Board &);

};

class Tower : public Pawn {
public:

    Tower(Player_side side) : Pawn(side, 'T',"Tower") {}

    void move(Board &);
};

class Knight : public Pawn {
public:
    Knight(Player_side side) : Pawn(side, 'N',"Knight") {}

    void move(Board &);
};

class Crazy : public Pawn {
public:
    Crazy(Player_side side) : Pawn(side, 'C',"Crazy") {}

    void move(Board &);
};

class Queen : public Pawn {
public:
    Queen(Player_side side) : Pawn(side, 'Q',"Queen") {}

    void move(Board &);
};

class King : public Pawn {
public:
    King(Player_side side) : Pawn(side, 'K',"King") {}

    void move(Board &);
};


#endif //CHESS_GAME_OBJECT_H
