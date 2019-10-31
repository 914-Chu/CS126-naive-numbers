#include "model.hpp"

#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

Model::Model(vector<Image> images, vector<char> labels) {

    vector<vector<vector<vector<double>>>> empty(kImageSize,vector<vector<vector<double>>>
            (kImageSize, vector<vector<double>>(kNumClasses, vector<double>(kShade, 0.0))));
    probs_ = empty;
    dataSize = labels.size();
    class_count_ = GenerateClassCount(labels);
    class_prob_ = GenerateClassProb();
    PixelCount(images,labels);
    CalculateProbs();
}

void Model::PixelCount(vector<Image> images, vector<char> labels) {

    for (int index = 0; index < labels.size(); index++) {
        int num = labels[index] - '0';
        Image image = images[index];
        for (int row = 0; row < kImageSize; row++) {
            for (int col = 0; col < kImageSize; col++) {
                if (image.get(row, col) == kNotShade) {
                    probs_[row][col][num][kNotShaded]++;
                } else {
                    probs_[row][col][num][kShaded]++;
                }
            }
        }
    }
}

void Model::CalculateProbs() {
    for(int num = 0; num < kNumClasses; num++){
        for(int row = 0; row < kImageSize; row++){
            for(int col = 0; col < kImageSize; col++){
                double shaded_total = probs_[row][col][num][kShaded];
                double not_shaded_total = probs_[row][col][num][kNotShaded];
                double smooth_shade = (shaded_total + kLaplaceSmooth)/(kShade*kLaplaceSmooth + class_count_[num]);
                double smooth_not_shade = (not_shaded_total + kLaplaceSmooth) / (kShade*kLaplaceSmooth + class_count_[num]);
                probs_[row][col][num][kShaded] = log10(smooth_shade);
                probs_[row][col][num][kNotShaded] = log10(smooth_not_shade);
            }
        }
    }

}

vector<double> Model::GenerateClassCount(vector<char> labels){

    vector<double> count(kNumClasses, 0);
    for(const auto &character : labels){
        int num = character - '0';
        count[num]++;
    }
    return count;
}

vector<double> Model::GenerateClassProb(){

    vector<double> result(kNumClasses);
    for(int num = 0; num < kNumClasses; num++){
        result[num] = log10(class_count_[num] / dataSize);
    }
    return result;
}

vector<vector<vector<vector<double>>>> Model::getProbs() const {
    return probs_;
}

vector<double> Model::getClassProb() const {
    return class_prob_;
}

void Model::setLaplaceSmooth(double num) {
    kLaplaceSmooth = num;
}

char Model::Classify(Image image) {

    vector<double> post_prob(kNumClasses);

    for(int num = 0; num < kNumClasses; num++) {
        double prob = class_prob_[num];
        for(int row = 0; row < kImageSize; row++) {
            for(int col = 0; col < kImageSize; col++) {
                if(image.get(row,col) == ' '){
                    prob += probs_[row][col][num][kNotShaded];
                }else{
                    prob += probs_[row][col][num][kShaded];
                }
            }
        }
    }
    return FindMax(post_prob);
}

char Model::FindMax(vector<double> post_prob) {

    double max = 0;
    char max_num_class;
    for(int num = 0; num < kNumClasses; num++){
        if(post_prob[num] > max){
            max = post_prob[num];
            max_num_class = static_cast<char>(num + '0');
        }
    }
    return max_num_class;
}

double Model::GetAccuracy(vector<Image> images, vector<char> labels){

    int match = 0;
    for(int index = 0; index < images.size(); index++){
        char predict = Classify(images[index]);
        if(predict == labels[index]){
            match++;
        }
    }
    return (match / images.size());
}

istream &operator>>(istream  &input, Model &model) {

    string file_name;
    input >> file_name;
    ifstream file(file_name);
    if(!file) {
        cout << "can't read from file." << endl;
    }

    for(int num = 0; num < kNumClasses; num++){
        file >> model.class_prob_[num];
    }
    for(int row = 0; row < kImageSize; row++) {
        for(int col = 0; col < kImageSize; col++) {
            for(int num = 0; num < kNumClasses; num++){
                for(int shade = 0; shade < kShade; shade++){
                    file >> model.probs_[row][col][num][shade];
                }
            }
        }
    }
    cout << "read successfully" << endl;
    return input;
}

ostream &operator<<(ostream &output, const Model &model) {

    for(int num = 0; num < kNumClasses; num++){
        output << model.class_prob_[num] << endl;
    }
    for(int row = 0; row < kImageSize; row++) {
        for(int col = 0; col < kImageSize; col++) {
            for(int num = 0; num < kNumClasses; num++){
                for(int shade = 0; shade < kShade; shade++){
                    output << model.probs_[row][col][num][shade] << endl;
                }
            }
        }
    }

    return output;
}


