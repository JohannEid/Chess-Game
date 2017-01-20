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
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if ((event.key.code == sf::Mouse::Left) && (is_move)) {
                        std::pair<int, int> target_coordinates_move{moveSelection(my_board, window)};

                        changeSideToPlay(index_to_play);


                    }
                    if (event.key.code == sf::Mouse::Left) {
                        std::pair<int, int> target_coordinates{pawnSelection(my_board, window)};
                        if (target_coordinates != std::make_pair(88, 88)) {
                            if ( my_players[index_to_play].getSide() == my_board.getBoard
                                    (target_coordinates.first, target_coordinates.second)->getSide()) {
                                {
                                    my_players[index_to_play].choice_of_action(my_board, window, target_coordinates);
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