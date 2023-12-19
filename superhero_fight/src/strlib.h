#pragma once

#include <string>
#include <vector>

// Name: 
//		strSplit
// Input:
//		1. A string (passed as constant reference) containing the string to split
//		2. A char containing the character to split on (the delimiter)
// Output: 
//		Vector of strings, with strings split around the delimiter (excluding the delimiter)
// Side effects: 
//		None
// Summary:
//		Splits the inputted string around the delimiter.
//		Returned vector will only have 1 string is there's no split
std::vector<std::string> strSplit(const std::string& str, char splitChar);

