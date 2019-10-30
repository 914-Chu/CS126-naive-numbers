#include "classifying.h"

#include <vector>

using namespace std;


namespace classifying {


    char Classify(Image image, vector<vector<vector<vector<double>>>> model, vector<double> class_prob) {

        vector<double> post_prob(kNumClasses);

        for(int num = 0; num < kNumClasses; num++) {
            double prob = class_prob[num];
            for(int row = 0; row < kImageSize; row++) {
                for(int col = 0; col < kImageSize; col++) {
                    if(image.get(row,col) == ' '){
                        prob += model[row][col][num][kNotShaded];
                    }else{
                        prob += model[row][col][num][kShaded];
                    }
                }
            }
        }
        return FindMax(post_prob);
    }

    char FindMax(vector<double> post_prob) {

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
        return (match / images.size());
    }
}
