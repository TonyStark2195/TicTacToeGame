#pragma once

#include <iostream>
#include <vector>

/*
Class definition for TicTacToe Game.
*/

class TicTacToe
{
	int gameState[9];			// maintaining the game state
	int turnsLeft;				// track how many turns left in the game
	std::vector<int> trackX;	// track player X's moves
	std::vector<int> trackO;	// track player O's moves

public:
	// Constructors
	TicTacToe();
	TicTacToe(int state[]);

	// API like get Methods
	int* getGameState();
	void displayGame();
	std::vector<int> trackPlayer(char player);

	// User Interaction Methods, API like put/post methods
	bool move(int index, int playerFlag);

	// Program termination method
	bool gameOver();

	// Internal logic validation methods
	bool isValidMove(int index);
	bool isWinner(char player);
};