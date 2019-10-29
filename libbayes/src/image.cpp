#include "image.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;


Image::Image() {
    vector<vector<char>> init(kIMAGE_SIZE, vector<char>(kIMAGE_SIZE));
    image = init;
}

void Image::set(int row, int col, char character){

    image[row][col] = character;
}


istream & operator >> (istream &in,  Image &image) {

    return in;
}

ostream & operator << (ostream &out, const Image &image){

    return out;
}



