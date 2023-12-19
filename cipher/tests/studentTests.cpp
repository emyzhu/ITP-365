#include "catch.hpp"
#include "srcmain.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("Substitution Decrypt Tests", "[student]") 
{
    SECTION("Decrypt -- Simple")
    {
        const char* argv[] = {
            "dsub",
            "input/simple-enc.txt",
            "output/simple-clear-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/simple-clear-out.txt", "input/simple-clear.txt");
        REQUIRE(result);
    }

    // TODO: Add more decrypt test sections!

}

TEST_CASE("Substitution Encrypt Tests", "[student]") 
{

    SECTION("Encrypt -- Simple")
    {
        const char* argv[] = {
            "esub",
            "input/simple-clear.txt",
            "output/simple-enc-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/simple-enc-out.txt", "input/simple-enc.txt");
        REQUIRE(result);
    }

    // TODO: Add more encrypt test sections!

}


