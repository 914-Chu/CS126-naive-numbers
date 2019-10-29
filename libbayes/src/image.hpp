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
    vector<vector<char>>pixels;

public:
    Image(){};
    ~Image(){};

    friend istream & operator >> (istream &in,  Image &image);
    friend ostream & operator << (ostream &out, const Image &image);
};
