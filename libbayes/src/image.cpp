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

char Image::get(int row, int col){
    return image[row][col];
}



