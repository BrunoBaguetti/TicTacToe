#include "TicTacToe.h"
#include <iostream>

int main(int arc, char **argv)
{
    TicTacToe game{};
    std::cout << "Tic Tac Toe Game" << std::endl;
    std::cout << "\nChoose number between 1..9 to play" << std::endl;

    while (game.getGameState() != TicTacToe::GameState::ENDED)
    {
        game.makeMove();
    }
}
