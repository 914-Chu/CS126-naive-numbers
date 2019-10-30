#pragma once

#include <vector>
#include <iostream>

/*
 * We've given you a starter class to represent an image.
 */
using namespace std;
const int kImageSize = 28;

class Image {

private:
    vector<vector<char>> image;

public:
    Image();
    ~Image(){};

    //set value at certain location of the image
    void set(int row, int col, char character);
    //get value at certain location of the image
    char get(int row, int col);
    //print out pixels for the image
    friend ostream& operator<<(ostream&, const Image&);
};
