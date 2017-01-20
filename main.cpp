#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"
#include "common.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int window_width = 589;
const int window_height = 589;


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JChess");

    sf::Event event;
    Board my_board;
    std::vector<Player> my_players = {Player_side::LEFT, Player_side::RIGHT};
    int index_to_play{0};
    bool is_move{false};
    int x_from{0};
    int y_from{0};
    int x_to{0};
    int y_to{0};
    std::vector<std::pair<int, int>> my_moves;
    std::pair<int, int> target_coordinates;
    std::pair<int, int> target_coordinates_move;
    //starting main music
    sf::Music background_music;
    assert(background_music.openFromFile("sounds/satie_je_te_veux.wav"));
    playMusic(background_music);
    //loading sound effect
    sf::SoundBuffer buffer_roll_dice;
    assert(buffer_roll_dice.loadFromFile("sounds/redneck_roll_dice.wav"));
    sf::Sound sound_roll_dice;
    sound_roll_dice.setBuffer(buffer_roll_dice);
    //start of game loop
    while (window.isOpen()) {
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
                            sound_roll_dice.play();

                            is_move = true;
                        } else {
                            // bad pawn selection
                            std::cout << "Please select a valid pawn" << std::endl;
                        }
                    } else if ((event.key.code == sf::Mouse::Left) && (is_move)) {
                        // now that we selected valid pawn we can choose spot to move into


                        target_coordinates_move = moveSelection(my_board, window);
                        x_to = target_coordinates_move.first;
                        y_to = target_coordinates_move.second;
                        std::cout << x_to << std::endl;
                        std::cout << y_to << std::endl;


                        if (my_board.getBoard(x_from, y_from)->
                                move(my_board, x_from, y_from,
                                     x_to, y_to, my_moves)) {
                            changeSideToPlay(index_to_play);
                            is_move = false;
                        }

                    }


            }


        }

        window.clear();
        my_board.relocateEntities();
        my_board.displayGame(window);
        window.display();

    }


}




/*

   Player rhs (Player_side::RIGHT);
   std::string name_of_winner{" "};
   Board my_board;
   while (my_board.isGame()) {
       my_board.incrNumberOfTurns();
       my_board.display();
       my_board.display();
       rhs.choice_of_action(my_board);
       my_board.display();
   }
   (my_board.getWinner()== Player_side::LEFT)?  name_of_winner = lhs.getName() : rhs.getName();
   std::cout << "Congratulation" << name_of_winner << "wins !! "<<std::endl;

   return 0;
    */