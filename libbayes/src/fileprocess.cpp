#include "fileprocess.h"
#include "model.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace fileprocess {

    istream &operator>>(istream &in, Model &model) {

        string line;
        char character;
        string image_file_name;
        string label_file_name;
        vector<string> images;
        vector<char> labels;

        in >> image_file_name;
        ifstream image_file(image_file_name);
        if (image_file.is_open()) {
            while ( getline (image_file,line) ) {
                images.push_back(line);
            }
            model.setLines(images);
            image_file.close();
        }

        in >> label_file_name;
        ifstream label_file(label_file_name);
        if(label_file.is_open()) {
            while(label_file.get(character)){
                labels.push_back(character);
            }
            label_file.close();
        }

        return in;
    }

    ostream &operator<<(ostream &out, const string &file_name) {


        return out;
    }

}
