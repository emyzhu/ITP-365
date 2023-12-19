#include "catch.hpp"
#include "tttgame.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("tttgame", "the game setup is running smoothly")
{
    TicTacToeGame game;
    // TODO: Add tests here!
	SECTION("constructor")
	{
		REQUIRE(game.getBoard() == );
	}
}


