#include "image.hpp"
#include "fileprocess.h"
#include "model.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include "fileprocess.h"

int main() {


    vector<string> file_names = fileprocess::GetFileNames();
    Model model;
    if(file_names.size() == 2) {
        vector<Image> images = fileprocess::GetImages(fileprocess::ReadFile(file_names[0]));
        vector<char> label = fileprocess::GetLabels(fileprocess::ReadFile(file_names[1]));
        model.probs = training::ComputeModel(images, label);
    }else{
        model.probs = fileprocess::GetModel(fileprocess::ReadFile(file_names[0]));
    }

    return EXIT_SUCCESS;
}