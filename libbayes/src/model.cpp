#include "model.hpp"

#include <vector>
#include <cmath>

using namespace std;

Model::Model(vector<Image> images, vector<char> labels) {

    class_count = GenerateClassCount(labels, kNumClasses);
    class_prob = GenerateClassProb(class_count,labels.size());
    probs = ComputeModel(images,labels);
}

vector<vector<vector<vector<double>>>> Model::ComputeModel(vector<Image> images, vector<char> labels) {

    vector<vector<vector<vector<double>>>> prob(kImageSize,vector<vector<vector<double>>>
            (kImageSize, vector<vector<double>>(kNumClasses, vector<double>(kShade, 0.0))));


    for(int num = 0; num < kNumClasses; num++) {
        for(int index = 0; index < labels.size(); index++){
            if((labels[index] - '0') == num) {
                Image image = images[index];
                for(int row = 0; row < kImageSize; row++){
                    for(int col = 0; col < kImageSize; col++){
                        if(image.get(row, col) == ' ') {
                            prob[row][col][num][kNotShaded] ++;
                        }else{
                            prob[row][col][num][kShaded] ++;
                        }
                    }
                }
            }
        }
    }

    for(int num = 0; num < kNumClasses; num++){
        for(int row = 0; row < kImageSize; row++){
            for(int col = 0; col < kImageSize; col++){
                double shaded_total = prob[row][col][num][kShaded];
                double not_shaded_total = prob[row][col][num][kNotShaded];
                double smooth_shade = (shaded_total + kLaplaceSmooth)/(2*kLaplaceSmooth + class_count[num]);
                double smooth_not_shade = (not_shaded_total + kLaplaceSmooth) / (2*kLaplaceSmooth + class_count[num]);
                prob[row][col][num][kShaded] = log10(smooth_shade);
                prob[row][col][num][kNotShaded] = log10(smooth_not_shade);
            }
        }
    }

    return prob;
}

vector<double> Model::GenerateClassCount(vector<char> labels, int classes){

    vector<double> count(classes, 0);
    for(const auto &character : labels){
        int num = character - '0';
        count[num]++;
    }
    return count;
}

vector<double> Model::GenerateClassProb(const vector<double> &class_count, int total_label){

    vector<double> result(kNumClasses);
    for(int num = 0; num < kNumClasses; num++){
        result[num] = log10(class_count[num] / total_label);
    }
    return result;
}

vector<vector<vector<vector<double>>>> Model::getProbs() const {
    return probs;
}

vector<double> Model::getClassProb() const {
    return class_prob;
}

