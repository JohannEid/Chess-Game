//
// Created by johann on 21/01/17.
//

#ifndef CHESS_GAME_ENGINE_H
#define CHESS_GAME_ENGINE_H
#include "Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Audio {
private:
    sf::Music background_music;
    sf::SoundBuffer buffer_roll_dice;
    sf::Sound sound_roll_dice;


public:
    Audio (const std::string&,const std::string&);
    void playMusic();
    void playSoundEffet();





};


#endif //CHESS_GAME_ENGINE_H
