#include "model.hpp"
#include "catch.hpp"
#include <cmath>

Model model;

TEST_CASE("GenerateClassCount") {

    vector<char> labels = {'3','4','4','7','5'};
    vector<double> expect = {0,0,0,1,2,1,0,1,0,0};
    int classes = 10;
    REQUIRE(expect == model.GenerateClassCount(labels,classes));
}

TEST_CASE("GenerateClassProb") {

    vector<double> class_count = {1,0,3,0,2,1,0,1,0,0};
    int total_label = 8;
    vector<double> class_prob = model.GenerateClassProb(class_count,total_label);
    REQUIRE(class_prob[2] == log10(3.0/8));
}

