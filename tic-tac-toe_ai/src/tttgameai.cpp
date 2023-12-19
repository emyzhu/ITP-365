#include "tttgameai.h"

void GenStates(GTNode* root, bool xPlayer)
{
    //iterate over each square row and column
    //if the square is empty,
        //make a new node, set the state to root state, and if it's x's turn, set the empty to X, set the empty to O.

        //add the node to the children
        //genStates for that node we just added
    GameState::SquareState playerTurn = GameState::SquareState::O;
    if (xPlayer == true) {
        playerTurn = GameState::SquareState::X;
    }
    
        //A generate states function should iterate through all the positions of the board
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (root->mState.mBoard[r][c] == GameState::Empty) {
                //1. Generate a new child node
                GTNode* newChild;
                //2. Set child’s board to the root’s board
                newChild->mState = root->mState;
                //3. Set the empty position to the O (or the player’s symbol)
                root->mState.mBoard[r][c] = playerTurn;
                //4. Add the node as a child to root
                root->mChildren.push_back(newChild);
                //5. Generate the child nodes for this child
                xPlayer = !xPlayer;
                GenStates(newChild, xPlayer);
                }

        }

    }
}

float GetScore(const GameState& state)
{
    GameState::SquareState squareStateWinner = GameState::SquareState::Empty;
    
    //checks for winner - three in a row, horizontally by traversing through each row and seeing if the GameStates in each row are equal to each other.
    //also, the last condition in the following four if statements makes sure that the spot on the board is not empty
    for (int row = 0; row < 3; row++) {
        if (state.mBoard[row][0] == state.mBoard[row][1] &&
            state.mBoard[row][1] == state.mBoard[row][2] &&
            state.mBoard[row][0] != GameState::Empty) {
            squareStateWinner = state.mBoard[row][0];
        }
    }
    
    //checks for winner - three in a column, vertically by traversing through each row and seeing if the GameStates in each column are equal to each other.
    for (int col = 0; col < 3; col++) {
        if (state.mBoard[0][col] == state.mBoard[1][col] &&
            state.mBoard[1][col] == state.mBoard[2][col] &&
            state.mBoard[0][col] != GameState::Empty) {
            squareStateWinner = state.mBoard[0][col];
        }
    }
    
    //checks for winner - diagonally (\). checks if particular three spots are the same as one another
    if (state.mBoard[0][0] == state.mBoard[1][1] &&
        state.mBoard[1][1] == state.mBoard[2][2] &&
        state.mBoard[0][0] != GameState::Empty) {
        squareStateWinner = state.mBoard[0][0];
    }
    
    //checks for winner - diagonally (/). checks if particular three spots are the same as one another
    if (state.mBoard[0][2] == state.mBoard[1][1] &&
        state.mBoard[1][1] == state.mBoard[2][0] &&
        state.mBoard[0][0] != GameState::Empty) {
        squareStateWinner = state.mBoard[0][2];
    }


    //converts the winner into the char format - if there actually is one
    if (squareStateWinner == GameState::SquareState::X) {
        return -1.0;
    }
    if (squareStateWinner == GameState::SquareState::O) {
        return 1.0;
    }
    
    //basically if there's no winner, then it must be a tie (assuming that the game is over)
	return 0.0;
}

float MinPlayer(const GTNode* node)
{
	// TODO: IMPLEMENT
	return 0.0; // FIX RETURN VALUE
}

float MaxPlayer(const GTNode* node)
{
	// TODO: IMPLEMENT
	return 0.0; // FIX RETURN VALUE
}

const GTNode* MinimaxDecide(const GTNode* root)
{
	// TODO: IMPLEMENT
	return nullptr; // FIX RETURN VALUE
}

unsigned pickMove(const GameState& board)
{
	// TODO: IMPLEMENT
	return 0; // FIX RETURN VALUE
}
