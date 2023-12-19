#include <iostream>
#include <string>
#include <vector>

#include "gwindow.h"
#include "disk.h"
#include "peg.h"

//every function except for the last one basically uses the same logic of a while loop to ensure that the user is not typing any invalid input
int promptForDisks() {
    std::cout << "How many disks would you like to start out with? (2-10 inclusive)" << std::endl;
    int numDisks;
    std::cin >> numDisks;
    while(numDisks < 2 || numDisks > 10) {
        std::cout << "Not within valid range. Please choose a value from 2 through 10 inclusive." <<std::endl;
        std::cin >> numDisks;
    }
    return numDisks;
}

void promptForPegs(int& startP, int& endP) {
    int startPeg;
    std::cout << "Please indicate your starting peg number (1, 2, or 3)." << std::endl;
    std::cin >> startPeg;
    while(startPeg < 1 || startPeg > 3) {
        std::cout << "Not within valid range. Please choose a value from 1 through 3 inclusive." <<std::endl;
        std::cin >> startPeg;
    }
    startP = startPeg - 1;
    
    int endPeg;
    std::cout << "Please indicate your ending peg number - this cannot be the same as your starting peg number (1, 2, or 3)." << std::endl;
    std::cin >> endPeg;
    while(!(startPeg != endPeg && (endPeg > 1 || endPeg < 3))) {
        if(endPeg < 1 || endPeg > 3) {
            std::cout << "Not within valid range. Please choose a value from 1 through 3 inclusive." << std::endl;
            std::cin >> endPeg;
        }
        while(startPeg == endPeg) {
        std::cout << "The ending peg number cannot be the same as the starting peg number." << std::endl;
        std::cin >> endPeg;
        }
    }
    endP = endPeg - 1;
}

int promptForPause() {
    int pauseTime;
    std::cout << "Please indicate the number of milliseconds you would like to pause for (1 to 1000000 inclusive)." << std::endl;
    std::cin >> pauseTime;
    while(pauseTime < 1 || pauseTime > 1000000) {
        std::cout << "Not within valid range. Please choose a value from 1 through 1000000 inclusive." <<std::endl;
        std::cin >> pauseTime;
    }
    return pauseTime;
}

void promptForWindowSize(int &winWidth, int &winHeight) {
    int promptedWidth;
    std::cout << "Please enter the width of the window you with to create (800 to 4096 inclusive)." << std::endl;
    std::cin >> promptedWidth;
    while(promptedWidth < 800 || promptedWidth > 4096) {
        std::cout << "Not within valid range. Please choose a value from 800 through 4096 inclusive." <<std::endl;
        std::cin >> promptedWidth;
    }
    winWidth = promptedWidth;
    
    int promptedHeight;
    std::cout << "Please enter the height of the window you with to create (600 to 2160 inclusive)." << std::endl;
    std::cin >> promptedHeight;
    while(promptedHeight < 600 || promptedHeight > 2160) {
        std::cout << "Not within valid range. Please choose a value from 600 through 2160 inclusive." <<std::endl;
        std::cin >> promptedHeight;
    }
    winHeight = promptedHeight;
}

void draw(GWindow& gw, std::vector<Peg>& pegVec, int endPause) {
    gw.clear();
    for(int i = 0; i < pegVec.size(); i++) {
        gw.setColor("#000000");
        pegVec[i].draw(gw);
    }
    pause(endPause);
}

void moveDisk(GWindow& gw, std::vector<Peg>& vecOfPegs, int start, int end, int pauseLen) {
    //first line makes a deep copy and the line afterwards removes the copy, rather than the original. this means that the changes do not persist.
    //Peg startPeg = vecOfPegs[start];
    //Disk topDisk = startPeg.removeDisk();

    Disk topDisk = vecOfPegs[start].removeDisk();
    vecOfPegs[end].addDisk(topDisk);
    draw(gw, vecOfPegs, pauseLen);
}
// take six arguments: the GWindow object (by reference), the Peg collection (by reference), the starting Peg (represented with an int), the destination Peg (represented with an int), the number of disks to move, and the pause duration.
void towerSolver(GWindow& gw, std::vector <Peg>& vecOfPegs, int startPegNum, int endPegNum, int numtoMove, int pauseTime) {
    //The towerSolver is to use recursion and the moveDisk function to recursively move all the Disks from the source Peg to the target Peg.
    
    //since temp is not passed through in the function itself, we then determine the value of temp by using the values of the start and end pegs.
    //assuming that the pegs are: 0, 1, and 2, the total added up together are three and by subtracting the other two from the total gives us temp
    int tempPeg = 3 - startPegNum - endPegNum;
    
    //if there's no more disks left to move, then we end the function completely. basically the base case is that all of the disks are on the end peg
    if(numtoMove == 0) {
        return;
    }
    else {
        //the first call to towerSolver puts all of the disks onto the second peg. calling the towerSolver here and later on is the equivalent of breaking up the stack into smaller, solvable stacks
        towerSolver(gw, vecOfPegs, startPegNum, tempPeg, numtoMove - 1, pauseTime);
        //moveDisk moves the bottom disk from the start to the end after all the disks above the bottom disk have been moved to the temporary peg
        moveDisk(gw, vecOfPegs, startPegNum, endPegNum, pauseTime);
        //now we do the same thing as the first tower solver, except from the temp to the end.
        towerSolver(gw, vecOfPegs, tempPeg, endPegNum, numtoMove - 1, pauseTime);

        
    }
}
    
int main(int argc, const char* argv[])
{
    int diskNum = promptForDisks();
    
    int startPeg;
    int endPeg;
    promptForPegs(startPeg, endPeg);
    
    int pauseTime = promptForPause();

    int winWidth;
    int winHeight;
    promptForWindowSize(winWidth, winHeight);

    std::vector<Peg> vecOfPegs;
    
    for(int i = 0; i < 3; i++) {
        //first peg has coordinates at 1/6 of the screen witdth and then increment by 1/3 for each successive peg
        double xCoorDouble = (double)winWidth * 0.166666667 + 0.333333333 * (double)i * (double)winWidth;
        int xCoor = (int)xCoorDouble;
        vecOfPegs.push_back(Peg(xCoor, winHeight, 10, 500));
    }
    
    for(int i = 0; i < diskNum; i++) {
        int diskXCoor = (int)(0.166666667 * winWidth);
        int diskWidth = (int)((0.25 * winWidth) - (20 * i));
        //the subtraction done in winHeight accounts for the number of disks below the disk that's being added to the peg
        //thus we would need to subtract by the product of the height and the number of disks already on the peg
        vecOfPegs[0].addDisk(Disk(diskXCoor, winHeight - (40 * i), diskWidth, 40));
    }
    
    GWindow gw(winWidth, winHeight);
    
    draw(gw, vecOfPegs, pauseTime);
    
    towerSolver(gw, vecOfPegs, startPeg, endPeg, diskNum, pauseTime);

	return 0;
}


