#pragma once

#include "model.hpp"
#include "image.hpp"
#include <vector>

using namespace std;

namespace classifying {

    //Determine the most likely class
    char Classify(Image image, vector<vector<vector<vector<double>>>> model, vector<double> class_prob);
    //Find max probability
    char FindMax(vector<double> post_prob);
    //Calculate accuracy of classification
    double GetAccuracy(Model model, vector<Image> images, vector<char> labels);
}