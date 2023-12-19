// ITP 365 Spring 2020
// HW04 – Towers of Hanoi
// Name: Emily Zhu
// Email: emilyzhu@usc.edu
// Platform: Mac

#include "disk.h"
Disk::Disk() {
    mXCoor = 0;
    mYCoor = 0;
    mWidth = 0;
    mHeight = 0;
}

Disk::Disk(int x, int y, int width, int height) {
    mXCoor = x;
    mYCoor = y;
    mWidth = width;
    mHeight = height;

}

void Disk::setX(int x) {
    mXCoor = x;
}

void Disk::setY(int y) {
    mYCoor = y;
}

int Disk::getDiskHeight() {
    return mHeight;
}

void Disk::draw(GWindow& gw){
    gw.setColor("CYAN");
    // subtract half of the width from the XCoor for X origin to draw rectangle and subtract hieght from the YCoor for the same reason
    gw.fillRect(mXCoor - (mWidth / 2), mYCoor - mHeight, mWidth, mHeight);
}


