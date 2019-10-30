#pragma once

#include "model.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace fileprocess {

    vector<string> GetFileNames();
    vector<Image> GetImages(vector<string> content);
    vector<char> GetLabels(vector<string> content);
    vector<vector<vector<vector<double>>>> GetModel(vector<string>);
    vector<string> ReadFile(string file_name);
}