#include <map>
#include "Game.h"

/*
Implementation of the TicTacToe Game class.
*/

TicTacToe::TicTacToe() {
	/*
	Default Constructor.
	*/

	int length = sizeof(gameState) / sizeof(gameState[0]);
	for (int i = 0; i < length; i++) {
		gameState[i] = 0;
	}
	turnsLeft = 9;
}

TicTacToe::TicTacToe(int state[]) {
	/*
	Overloaded Constructor, with input state array directly obtained from the user.
	*/

	int zeroCount = 0;
	for (int i = 0; i < 9; i++) {
		gameState[i] = state[i];
		if (state[i] == 0) {
			zeroCount++;
		}
		else if (state[i] == 1) {
			trackX.push_back(i);
		}
		else {
			trackO.push_back(i);
		}
	}
	turnsLeft = zeroCount;
}

int* TicTacToe::getGameState() {
	/*
	Method to return the state of the game. For debugging and testing.
	*/

	return gameState;
}

bool TicTacToe::isValidMove(int index) {
	/*
	Method to check if the user entered move (input index 1 - 9) is valid or not.
	Input: index
	*/

	if (index >= 0 && index < 9 && gameState[index] == 0) {
		std::cout << "Valid Move!" << std::endl;
		return true;
	}
	else {
		std::cout << "Invalid Move! Please enter again." << std::endl;
		return false;
	}
}

bool TicTacToe::isWinner(char player) {
	/*
	Method to check if the given player has won or not.
	Input: Player Character ('X' or 'O')
	*/

	int flag = (player == 'X') ? 1 : -1;
	
	for (int i = 0; i < 3; i++) {
		// row wise check
		if (gameState[3*i] + gameState[(3*i)+1] + gameState[(3*i)+2] == flag * 3) {
			return true;
		}

		// column wise check
		else if (gameState[i] + gameState[i + 3] + gameState[i + 6] == flag * 3) {
			return true;
		}
	}

	// diagonal check
	if (gameState[0] + gameState[4] + gameState[8] == flag * 3 ||
		gameState[2] + gameState[4] + gameState[6] == flag * 3) {
		return true;
	}

	return false;
}

void TicTacToe::displayGame() {
	/*
	Method to display the game board with player moves. For debugging and testing.
	*/

	std::map<int, char> playerMap = { {-1, 'O'}, {1, 'X'}, {0, ' '}};

	std::cout << " ___ ___ ___" << std::endl;
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) {
			std::cout << "| ";
		}
		std::cout << playerMap[gameState[i]];
		if (i % 3 == 2) {
			std::cout << " |";
			std::cout << std::endl << "|___|___|___|" << std::endl;
		}
		else {
			std::cout << " | ";
		}
	}
}

std::vector<int> TicTacToe::trackPlayer(char player) {	
	/*
	Method to track the player moves and return them.
	Input: Player Character ('X' or 'O')
	*/

	if (player == 'X') {
		return trackX;
	}
	else {
		return trackO;
	}
}

bool TicTacToe::gameOver() {
	/*
	Method to check if the game is completed or not.
	Game Over:
		Case 1: Player X Won
		Case 2: Player O Won
		Case 3: Game ended in a draw
	Game Not Over:
		Case 4: Some more moves left and nobody has won yet
	*/

	if (isWinner('X')) {
		std::cout << std::endl;
		std::cout << "**** Player X has won! ****" << std::endl;
		return true;
	}

	else if (isWinner('O')) {
		std::cout << std::endl;
		std::cout << "**** Player O has won! ****" << std::endl;
		return true;
	}

	if (turnsLeft == 0) {
		std::cout << std::endl;
		std::cout << "**** Game ended in a Draw! ****" << std::endl;
		return true;
	}

	return false;
}

bool TicTacToe::move(int index, int playerFlag) {
	/*
	Method to enable the players to play (to mark X's and O's on the board).
	
	Input: Index
		   Player notation (1: Player X, -1: Player O)
	*/

	if (isValidMove(index)) {
		gameState[index] = playerFlag;
		turnsLeft--;
		if (playerFlag == 1) { 
			trackX.push_back(index); 
		}
		else { 
			trackO.push_back(index); 
		}
		return true;
	}
}