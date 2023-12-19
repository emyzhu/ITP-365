#include "IMDBData.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>

// Function: Default Constructor
// Purpose: Loads in the actor/movie file specified,
// and populates the data into the appropriate hash maps.
// Also constructs the graph with actor relationships.
// Input: Name of file to load (by reference)
// Returns: Nothing
IMDBData::IMDBData(const std::string& fileName)
{
    //keeping track of the current key so we can add multiple movies to a specific actor
    std::string actor;
    std::vector<std::string> movies;
    
    std::ifstream fileInput(fileName);
	if (fileInput.is_open()) {
        while (fileInput.eof()!= true) {
            std::string line;
            // grab the next line to be grabbed
            std::getline(fileInput, line);
            // if the first character in the line is '|', that means it's a movie aka a value. therefore, we add the movie to the movies vector associated with an actor
            if(line[0] == '|') {
                //push back the movie into the vector, but starting from the actual name of the movie rather than '|'
                movies.push_back(line.substr(1));
            }
            //otherwise, if it's not a movie, it must be a new actor, so we first add vector associated with previous actor (the key value pair) and then we can move onto the next actor and clear the vector for the next actor as well
            else {
                //creating an entry for the actor in the hash map
                mActorsToMoviesMap[actor] = movies;
                //call reverseMap on each actor to movie vector pair after populating the mActorToMoviesMap
                reverseMap(actor, movies);
                //be sure to clear the vector before taking in a new actor
                movies.clear();
                //moving onto the next actor because we're done with the previous actor
                actor = line;
            }
        } //end of while loop
        fileInput.close();
    } //out of file i/o
    else {
        std::cout << "Unable to load file \"" << fileName << "\"!" << std::endl;
    }
}

// Function: reverseMap
// Purpose: This is a helper function that is used to generate
// the reverse map (movies to actors)
// Input: Name of actor (by reference), vector of their movies (by reference)
// Returns: Nothing
void IMDBData::reverseMap(const std::string& actorName, const std::vector<std::string>& movies)
{
    //For each movie in the vector
    for (int i = 0; i < movies.size(); i++) {
        auto itr = mMoviesToActorsMap.find(movies[i]);
        
        // If mMoviesToActorsMap already contains the movie in question, you need to add actorName to that movie’s associated vector
        if(!(itr == mMoviesToActorsMap.end())) {
            itr->second.push_back(actorName);
        }
        // Otherwise, you need to add an entry in mMoviesToActorsMap that associates the movie with a vector that, for now, only contains actorName
        else {
            mMoviesToActorsMap[movies[i]] = std::vector<std::string>();
            mMoviesToActorsMap[movies[i]].push_back(actorName);
        }
    }
    
}

// Function: getMoviesFromActor
// Purpose: Given an actor's name, returns a vector containing their movies
// Input: Name of actor (by reference)
// Returns: Vector of movies (by reference)
const std::vector<std::string>& IMDBData::getMoviesFromActor(const std::string& actorName)
{
    auto itr = mActorsToMoviesMap.find(actorName);
    //if we have not (reached the end and found nothing...)
    if(!(itr == mActorsToMoviesMap.end())) {
        //itr->second has the value
        return itr->second;
    }
    
    //empty vector will be returned if the if statement isn't true and if the if statement is true, then the sEmptyVector will contain the movies the actor has been in
    return sEmptyVector;
}

// Function: getActorsFromMovie
// Purpose: Given a movie's name, returns the name of its actors
// Input: Name of movie (by reference)
// Returns: Vector of actors (by reference)
const std::vector<std::string>& IMDBData::getActorsFromMovie(const std::string& movieName)
{
    auto itr = mMoviesToActorsMap.find(movieName);
    //if we have not (reached the end and found nothing...)
    if(!(itr == mMoviesToActorsMap.end())) {
        //itr->second has the value
        return itr->second;
    }
    
    //empty vector will be returned if the if statement isn't true and if the if statement is true, then the sEmptyVector will contain the actors in the movie
    return sEmptyVector;
}

// Function: createGraph
// Purpose: This helper function constructs the IMDBGraph from the movie to actors map
// For each movie, it connects every actor in the film with the other actors in the film
// Input: None
// Returns: Nothing
void IMDBData::createGraph()
{
    // here we're iterating through all of the movies
    for(auto& pair : mMoviesToActorsMap) {
        const std::string& movieName = pair.first; // don't accdientally change
        const std::vector<std::string>& actors = mMoviesToActorsMap[movieName];
        
        //loop through all the actors
        for(int i = 0; i < actors.size(); i++) {
            ActorNode* actor1 = mGraph.getActorNode(actors[i]);
            // int j serves as the positon of the second actor, so we would do actors.size(), so we can include the final actor in the vector
            for (int j = i + 1; j < actors.size(); j++) {
               mGraph.createActorEdge(actor1, mGraph.getActorNode(actors[j]), movieName);
           }
            
        }
    }
}

// Function: findRelationship
// Purpose: Tries to find a relationship between two actors, using a BFS
// and returns a string with the result of the search.
// Input: Name of two actors to check for a relationship
// Returns: A string with the search results
std::string IMDBData::findRelationship(const std::string& fromActor, const std::string& toActor)
{
    std::stringstream ss;
    
    //make sure you check that the two actors passed to findRelationship are in the graph – if they aren’t you should cout an error message - tell which actor exactly does't exist
    if (!(mGraph.containsActor(fromActor))) {
        ss << fromActor << " is unknown!" << std::endl;
        if (!(mGraph.containsActor(toActor))) {
            ss << toActor << " is unknown!" << std::endl;
            return ss.str();
        }
        return ss.str();
    }
    
    // Create a queue of ITPGraphNode *
    std::queue <ActorNode*> actorQueue;
    //enqueue the node we’re starting from…
    
    // make two node pointers. one is fromActor other is toActor node. can enqueue the from and after node
    ActorNode* fromActorNode = mGraph.getActorNode(fromActor);
    ActorNode* toActorNode = mGraph.getActorNode(toActor);

    actorQueue.push(mGraph.getActorNode(fromActor));
    //while BFS queue is not empty
    while (actorQueue.size() != 0) {
        //save the front ActorNode* before dequeuing
        ActorNode* currentNode = actorQueue.front();
        //.pop the queue after you save the front ActorNode* in order to dequeue it.
        actorQueue.pop();
        
        //If currentNode is the target node, we found a path!
        //compare node pointer in if statement to see if node is toActor node
        if (currentNode == toActorNode) {
            ss << "Found a path! (" << toActorNode->mPath.size() << " hops)" << std::endl;
            ss << fromActorNode->mName << " was in..." << std::endl;
            for (int i = 0; i < toActorNode->mPath.size(); i++) {
                //this is for the toActor, whose output will be different since its the last item in the path
                if (i == toActorNode->mPath.size() - 1) {
                    ss << toActorNode->mPath[i].getMovieName() << " with " << toActorNode->mPath[i].getActorName() << std::endl;
                    mGraph.clearVisited();
                    return ss.str();
                }
                ss << toActorNode->mPath[i].getMovieName() << " with " << toActorNode->mPath[i].getActorName() << " who was in... " << std::endl;
            }
        }
        
        //if currentNode’s visited bool is false…
        // actor hasn't been visited so we need to do analysis
        if (currentNode->mIsVisited == false) {
            //Visit currentNode
            //Set currentNode’s visited bool to true
            currentNode->mIsVisited = true;
            //Loop through currentNode’s adjacency list (mEdges), and enqueue all adjacent nodes whose visited flag is false
            // pass by reference we don't want a copy!!!!!!!
            for(Edge& e : currentNode->mEdges) {
                if (e.mOtherActor->mIsVisited == false) {
                    actorQueue.push(e.mOtherActor);
                    //If the adjacent node path has a size of 0…
                    if (e.mOtherActor->mPath.size() == 0) {
                        //Set the adjacent node’s path equal to currentNode’s path
                        e.mOtherActor->mPath = currentNode->mPath;
                        //Push_back adjacent nodes’s name to adjacent node’s path
                        e.mOtherActor->mPath.push_back(PathPair(e.mMovieName, e.mOtherActor->mName));
                    }
                }
            }
        }
    }
    ss << "Didn't find a path!" << std::endl;
    mGraph.clearVisited();
	return ss.str();

}


// Leave here! Do not edit!!!
// DO NOT REMOVE THIS LINE
std::vector<std::string> IMDBData::sEmptyVector;
