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
        vector<double> class_prob = class_count;
        transform(class_prob.begin (), class_prob.end (), class_prob.begin (),
                bind1st (divides<double>(),labels.size()));

        for(int num = 0; num < kNUM_CLASSES; num++) {
            for(int index = 0; index < labels.size(); index++){
                if((labels[index] - '0') == num) {

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



}


