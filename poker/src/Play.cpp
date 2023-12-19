#include "ITPVector.hpp"
#include "Cards.h"

#include <fstream>
#include <iostream>

// Function: playPoker
// Purpose: Plays poker with IO from the inputted stream
// Input: An input stream, an output stream, a seed
// Returns: nothing
void playPoker(std::istream& in, std::ostream& out, unsigned seed)
{
    std::srand(seed);
    std::string choice = "y";
    while(choice == "y") {
        ITPVector<Card> theDeck;

        // clear the deck and then create the deck again each time you run the loop
        //clear the deck after every turn
        theDeck.clear();
        
        //setting up the game by creating a deck of cards and a hand from said deck
        createDeck(theDeck);
        PokerHand theHand(theDeck);
        
        //output messages that match expected output; ties the operators in the Cards.cpp together
        out << "You drew: " << theHand << std::endl;
        out << "You have a " << theHand.getBestPokerHand() << std::endl;
        
        out << "Try again (y/n):";
        in >> choice;
    }
    
}

// Function: playPoker
// Purpose: Creates File IO streams and calls the above function
// Input: An input file name, an output name, a seed
// Returns: nothing
void playPoker(const std::string& inFile, const std::string& outFile, unsigned seed)
{
    //file input stream
    std::ifstream input(inFile);
    std::ofstream output(outFile);

    if (input.is_open()) {
        //until end of function, add each line to the data vector while the file is open
        playPoker(input, output, seed);
        input.close();
    }
    
}
