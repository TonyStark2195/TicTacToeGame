// TicTacToeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include <stdlib.h>

int main()
{
    TicTacToe game;

    bool flag = true;   // Flag to denote which player's turn. X: true, O: false
    char playerTag;     // Denote the player itself. 'X' is default
    int playerFlag;     // Numeric Flag to denote which player's turn. X: 1, O: -1

    int displayFlag;    // To display the game board or not
    int input;          // User input for the position on the board

    std::cout << "Welcome to the Tic Tac Toe Game!" << std::endl;
    std::cout << "Player X vs Player O" << std::endl;
    std::cout << "Player X goes first!" << std::endl;
    std::cout << "*************************************\n";

    std::cout << " ___ ___ ___" << std::endl;
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            std::cout << "| ";
        }
        std::cout << i+1;
        if (i % 3 == 2) {
            std::cout << " |";
            std::cout << std::endl << "|___|___|___|" << std::endl;
        }
        else {
            std::cout << " | ";
        }
    }

    std::cout << "\n*************************************\n";

    std::cout << "display required? (Yes - 1 / No - 0)" << std::endl;
    std::cin >> displayFlag;

    while (!game.gameOver()) {

        playerFlag = flag ? 1 : -1;
        playerTag = flag ? 'X' : 'O';

        std::cout << "Player " << playerTag <<"'s Turn - Enter index 1 - 9: " << std::endl;
        std::cin >> input;

        
        if (game.move(input - 1, playerFlag)) {     // input - 1, to match human convention to that of program's

            flag = !flag;       // alternate player turns
            system("cls");

            if (displayFlag) { 
                game.displayGame(); 
            }
        }

        else
        {
            continue;
        }
    }

    std::cout << "Final Game Board: \n";
    game.displayGame();
    system("pause");
}