#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

const int window_width = 589;
const int window_height = 589;





int main() {

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JChess");
    sf::Event event;
    Board my_board;
    Player lhs(Player_side::LEFT);

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            lhs.choice_of_action(my_board,window);
            switch (event.type)
            {
                case sf::Event:: Closed:
                    window.close();
                    break;
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