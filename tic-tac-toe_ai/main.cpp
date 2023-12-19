#include "gwindow.h"
#include "tttgamedata.h"
#include "tttgame.h"
#include <iostream>
#include <string>
#include <sstream>

//returns the current state of the square to be used for printing the board
//get grid and turn to string
std::string drawBoard(GameState state) {
    std::stringstream ss;
    //state.mBoard[r][c];
    //remember to add new lines and tabs to center board
    // # = 3R + C + 1
    // r = (#-1)/3
    // c = (#-1) % 3
    
    //ensure spacing
    ss << "\n\n\n\n";
    for (int r = 0; r < 3; r++) {
        //tab in several times to center the board at the beginning of each row
        ss << "\t    ";
        for (int c = 0; c < 3; c++) {
            
            //this set of statements determine what to print out for the square space
            if (state.mBoard[r][c] == GameState::X) {
                ss << " X ";
            }
            else if (state.mBoard[r][c] == GameState::O) {
                ss << " O ";
            }
            else {
                //converting the row/column position of the square space to its respective number on the grid
                int squareSpace = (3 * r) + c + 1;
                ss << " " << squareSpace << " ";
            }
            // add the border that goes in between spaces in the same row, making sure not to add too many
            if (c < 2) {
                ss << "|";
            }
        }
        // add the border that goes in after each row is done, making sure to begin and end with new line
        if (r < 2) {
            ss << "\n\t    -----------\n";
        }
    }
    
    return ss.str();
}
int main(int argc, const char* argv[])
{
    bool isXTurn = true;
	// Terminal for the "screen"
	GTerminal term(400, 400);
	term.showCursor(false);
    
    TicTacToeGame theGame;
    
    unsigned short square;
    
    //keeps track of whether it's X's or O's turn
    GameState::SquareState playerTurn;
    
    char pressedKey;

    while (1)
    {
        term.clear();

        //checking for key presses
        while (term.hasEvents())
        {
            GEvent e = term.getEvent();
            if (e.Type == EventType::KeyDown)
            {
                int key = e.Event.Key.Code;
                if (key > '0' && key <= '9')
                {
                    square = key - '0';
                    pressedKey = key;
                }
                else if (key == '0')
                {
                    return 0;
                }
            }
        }
        std::stringstream ss;
        ss << drawBoard(theGame.getBoard());
        
        //check to see if there's a winner
        if(theGame.getWinner() != ' ' && theGame.getWinner() != 'N') {
            ss << "! ! ! ! ! ! ! ! ! ! ! ! ! " << theGame.getWinner() << " WINS!" <<
            " ! ! ! ! ! ! ! ! ! ! ! ! ! ";
            return 0;
        }
        
        ss << "\n\n\n\n___________________________________\n";

        //if the number of turns that have happened are 0, then it's X's turn. otherwise, it's O's turn (so every odd turn is for X and every even turn is for O).
        if(isXTurn) {
            playerTurn = GameState::SquareState::X;
        }
        else {
            playerTurn = GameState::SquareState::O;
        }
        
        ss << playerTurn << "'s move...";
                
        if (pressedKey) {
            // this will return true if we successfully set the state
            // if we successfully set the state then it's the next player's turn
            //make sure move is valid before switching 
        theGame.setSquareState(square, playerTurn);
        }
                
        term.appendText(ss.str());
        
        //advance turn
        isXTurn = !isXTurn;
        
        //program is pausing in between moves
        pause(6000);
    }
	return 0;
}
