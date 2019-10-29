#include "image.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

istream & operator >> (istream &in,  Image &image) {

    return in;
}

ostream & operator << (ostream &out, const Image &image){

    return out;
}

