#include "catch.hpp"
#include "srcmain.h"

// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

static int grade = 0;

TEST_CASE("Substitution Cypher Decrypt Tests", "[graded]") 
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

        grade += 10;
    }
    SECTION("Decrypt -- Letter 01")
    {
        const char* argv[] = {
            "dsub",
            "input/letter1-enc.txt",
            "output/letter1-clear-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/letter1-clear-out.txt", "input/letter1-clear.txt");
        REQUIRE(result);

        grade += 10;
    }
    SECTION("Decrypt -- Letter 02")
    {
        const char* argv[] = {
            "dsub",
            "input/letter2-enc.txt",
            "output/letter2-clear-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/letter2-clear-out.txt", "input/letter2-clear.txt");
        REQUIRE(result);

        grade += 10;
    }
    SECTION("Decrypt -- Letter 03")
    {
        const char* argv[] = {
            "dsub",
            "input/letter3-enc.txt",
            "output/letter3-clear-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/letter3-clear-out.txt", "input/letter3-clear.txt");
        REQUIRE(result);

        grade += 10;
    }
}

TEST_CASE("Substitution Cypher Encrypt Tests", "[graded]") 
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

        grade += 10;
    }
    SECTION("Encrypt -- Letter 01")
    {
        const char* argv[] = {
            "esub",
            "input/letter1-clear.txt",
            "output/letter1-enc-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/letter1-enc-out.txt", "input/letter1-enc.txt");
        REQUIRE(result);

        grade += 10;
    }
    SECTION("Encrypt -- Letter 02")
    {
        const char* argv[] = {
            "esub",
            "input/letter2-clear.txt",
            "output/letter2-enc-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/letter2-enc-out.txt", "input/letter2-enc.txt");
        REQUIRE(result);

        grade += 10;
    }
    SECTION("Encrypt -- Letter 03")
    {
        const char* argv[] = {
            "esub",
            "input/letter3-clear.txt",
            "output/letter3-enc-out.txt"
        };

        ProcessCommandArgs(4, argv);
        bool result = CheckTextFilesSame("output/letter3-enc-out.txt", "input/letter3-enc.txt");
        REQUIRE(result);

        grade += 10;
    }
}

TEST_CASE("Test Cases Grade", "[graded]")
{
	WARN("****TEST CASES GRADE: " << grade << "/" << 80 << "****");
}





