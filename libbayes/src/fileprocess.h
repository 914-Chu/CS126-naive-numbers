#pragma once

#include "image.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace fileprocess {

    //Get each file's name from user input
    vector<string> GetFileNames();
    //Put all the images in a vector
    vector<Image> GetImages(vector<string> content);
    //Put all the labels in a vector
    vector<char> GetLabels(vector<string> content);
    //Read file content
    vector<string> ReadFile(string file_name);
//    void SaveModel(Model model);
//    Model GetModel(vector<string>);
}