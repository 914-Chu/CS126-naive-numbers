#include "image.hpp"

using namespace std;

Image::Image() {
    vector<vector<char>> init(kImageSize, vector<char>(kImageSize));
    image = init;
}

void Image::set(int row, int col, char character){

    image[row][col] = character;
}

char Image::get(int row, int col){
    return image[row][col];
}

ostream& operator<< (ostream& output, const Image& image) {

    for(int row = 0; row < kImageSize; row++) {
        for(int col = 0; col < kImageSize; col++) {
            output << image.image[row][col] << " ";
        }
        output << endl;
    }
    return output;
}



