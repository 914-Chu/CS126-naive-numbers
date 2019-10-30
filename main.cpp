#include "image.hpp"
#include "fileprocess.h"
#include "model.hpp"
#include "classifying.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {


    vector<string> file_names = fileprocess::GetFileNames();
//    if(file_names.size() == 2) {
////        vector<Image> images = fileprocess::GetImages(fileprocess::ReadFile(file_names[0]));
////        vector<char> labels = fileprocess::GetLabels(fileprocess::ReadFile(file_names[1]));
////        Model *model = new Model(images, labels);
////        fileprocess::SaveModel(*model);
////    }else{
////        Model computed_model = fileprocess::GetModel(fileprocess::ReadFile(file_names[0]));
////        vector<Image> test_image = fileprocess::GetImages(fileprocess::ReadFile(file_names[1]));
////        vector<char> test_label = fileprocess::GetLabels(fileprocess::ReadFile(file_names[2]));
////        double accuracy = classifying::GetAccuracy(computed_model, test_image, test_label);
////    }

    vector<Image>  train_images =  fileprocess::GetImages(fileprocess::ReadFile(file_names[0]));
    vector<char> train_labels = fileprocess::GetLabels(fileprocess::ReadFile(file_names[1]));
    Model *model = new Model(train_images, train_labels);
    vector<Image>  test_images =  fileprocess::GetImages(fileprocess::ReadFile(file_names[2]));
    vector<char> test_labels = fileprocess::GetLabels(fileprocess::ReadFile(file_names[3]));
    double accuracy = classifying::GetAccuracy(model, test_images, test_labels);
    cout << accuracy << endl;

    return EXIT_SUCCESS;
}