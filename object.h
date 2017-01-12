//
// Created by johann on 20/12/16.
//

#ifndef CHESS_GAME_OBJECT_H
#define CHESS_GAME_OBJECT_H
#include "Header.h"
const int left_pawn_starting = 1;
const int right_pawn_starting = 1;

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
    const char  sideToChar();


public:
    virtual ~Object() {}

    explicit Object() {}


    explicit Object(char widget, Player_side side, std::string name) :
            widget(widget), side(side), name(name) {}

    void display() {
        std::cout << getWidget() << sideToChar() <<" ";
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

    virtual void move(Board &, const int &x, const int &y);


};

using pointer_to_object= std::unique_ptr<Object>  ;


class Pawn : public Object {
private:
     int sideToDirection();
    virtual const std::vector < std::pair <int,int >> getMovePossibilites(const Board&,const int& x , const int& y);
    void displayMovePossibilities (const std::vector <std::pair<int,int>> &);
    const std::pair <int,int> selectPositionToMove (const std::vector<std::pair<int,int>>& );



public:

    Pawn(Player_side side, char widget = 'P', std::string name = "Pawn") : Object(widget, side, name) {}

    void move(Board &, const int &x, const int &y);

};

class Tower : public Pawn {
public:

    Tower(Player_side side) : Pawn(side, 'T', "Tower") {}

    void move(Board &, const int &x, const int &y);
};

class Knight : public Pawn {
public:
    Knight(Player_side side) : Pawn(side, 'N', "Knight") {}

    void move(Board &, const int &x, const int &y);
};

class Crazy : public Pawn {
public:
    Crazy(Player_side side) : Pawn(side, 'C', "Crazy") {}

    void move(Board &, const int &x, const int &y);
};

class Queen : public Pawn {
public:
    Queen(Player_side side) : Pawn(side, 'Q', "Queen") {}

    void move(Board &, const int &x, const int &y);
};

class King : public Pawn {
public:
    King(Player_side side) : Pawn(side, 'K', "King") {}

    void move(Board &, const int &x, const int &y);
};


#endif //CHESS_GAME_OBJECT_H
