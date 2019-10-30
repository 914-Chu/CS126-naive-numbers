#pragma once

#include "image.hpp"
#include <vector>
/*
 * We've given you a starter struct to represent the model.
 * You are totally allowed to delete, change, move, rename, etc. this struct
 * however you like! In fact, we encourage it! It only exists as a starting
 * point of reference.
 *
 * In our probabilities array we have a final dimension [2], which represents
 * the individual probabilities that a pixel for a class is either shaded or
 * not shaded. Since the probability that a pixel is shaded is just
 * (1 - probability not shaded), we COULD have deleted that final dimension
 * (and you can do so if you want to), but we left it in so that you could
 * see how the model would need to change if we were to keep track of the
 * probability that a pixel is white vs. gray vs. dark gray vs. black.
 *
 * You can delete this comment once you're done with it.
 */

constexpr size_t kNUM_CLASSES = 10;  // 0-9 inclusive
constexpr size_t kShade = 2;
const int kShaded = 0;
const int kNotShaded = 1;
const double kLaplaceSmooth = 1;
/**
 * Represents a Naive Bayes classification model for determining the
 * likelihood that an individual pixel for an individual class is
 * white or black.
 */
struct Model {
    // The individual probabilities for each pixel for each class for
    // whether it's shaded or not.
    //
    // Examples:
    // probs[2][10][7][0] is the computed probability that a pixel at
    // [2][10] for class 7 is not shaded.
    //
    // probs[0][0][0][1] is the computed probability that a pixel at
    // [0][0] for class 0 is shaded.

    //double probs[kIMAGE_SIZE][kIMAGE_SIZE][kNUM_CLASSES][2];
    vector<vector<vector<vector<double>>>> probs;
};

namespace training{

    vector<vector<vector<vector<double>>>> ComputeModel(vector<Image> images, vector<char> labels);
    vector<double> GetClassCount(vector<char> labels, int classes);
    vector<double> GetClassProb(vector<double> class_count, int total_label);
}