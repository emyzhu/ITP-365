#include <iostream>

#include "fight.h"

int main(int argc, const char* argv[])
{    
	// Main function runs interactive mode
	// Input is CIN
	// Output is COUT
	// Seed is the current time in MS
	fight(std::cin, std::cout, time(nullptr));
	return 0;
}
