// ITP 365 Spring 2020
// HW04 – Towers of Hanoi
// Name: Emily Zhu
// Email: emilyzhu@usc.edu
// Platform: Mac

#pragma once

#include "gwindow.h"

class Disk
{
public:
    //Default constuctor
    Disk();
    
    // parameterized constructor that sets x, y, width, and heigh for the Disk
    Disk(int x, int y, int width, int height);
    
    //setters for the x and y coordinates
    void setX(int x);
    
    void setY(int y);
    
    //returns the height of the disk
    int getDiskHeight();
    
    //draw function that accepts a GWindow (by reference). This function will use the GWindow and the member variables to create the colored rectangles that represent your Disks.
    void draw(GWindow& gw);
    
private:
    // X and Y coordinates represent the bottom middle coordinates of the peg
    int mXCoor;
    int mYCoor;
    int mWidth;
    int mHeight;
    std::string mColor;
};
