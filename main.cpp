#include "image.hpp"
#include "fileprocess.h"
#include "model.hpp"
#include <sstream>
#include <iostream>

int main() {

    Model *model = new Model();
    string input;
    cout << "Please enter file names.";
    cin >> input;
    istringstream iss(input);
    vector<string> file_name;
    while (getline(iss, input, ' ')) {
        file_name.push_back(input);
    }

    if (file_name.size() == 2){

    }else if(file_name.size() == 3) {

    }else {
        cout << "Invalid input." << endl;
    }


    return EXIT_SUCCESS;
}