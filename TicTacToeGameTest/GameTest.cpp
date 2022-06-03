#include "pch.h"
#include "../TicTacToeGame/Game.cpp"

/*
Test Cases for all the methods in Game Class.
*/

TEST(GameStateTest, DefaultTest) {
	/*
	Testing the default initialization of the Game, i.e, all zeros.
	*/

	TicTacToe gameTest;
	int* initState = gameTest.getGameState();

	for (int i = 0; i < 9; i++) {
		EXPECT_EQ(initState[i], 0);
	}
}

TEST(GameStateTest, UserTest) {
	/*
	Testing the user initialization of the Game.
	*/

	int userState[9] = {1, -1, -1, 0, 1, 0, 0, 0, 1};
	TicTacToe gameTest = TicTacToe(userState);
	int* initState = gameTest.getGameState();
	
	EXPECT_EQ(initState[0], 1);
	EXPECT_EQ(initState[4], 1);
	EXPECT_EQ(initState[8], 1);
	EXPECT_EQ(initState[1], -1);
	EXPECT_EQ(initState[2], -1);
	EXPECT_EQ(initState[3], 0);
}

TEST(GameMoveValidityTest, ValidMove) {
	/*
	Testing few cases of valid moves in the game.
	*/

	TicTacToe gameTest;

	EXPECT_TRUE(gameTest.isValidMove(0));
	EXPECT_TRUE(gameTest.isValidMove(8));
}

TEST(GameMoveValidityTest, InvalidMove) {
	/*
	Testing few cases of invalid moves in the game.
	*/

	TicTacToe gameTest;

	gameTest.move(0, 1);

	EXPECT_FALSE(gameTest.isValidMove(0));
	EXPECT_FALSE(gameTest.isValidMove(10));
}
TEST(GameMoveTest, ValidMove) {
	/*
	Test to ensure the user move worked for both the players.
	*/

	TicTacToe gameTest;

	EXPECT_TRUE(gameTest.move(0, 1));
	EXPECT_TRUE(gameTest.move(8, -1));
}

TEST(GameMoveTest, InvalidMove) {
	/*
	Test to ensure the user move failed for both the players.
	*/

	TicTacToe gameTest;

	gameTest.move(0, 1);
	EXPECT_FALSE(gameTest.move(0, 1));
	EXPECT_FALSE(gameTest.move(0, -1));
}

TEST(WinnerTest, WinnerX) {
	/*
	Test to check the winning of Player X.

	Configuration: Player X Winning.
	 ___ ___ ___
	| X | O | O |
	|___|___|___|
	|   | X |   |
	|___|___|___|
	|   |   | X |
	|___|___|___|

	*/

	int userState[9] = { 1, -1, -1, 0, 1, 0, 0, 0, 1 };
	TicTacToe gameTest = TicTacToe(userState);

	EXPECT_TRUE(gameTest.isWinner('X'));
	EXPECT_FALSE(gameTest.isWinner('O'));
}

TEST(WinnerTest, WinnerO) {
	/*
	Test to check the winning of Player O.
	
	Configuration: Player O Winning.
	 ___ ___ ___
	| O | X | X |
	|___|___|___|
	| X | O |   |
	|___|___|___|
	|   |   | O |
	|___|___|___|

	*/

	int userState[9] = { -1, 1, 1, 1, -1, 0, 0, 0, -1 };
	TicTacToe gameTest = TicTacToe(userState);

	EXPECT_TRUE(gameTest.isWinner('O'));
	EXPECT_FALSE(gameTest.isWinner('X'));
}

TEST(GameOverTest, DrawGame) {
	/*
	Test to check the drawing of game.

	Configuration: Game ends in a Draw.
	 ___ ___ ___
	| X | O | X |
	|___|___|___|
	| X | X | O |
	|___|___|___|
	| O | X | O |
	|___|___|___|

	*/

	int userState[9] = { 1, -1, 1, 1, 1, -1, -1, 1, -1 };
	TicTacToe gameTest = TicTacToe(userState);

	EXPECT_FALSE(gameTest.isWinner('X'));
	EXPECT_FALSE(gameTest.isWinner('O'));
	EXPECT_TRUE(gameTest.gameOver());
}

TEST(GameOverTest, WinnerX) {
	/*
	Test to check game completion with player X winning.

	Configuration: Player X Winning.
	 ___ ___ ___
	| X | O | O |
	|___|___|___|
	|   | X |   |
	|___|___|___|
	|   |   | X |
	|___|___|___|

	*/

	int userState[9] = { 1, -1, -1, 0, 1, 0, 0, 0, 1 };
	TicTacToe gameTest = TicTacToe(userState);

	EXPECT_TRUE(gameTest.isWinner('X'));
	EXPECT_TRUE(gameTest.gameOver());
}

TEST(GameOverTest, WinnerO) {
	/*
	Test to check game completion with player O winning.

	Configuration: Player O Winning.
	 ___ ___ ___
	| O | X | X |
	|___|___|___|
	| X | O |   |
	|___|___|___|
	|   |   | O |
	|___|___|___|

	*/

	int userState[9] = { -1, 1, 1, 1, -1, 0, 0, 0, -1 };
	TicTacToe gameTest = TicTacToe(userState);

	EXPECT_TRUE(gameTest.isWinner('O'));
	EXPECT_TRUE(gameTest.gameOver());
}

TEST(TrackPlayerTest, TrackX) {
	/*
	Test to track player X's moves.

	Configuration: Tracking X.
	 ___ ___ ___
	| O | X | X |
	|___|___|___|
	| X | O |   |
	|___|___|___|
	|   |   | O |
	|___|___|___|

	*/

	int userState[9] = { -1, 1, 1, 1, -1, 0, 0, 0, -1 };
	TicTacToe gameTest = TicTacToe(userState);

	std::vector<int> indicesX = {1, 2, 3};

	EXPECT_EQ(gameTest.trackPlayer('X'), indicesX);
}

TEST(TrackPlayerTest, TrackO) {
	/*
	Test to track player O's moves.
	
	Configuration: Tracking X.
	 ___ ___ ___
	| O | X | X |
	|___|___|___|
	| X | O |   |
	|___|___|___|
	|   |   | O |
	|___|___|___|

	*/

	int userState[9] = { -1, 1, 1, 1, -1, 0, 0, 0, -1 };
	TicTacToe gameTest = TicTacToe(userState);

	std::vector<int> indicesO = {0, 4, 8};

	EXPECT_EQ(gameTest.trackPlayer('O'), indicesO);
}