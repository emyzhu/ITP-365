#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "ITPMemLeaks.h"
#include "IMDBData.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("Student tests", "[student]") 
{
    SECTION("number of hops for Heath L and Jeanette Nolan") {
        IMDBData data("input/top250.list");
        data.createGraph();
        
        std::string line;
        std::istringstream firstLine(data.findRelationship("Heath Ledger", "Jeanette Nolan"));
        output = std::getline(firstLine, line);
        result = "Found a path! (3 hops)\n";
        
        REQUIRE(output == result);
    }
    
    SECTION("first actor is known, but not the second") {
        IMDBData data("input/top250.list");
        data.createGraph();
        
        std::istringstream firstLine(data.findRelationship("Gail Yudain", "Nicki Minaj"));
        std::string result = "Nicki Minaj is unknown!\n";
        
        REQUIRE(output == result);
    }
    
    SECTION("second actor is known, but not the first") {
        IMDBData data("input/top250.list");
        data.createGraph();
        
        std::istringstream firstLine(data.findRelationship("Nathan Greenfield", "Robert De Niro"));
        std::string result = "Nathan Greenfield is unknown!\n";
        
        REQUIRE(output == result);
    }
    
    SECTION("both actors are unknown") {
        IMDBData data("input/top250.list");
        data.createGraph();

        // Check for no relationship
        std::string result = "Kevin Bacon is unknown!\Nicki Minaj is unknown!\n";
        std::string output = data.findRelationship("Kevin Bacon", "Nicki Minaj");

        REQUIRE(result == output);
    }
    
    
}


