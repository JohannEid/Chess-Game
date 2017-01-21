//
// Created by johann on 21/01/17.
//

#include "engine.h"
#include "common.h"

 void Audio ::createAudio(const std::string &background_music_file, const std::string &buffer_roll_dice_file){

    assert(background_music.openFromFile(background_music_file));
    assert(buffer_roll_dice.loadFromFile(buffer_roll_dice_file));
    sound_roll_dice.setBuffer(buffer_roll_dice);

}

void Audio::playMusic() {
    background_music.play();
    background_music.setLoop(true);
}

void Audio::playSoundEffet() {
    sound_roll_dice.play();
}


void GameEngine::run() {
    my_audio.playMusic();
    while (window.isOpen()) {
        while (window.pollEvent(event)) {


            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {


                if ((event.key.code == sf::Mouse::Left) && (!is_move)) {
                    pawnSelectionEvent();
                } else if ((event.key.code == sf::Mouse::Left) && (is_move)) {
                    pawnMoveEvent();

                } else if ((event.key.code == sf::Mouse::Right) && (is_move)) {
                    is_move = false;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || (!my_board.isGame())) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear();
        my_board.relocateEntities();
        my_board.displayGame(window);
        window.display();
    }
}

void GameEngine::pawnSelectionEvent() {

    target_coordinates = pawnSelection(my_board, window, my_players[index_to_play].getSide());
    if (target_coordinates != std::make_pair(88, 88)) {
        x_from = target_coordinates.first;
        y_from = target_coordinates.second;
        my_moves = my_board.getBoard(x_from, y_from)->
                getMovePossibilites(my_board, x_from, y_from);
        my_board.getBoard(x_from, y_from)->
                displayMovePossibilities(my_moves);
        is_move = true;
         my_audio.playSoundEffet();

    }
}

void GameEngine::pawnMoveEvent() {
    target_coordinates_move = moveSelection(my_board, window);
    x_to = target_coordinates_move.first;
    y_to = target_coordinates_move.second;

    if (my_board.getBoard(x_from, y_from)->
            move(my_board, x_from, y_from,
                 x_to, y_to, my_moves)) {
        changeSideToPlay(index_to_play);
        is_move = false;
    }
}


GameEngine::GameEngine() {
    window.create(sf::VideoMode(window_width, window_height), "JChess");
     my_audio.createAudio("sounds/satie_je_te_veux.wav", "sounds/redneck_roll_dice.wav");
}





