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
    Player lhs(Player_side::LEFT);
    Player rhs(Player_side::RIGHT);
    Player_side side_to_play{Player_side::LEFT};
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.key.code == sf::Mouse::Left) {
                        std::pair<int, int> target_coordinates{pawnSelection(my_board, window)};
                        if (target_coordinates != std::make_pair(88, 88)) {
                            if (side_to_play == my_board.getBoard
                                    (target_coordinates.first, target_coordinates.second)->getSide()) {
                                if (side_to_play == Player_side::LEFT) {
                                    lhs.choice_of_action(my_board, window, target_coordinates);
                                } else if (side_to_play == Player_side::RIGHT) {
                                    rhs.choice_of_action(my_board, window, target_coordinates);
                                }
                                changeSideToPlay(side_to_play);

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