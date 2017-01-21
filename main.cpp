#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"
#include "common.h"
#include "engine.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int window_width = 589;
const int window_height = 589;


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JChess");
    sf::Event event;
    //starting main music
    Audio my_audio("sounds/satie_je_te_veux.wav", "sounds/redneck_roll_dice.wav");
    my_audio.playMusic();
    bool isNewGame{false};
    int index_to_play{0};
    bool is_move{false};
    int x_from{0};
    int y_from{0};
    int x_to{0};
    int y_to{0};
    std::vector<std::pair<int, int>> my_moves;
    std::pair<int, int> target_coordinates;
    std::pair<int, int> target_coordinates_move;
    Board my_board;
    std::vector<Player> my_players = {Player_side::LEFT, Player_side::RIGHT};
    //start of game loop
    while (window.isOpen()) {
        if (isNewGame) {
            my_board = Board();
            my_players[0] = Player(Player_side::LEFT);
            my_players[1] = Player(Player_side::RIGHT);
            isNewGame = false;
        }

        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:

                    if ((event.key.code == sf::Mouse::Left) && (!is_move)) {
                        // we have a pawn which is on side of player whose it is turn
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
                        } else {
                            // bad pawn selection
                            std::cout << "Please select a valid pawn" << std::endl;
                        }
                    } else if ((event.key.code == sf::Mouse::Left) && (is_move)) {
                        // now that we selected valid pawn we can choose spot to move into


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
                        //deselect pawn
                    else if ((event.key.code == sf::Mouse::Right) && (is_move)) {
                        is_move = false;
                    }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || (!my_board.isGame())) {
                isNewGame = true;
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

