#include "Header.h"
#include "object.h"
#include "Board.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

const int window_width = 1024;
const int window_height = 768;





int main() {
sf::Sprite s_sprites[32];

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JChess");
    sf::Event event;
    Board my_board;
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event:: Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        window.display();

    }

}




/*

   Player lhs(Player_side::LEFT);
   Player rhs (Player_side::RIGHT);
   std::string name_of_winner{" "};
   Board my_board;
   while (my_board.isGame()) {
       my_board.incrNumberOfTurns();
       my_board.display();
       lhs.choice_of_action(my_board);
       my_board.display();
       rhs.choice_of_action(my_board);
       my_board.display();
   }
   (my_board.getWinner()== Player_side::LEFT)?  name_of_winner = lhs.getName() : rhs.getName();
   std::cout << "Congratulation" << name_of_winner << "wins !! "<<std::endl;

   return 0;
    */