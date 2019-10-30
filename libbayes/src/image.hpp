#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

/*
 * We've given you a starter class to represent an image.
 */
using namespace std;
constexpr size_t kIMAGE_SIZE = 28;

class Image {

private:
    vector<vector<char>> image;

public:
    Image();
    ~Image(){};

    void set(int row, int col, char character);
    char get(int row, int col);
};
