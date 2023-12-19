#include "tttgame.h"
#include "tttgameai.h"

TicTacToeGame::TicTacToeGame()
{
    //nested for loop goes through every spot of the grid, setting each to empty game state
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            currentState.mBoard[r][c] = GameState::Empty;
        }
    }
}

GameState TicTacToeGame::getBoard() const
{
	return currentState;
}


bool TicTacToeGame::setSquareState(unsigned short row, unsigned short col, GameState::SquareState state)
{
    if (currentState.mBoard[row][col] == GameState::Empty) {
        currentState.mBoard[row][col] = state;
        return true;
    }
    
	return false;
}

bool TicTacToeGame::setSquareState(unsigned short square, GameState::SquareState state)
{
    //mathematical formulas allow for conversion from square number to its representative row and column
    unsigned short row = (square - 1) / 3;
    unsigned short col = (square - 1) % 3;
    
    //same logic as the previous setSquareSpa
    if (currentState.mBoard[row][col] == GameState::Empty) {
        currentState.mBoard[row][col] = state;
        return true;
    }
	return false;
}

char TicTacToeGame::getWinner()
{
    float checkForWinner = GetScore(currentState);
    char winner = ' ';
    
    //converts the winner into the char format - if there actually is one
    if (checkForWinner == -1.0) {
        winner = 'X';
    }
    if (checkForWinner == 1.0) {
        winner = 'O';
    }
    //if getWinner equals, check to see if there's a tie by going through all the tiles and checking if any are empty. (0 could either mean tie or unfinished game
    int empty = 0;
    if (checkForWinner == 0.0) {
        for (int col = 0; col < 3; col++) {
            //increase count for number of empty spaces each time an empty space is found
            for (int row = 0; row < 3; row++) {
                if (currentState.mBoard[row][col] == GameState::SquareState::Empty) {
                    empty += 1;
                }
            }
        }
        //after looking at all the spaces - if there's no empty spaces to be found (after there being no clear winner from the previous 4 set of if statements) then the game ends in a tie
        if (empty > 0) {
            winner = 'N';
        }
        else {
            winner = ' ';
        }
    }
    
	return winner;
}
