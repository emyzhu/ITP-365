#pragma once

#include "tttgamedata.h"

class TicTacToeGame
{
public:
	// Function: Constructor
	// Purpose: Creates an "empty board" in currentState -- 
	// A 3x3 grid of "empty" square states
	// Input: None
	// Returns: Nothing
	TicTacToeGame();

	// Function: getBoard
	// Purpose: Getter for the currentState member variable
	// Input: None
	// Returns: A GameState
	GameState getBoard() const;

	// Function: setSquareState
	// Purpose: Sets the position (indicated by row and col) to
	// the indicated SquareState
	// Input: 2 integers representing the row/column to set
	//		A square state to set the r/c to
	// Returns: True to indicate the state was set successfully
	bool setSquareState(unsigned short row, unsigned short col, GameState::SquareState state);

	// Function: setSquareState
	// Purpose: Sets the position (indicated by the square number) to
	// the indicated SquareState
	// Input: An integer indicating the square number (upper left is #1)
	//		A square state to set square to
	// Returns: True to indicate the state was set successfully
	bool setSquareState(unsigned short square, GameState::SquareState state);

	// Function: getBoard
	// Purpose: Determines if there's a winner and returns the symbol
	// Input: None
	// Returns: 'X' to indicate X wins
	//			'O' to indicate O wins
	//			'N' to indicate tie game
	//			' ' to indicate no winner yet
	char getWinner();

private:
	// The current game state
	GameState currentState;
};

