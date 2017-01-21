//
// Created by johann on 21/01/17.
//

#ifndef CHESS_GAME_ENGINE_H
#define CHESS_GAME_ENGINE_H

#include "Header.h"
#include "Board.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int window_width = 589;
const int window_height = 589;


class Audio {
private:
    sf::Music background_music;
    sf::SoundBuffer buffer_roll_dice;
    sf::Sound sound_roll_dice;


public:
    Audio(const std::string &, const std::string &);

    void playMusic();

    void playSoundEffet();
};

class GameEvent
{
private:
    int index_to_play {0};
    int x_from{0};
    int y_from{0};
    int x_to{0};
    int y_to{0};
    std::vector<std::pair<int, int>> my_moves;
    std::pair<int, int> target_coordinates;
    std::pair<int, int> target_coordinates_move;

public:


};

class GameEngine {
private:
    int index_to_play{0};
    bool is_move{false};
    int x_from{0};
    int y_from{0};
    int x_to{0};
    int y_to{0};
    std::vector<std::pair<int, int>> my_moves;
    std::pair<int, int> target_coordinates;
    std::pair<int, int> target_coordinates_move;
    sf::Event event;
    Board my_board;
    std::vector<Player> my_players = {Player_side::LEFT, Player_side::RIGHT};
    sf::RenderWindow window ;
   // Audio my_audio;

public:
    GameEngine();

    void run ();

    void pawnSelectionEvent();

    void pawnMoveEvent();



    bool isMove() const {
        return is_move;
    }


};



#endif //CHESS_GAME_ENGINE_H
