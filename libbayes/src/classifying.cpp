#include "classifying.h"
#include "model.hpp"
#include <vector>

using namespace std;

namespace classifying {

    char Classify(Image image, vector<vector<vector<vector<double>>>> model, vector<double> class_prob) {

        vector<double> post_prob(kNUM_CLASSES);

        for(int num = 0; num < kNUM_CLASSES; num++) {
            double prob = class_prob[num];
            for(int row = 0; row < kIMAGE_SIZE; row++) {
                for(int col = 0; col < kIMAGE_SIZE; col++) {
                    if(image.get(row,col) == ' '){
                        prob += model[row][col][num][kNotShaded];
                    }else{
                        prob += model[row][col][num][kShaded];
                    }
                }
            }
        }
        return FindMostLikelyClass(post_prob);
    }

    char FindMostLikelyClass(vector<double> post_prob) {

        double max = 0;
        char max_num_class;
        for(int num = 0; num < kNUM_CLASSES; num++){
            if(post_prob[num] > max){
                max = post_prob[num];
                max_num_class = static_cast<char>(num - '0');
            }
        }
        return max_num_class;
    }

    double GetAccuracy(Model model, vector<Image> images, vector<char> labels){

        vector<vector<vector<vector<double>>>> prob = model.getProbs();
        vector<double> class_prob = model.getClassProb();
        int match = 0;
        for(int index = 0; index < images.size(); index++){
            char predict = Classify(images[index], prob, class_prob);
            if(predict == labels[index]){
                match++;
            }
        }
        return match / images.size();
    }
}
