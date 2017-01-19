//
// Created by johann on 20/12/16.
//

#include "Board.h"
#include "object.h"


const int raw_pawn_lhs = 1;
const int raw_pawn_rhs = 6;


Board::Board() {

    int top{6};
    sf::Texture texture_figure;
    sf::Texture texture_board;
    sf::IntRect sprite_size_pawn = sf::IntRect(294, top, 28, 50);
    std::vector<char> names{'T', 'N', 'C', 'K', 'Q', 'C', 'N', 'T'};
    std::vector<sf::IntRect> sprite_sizes{sf::IntRect(8, top, 40, 52), sf::IntRect(62, top, 44, 55),
                                          sf::IntRect(114, top, 52, 53), sf::IntRect(170, top, 52, 55),
                                          sf::IntRect(227, top, 50, 53), sf::IntRect(8, top, 40, 52),
                                          sf::IntRect(62, top, 44, 55),
                                          sf::IntRect(114, top, 52, 53)};
    assert (texture_figure.loadFromFile("sprites/figures.png"));
    assert (texture_board.loadFromFile("sprites/board.jpg"));
    sprite_board.setTexture(texture_board);
    for (int j{0}; j < board_width; ++j) {
        board.push_back(std::vector<std::unique_ptr<Object>>());
        for (int i{0}; i < board_height; ++i) {
            switch (j) {
                case 0:

                    board[j] .push_back(std::move(createPawn(Player_side::LEFT, names[i]))) ;
                    board[j][i]->setSprite(texture_figure, sprite_sizes[i]);
                    break;


                case 1:

                    board[j] .push_back(std::move (createPawn(Player_side::LEFT, 'P'))) ;
                    board[j][i]->setSprite(texture_figure, sprite_size_pawn);
                    break;
                case 6:

                    top = 62;
                    board[j].push_back( std::move (createPawn(Player_side::RIGHT, 'P')));
                    board[j][i]->setSprite(texture_figure, sprite_size_pawn);
                    break;
                case 7:
                    top = 62;
                    board[j].push_back( std::move (createPawn(Player_side::RIGHT, names[i])));
                    board[j][i]->setSprite(texture_figure, sprite_sizes[i]);
                    break;


                default:
                    board[j].push_back(std::move (std::make_unique<Object>())) ;

            }
        }

    }


}

void Board::displayGame(sf::RenderWindow &window) {
    //window.draw(getSprite_board());
    for (int i{0}; i < board_width; ++i) {
        for (int j{0}; j < board_width; ++j) {
            if (getBoard(i, j)->getName() != "empty") { window.draw(getBoard(i, j)->getSprite_figure());
            std::cout << "yoyo";}}
    }
}


bool Board::isNewQueen(const int &from_x, const int &from_y, const int &to_x,
                       const int &to_y) {
    if ((board[from_x][from_y]->getName() == "Pawn") &&
        (((board[from_x][from_y]->getSide() == Player_side::RIGHT)
          && (to_x == 0)) || ((board[from_x][from_y]->getSide() == Player_side::LEFT)
                              && (to_x == board_width - 1)))) { return true; }
    else { return false; }

}

void Board::winGame(const int &from_x, const int &from_y, const int &to_x,
                    const int &to_y) {
    if (getBoard(to_x, to_y)->getName() == "King")
        setGame(false);
    setWinner(getBoard(from_x, from_y)->getSide());
}

void Board::setBoard(const int &from_x, const int &from_y, const int &to_x,
                     const int &to_y) {

    if (isNewQueen(from_x, from_y, to_x, to_y)) {
        board[from_x][from_y] = std::make_unique<Queen>(getBoard(from_x, from_y)->getSide());
    }
    board[to_x][to_y] = std::move(board[from_x][from_y]);
    board[from_x][from_y] = std::move(std::make_unique<Object>());
}


std::unique_ptr<Object> Board::createPawn(const Player_side &side, const char &name) {
    switch (name) {
        case 'P':
            return std::make_unique<Pawn>(side);
        case 'T':
            return std::make_unique<Tower>(side);
        case 'C':
            return std::make_unique<Crazy>(side);
        case 'N':
            return std::make_unique<Knight>(side);
        case 'K':
            return std::make_unique<King>(side);
        case 'Q':
            return std::make_unique<Queen>(side);
    }

}

/*
void Board::initBoard() {
    int j {0};
    int top{6};
    sf::Texture texture_figure;
    sf::IntRect sprite_size_pawn = sf::IntRect(294, top, 28, 50);
    std::vector<char> names{'T', 'N', 'C', 'K', 'Q', 'C', 'N', 'T'};
    std::vector<sf::IntRect> sprite_sizes{sf::IntRect(8, top, 40, 52), sf::IntRect(62, top, 44, 55),
                                          sf::IntRect(114, top, 52, 53), sf::IntRect(170, top, 52, 55),
                                          sf::IntRect(227, top, 50, 53), sf::IntRect(8, top, 40, 52),
                                          sf::IntRect(62, top, 44, 55),
                                          sf::IntRect(114, top, 52, 53)};
    assert (texture_figure.loadFromFile("sprites/board.jpg"));


    for (int i{0}; i < board_width; i++) {
        j=0;
        board[j][i] = createPawn(Player_side::LEFT, names[i]);
        board[j][i]->setSprite(texture_figure, sprite_sizes[i]);
    }
    for (int i{0}; i < board_width; i++) {
        j=1;
        board[j][i] = createPawn(Player_side::LEFT, 'P');
        board[j][i]->setSprite(texture_figure, sprite_size_pawn);
    }
    top = 62;
    for (int i{0}; i < board_width; i++) {
        j=6;
        board[j][i] = createPawn(Player_side::RIGHT, 'P');
        board[j][i]->setSprite(texture_figure, sprite_size_pawn );
    }
    for (int i{0}; i < board_width; i++) {
        j=7;
        board[j][i] = createPawn(Player_side::RIGHT, names[i]);
        board[j][i]->setSprite(texture_figure, sprite_sizes[i]);
    }

}
 */
