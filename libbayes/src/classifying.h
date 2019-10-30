#pragma once

#include "image.hpp"
#include "model.hpp"
#include <vector>

using namespace std;

namespace classifying {

    char Classify(Image image, vector<vector<vector<vector<double>>>> model, vector<double> class_prob);
    char FindMostLikelyClass(vector<double> post_prob);
    double GetAccuracy(Model model, vector<Image> images, vector<char> labels);
}