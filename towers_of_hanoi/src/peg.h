// ITP 365 Spring 2020
// HW04 – Towers of Hanoi
// Name: Emily Zhu
// Email: emilyzhu@usc.edu
// Platform: Mac

#pragma once

#include "gwindow.h"
#include "disk.h"
#include <vector>

class Peg {
public:
    Peg();
    
    Peg(int x, int y, int width, int height);
    
    // draws the Peg and all of the Disks that are “on” that Peg. The Disks are to be drawn centered on their Peg.
    void draw(GWindow& gw);
    
    //  This function takes a Disk object as inpu*t. The Disk object that is passed into this function is to be added at the end of the Vector (for performance)
    void addDisk(Disk disk);
    
    //  This function is to remove the last Disk on that Peg and return it.
    Disk removeDisk();
    
private:
    std::vector<Disk> mDisksOnPeg;
    // X and Y coordinates represent the bottom middle coordinates of the disk
    int mPXCoor;
    int mPYCoor;
    int mPWidth;
    int mPHeight;
    std::string mPColor;
};
