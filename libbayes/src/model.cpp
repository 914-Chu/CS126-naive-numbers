#include "model.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

namespace training{


    vector<vector<vector<vector<double>>>> ComputeModel(vector<Image> images, vector<char> labels) {

        vector<vector<vector<vector<double>>>> prob(kIMAGE_SIZE,vector<vector<vector<double>>>
                (kIMAGE_SIZE, vector<vector<double>>(kNUM_CLASSES, vector<double>(kShade, 0.0))));

        vector<double> class_count = GetClassCount(labels, kNUM_CLASSES);
        vector<double> class_prob = GetClassProb(class_count, labels.size());


        for(int num = 0; num < kNUM_CLASSES; num++) {
            for(int index = 0; index < labels.size(); index++){
                if((labels[index] - '0') == num) {
                    Image image = images[index];
                    for(int row = 0; row < kIMAGE_SIZE; row++){
                        for(int col = 0; col < kIMAGE_SIZE;col++){
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

        for(int num = 0; num < kNUM_CLASSES; num++){
            for(int row = 0; row < kIMAGE_SIZE; row++){
                for(int col = 0; col < kIMAGE_SIZE; col++){
                    double shaded_total = prob[row][col][num][kShaded];
                    double not_shaded_total = prob[row][col][num][kNotShaded];
                    prob[row][col][num][kShaded] = (shaded_total + kLaplaceSmooth) / (2*kLaplaceSmooth + class_count[num]);
                    prob[row][col][num][kNotShaded] = (not_shaded_total + kLaplaceSmooth) / (2*kLaplaceSmooth + class_count[num]);
                }
            }
        }
    }

    vector<double> GetClassCount(vector<char> labels, int classes){

        vector<double> count(classes, 0);
        for(const auto &character : labels){
            int num = character - '0';
            labels[num]++;
        }
        return count;
    }

    vector<double> GetClassProb(const vector<double> &class_count, int total_label){

        vector<double> result(kNUM_CLASSES);
        transform(class_count.begin (), class_count.end (), result.begin (),
                  bind1st (divides<double>(),total_label));
        return result;
    }


}


