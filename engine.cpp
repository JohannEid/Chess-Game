//
// Created by johann on 21/01/17.
//

#include "engine.h"

Audio::Audio(const std::string& background_music_file, const std::string & buffer_roll_dice_file) {

    assert(background_music.openFromFile(background_music_file));
    assert(buffer_roll_dice.loadFromFile(buffer_roll_dice_file));
    sound_roll_dice.setBuffer(buffer_roll_dice);

}

void Audio::playMusic() {
        background_music.play();
        background_music.setLoop(true);
}
void Audio::playSoundEffet()
{
    sound_roll_dice.play();
}
