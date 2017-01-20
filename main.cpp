#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"
#include "common.h"
#include <SFML/Graphics.hpp>

const int window_width = 589;
const int window_height = 589;


int main() {

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
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if ((event.key.code == sf::Mouse::Left) && (is_move)) {


                        changeSideToPlay(index_to_play);


                    }
                    if (event.key.code == sf::Mouse::Left) {
                        std::pair<int, int> target_coordinates{pawnSelection(my_board, window)};
                        if (target_coordinates != std::make_pair(88, 88)) {
                            x_from = target_coordinates.first;
                            y_from = target_coordinates.second;

                            if (my_players[index_to_play].getSide() == my_board.getBoard
                                    (x_from, y_from)->getSide())
                                // we have a pawn which is on side of player whose it is turn
                            {
                                {
                                    // now we want to select coordinates where to move
                                    while ((0 <= x_to < board_width) && (0 <= y_to < board_height)) {

                                        if (event.type == sf::Mouse::Left) {


                                            std::pair<int, int> target_coordinates_move{
                                                    moveSelection(my_board, window)};
                                            x_to = target_coordinates_move.first;
                                            y_to = target_coordinates_move.second;

                                            my_board.getBoard(x_from, y_from)->
                                                    move(my_board, x_from, y_from, x_to, y_to);

                                        }

                                    }


                                }

                            }
                        } else {
                            std::cout << "Please select a valid pawn" << std::endl;
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