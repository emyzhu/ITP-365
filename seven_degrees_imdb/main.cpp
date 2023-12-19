#include <iostream>
#include <string>
#include <chrono>

#include "IMDBData.h"

// Option 1
// Function: moviesFromActor
// Purpose: Uses CIN and COUT to get an actor name from the user and 
// display the actor and the movies they've been in If the actor isn't in the map, 
// it will display that the actor is unknown
// Input: A populated IMDB data graph
// Side effects: Uses CIN and COUT to interact with the user.
// Returns: Nothing
void moviesFromActor(IMDBData& data)
{
    // basic i/o that asks user for the name of an actor to look up
    std::string actorName;
    std::cout << "Enter an actor's name \n>";
    // by default std::cin stops at the first whitespace (space, tab, or enter). std getline allows you to get an entire line of input
    std::getline(std::cin, actorName);
    std::cout << "\n--------------------------------------------------\n";
    
    //call to function in the IMDBData that returns the movies an actor has been in if the actor exists in tjhe data
    std::vector<std::string> movies = data.getMoviesFromActor(actorName);
    
    //if there's nothing in the vector, indicate that there's no movies the actor's been in
    if(movies.size() == 0) {
        std::cout << actorName << " is unknown!" << std::endl;;
        std::cout << "--------------------------------------------------" << std::endl;

    }
    else {
        std::cout << actorName << " has been in " << movies.size() << " movies: \n";
        //loop through vector of movies actor has been in and print out all of the titles
        for (int i = 0; i < movies.size(); i++) {
            std::cout << movies[i] << std::endl;
        }
        std::cout << "--------------------------------------------------" << std::endl;
    }
    
}

// Option 2
// Function: actorFromMovies
// Purpose: Uses CIN and COUT to get a movie name from the user and 
// display the movie and the actors they've been in If the movie isn't in the map, 
// it will display that the movie is unknown
// Input: A populated IMDB data graph
// Side effects: Uses CIN and COUT to interact with the user.
// Returns: Nothing
void actorFromMovies(IMDBData& data)
{
	// basic i/o that asks user for the name of an actor to look up
    std::string movieName;
    std::cout << "Enter a movie name \n>";
    // by default std::cin stops at the first whitespace (space, tab, or enter). std getline allows you to get an entire line of input
    std::getline(std::cin, movieName);
    std::cout << "\n--------------------------------------------------\n";
    
    //call to function in the IMDBData that returns the actors in the movie
    std::vector<std::string> actors = data.getActorsFromMovie(movieName);
    
    //if there's nothing in the vector, indicate that there's no movies the actor's been in
    if(actors.size() == 0) {
        std::cout << movieName << " is unknown!" << std::endl;;
        std::cout << "--------------------------------------------------" << std::endl;

    }
    else {
        std::cout << movieName << " had " << actors.size() << " actors: \n";
        //loop through vector of actors from a given movie and print out all of their names
        for (int i = 0; i < actors.size(); i++) {
            std::cout << actors[i] << std::endl;
        }
        std::cout << "--------------------------------------------------" << std::endl;
    }
}

// Option 3
// Function: relationship
// Purpose: Uses CIN and COUT to get 2 actor names
// Using the string returned from findRelationship displays the
// movies linking the 2 actors
// Input: A populated IMDB data graph
// Side effects: Uses CIN and COUT to interact with the user.
// Returns: Nothing
void relationship(IMDBData& data)
{
    std::string actor1;
    std::string actor2;
    
    std::cout << "Enter the first actor's name \n>";
    std::getline(std::cin, actor1);
    std::cout << "Enter the second actor's name \n>";
    std::getline(std::cin, actor2);
    std::cout << "\n--------------------------------------------------\n";
    std::cout << data.findRelationship(actor1, actor2);
    std::cout << "--------------------------------------------------" << std::endl;

}


int main(int argc, char** argv)
{
	std::cout << "Enter an actor file to load: " << std::endl;
	std::cout << "> ";
	std::string fname;
	std::getline(std::cin, fname);

	// Time out how long it takes to load the data
	std::cout << "Loading..." << std::endl;

	auto start = std::chrono::high_resolution_clock::now();

	IMDBData data(fname);

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	float seconds = duration / 1000000000.0f;

	std::cout << "Took " << seconds << "s\n";

	// Time out how long it takes to create the graph
	std::cout << "Creating graph..." << std::endl;

	start = std::chrono::high_resolution_clock::now();

	data.createGraph();

	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	seconds = duration / 1000000000.0f;

	std::cout << "Took " << seconds << "s\n";

	while (true)
	{
		std::cout << std::endl;
		std::cout << "Main Menu" << std::endl;
		std::cout << "1. Get movies from actor" << std::endl;
		std::cout << "2. Get actors from movies" << std::endl;
		std::cout << "3. Find relationship between actors" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << "> ";

		std::string option;
		std::getline(std::cin, option);

		if (option == "1")
		{
			moviesFromActor(data);
		}
		else if (option == "2")
		{
			actorFromMovies(data);
		}
		else if (option == "3")
		{
			relationship(data);
		}
		else if (option == "4")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid option, please try again." << std::endl;
		}
	}

	return 0;

}
