#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "movie.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    mFilmName = filmName;
    mFilm.clear();
    loadTape();
    rewind();
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    mFilm.clear();
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
    if(pos->mNext != nullptr) {
        ++pos;
        currFrameNum += 1;
    }
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
    if(pos->mPrev != nullptr) {
        --pos;
        currFrameNum -= 1;
    }
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    pos = mFilm.begin();
    currFrameNum = 1;
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
    //access the data in what is basically the current position of the iterator
    std::string theCurrFrame = *pos;
	return theCurrFrame;
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
    //pretty sure that the currFrameNum would still be the same
    if(pos->mNext != nullptr) {
    // sets the position to the next item
    pos = mFilm.erase(pos);
    }
    
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
    //get data from current frame
    //insert function is called with data passed thru
    mFilm.insert(pos,pos->mData);
    //position in this case would also remain unchanged because iterator is pointing to the inserted copy of the orignal frame
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    //if properly keeping track when rewinding, going fwd, back, etc, should just be able to return the number of frames you're on
	return currFrameNum;
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    return mFilm.size();
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
	return FRAMESIZE;
}

// Function: loadTape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
    std::ifstream fileInput(mFilmName);
    if (fileInput.is_open()) {
        while (fileInput.eof()!= true) {
            std::string line;

            //read separator line (get the separator number)
            std::getline(fileInput, line);
            //for when film gets to end - we're not adding anything extra then
            if (line.empty()) {
                return;
            }
            //number of times frame is stored in mFilm
            int numTimes;
            std::stringstream sep(line);
            sep >> numTimes;

            //put following lines into stingstream
            std::stringstream frame;
            //read in 13 lines (make 1 string)
            for (int i = 0; i < FRAMESIZE; i++) {
                std::getline(fileInput, line);
                // if the line ends with a backslash, add a space before a new line
                if(line.back() == '\\') {
                    frame << line << " \n";
                }
                //if there's no backslash, just go to the new line
                else {
                    frame << line << "\n";
                }
            }

            //insert n number of times
            for (int i = 0; i < numTimes; i++) {
                //store frames in mFilm
                mFilm.push_back(frame.str());
            }
        }
        fileInput.close();
    }
    else {
        throw std::invalid_argument("File not found");
    }
}

