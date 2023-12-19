// ITP 365 Spring 2020
// HW04 – Towers of Hanoi
// Name: Emily Zhu
// Email: emilyzhu@usc.edu
// Platform: Mac

#include "peg.h"
#include <vector>

Peg::Peg() {
    mPXCoor = 0;
    mPYCoor = 0;
    mPWidth = 0;
    mPHeight = 0;
}

Peg::Peg(int x, int y, int width, int height) {
    mPXCoor = x;
    mPYCoor = y;
    mPWidth = width;
    mPHeight = height;
}

void Peg::draw(GWindow& gw) {    
    gw.fillRect(mPXCoor - (mPWidth / 2), mPYCoor - mPHeight, mPWidth, mPHeight);
    for(int i = 0; i < mDisksOnPeg.size(); i++) {
        mDisksOnPeg[i].draw(gw);
    }
}

void Peg::addDisk(Disk disk) {
    
    //set x to the peg's x coordinate
    disk.setX(mPXCoor);
    //to set the y coordinate for the incoming disk, we must account for height(s) of the disk(s) below as well - not just the y coordinate of the peg.
    disk.setY(mPYCoor - (mDisksOnPeg.size() * disk.getDiskHeight()));
    //add disk to vector
    mDisksOnPeg.push_back(disk);
}

Disk Peg::removeDisk() {
    Disk lastDiskOnPeg = mDisksOnPeg[mDisksOnPeg.size() - 1];
    mDisksOnPeg.pop_back();
    return lastDiskOnPeg;
}

