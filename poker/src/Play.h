#pragma once

#include <iostream>
#include <string>

// Function: playPoker
// Purpose: Plays poker with IO from the inputted stream
// Input: An input stream, an output stream, a seed
// Returns: nothing
void playPoker(std::istream& in, std::ostream& out, unsigned seed);

// Function: playPoker
// Purpose: Creates File IO streams and calls the above function
// Input: An input file name, an output name, a seed
// Returns: nothing
void playPoker(const std::string& inFile, const std::string& outFile, unsigned seed);
