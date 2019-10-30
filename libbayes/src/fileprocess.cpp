#include "fileprocess.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace fileprocess {

    vector<string> GetFileNames(){

        string input;
        cout << "Please enter file names.";
        cin >> input;
        istringstream iss(input);
        vector<string> file_name;
        while (getline(iss, input, ' ')) {
            file_name.push_back(input);
        }
        return file_name;
    }
    vector<Image> GetImages(vector<string> content) {

        vector<Image> images;
        for(int line = 0; line < content.size(); line+=kIMAGE_SIZE){
            Image *image = new Image();
            for(int row = 0; row < kIMAGE_SIZE; row++){
                for(int col = 0; col < kIMAGE_SIZE; col++){
                    image->set(row,col,content[row][col]);
                }
            }
            images.push_back(*image);
        }
        return images;
    }

    vector<char> GetLabels(vector<string> content) {

        vector<char> characters;
        for (int i=0; i<content.size(); i++) {
            characters.push_back(content[i][0]);
        }
        return characters;
    }

    vector<string> ReadFile(string file_name){

        vector<string> content;
        string line;
        ifstream file(file_name);
        if (file.is_open()) {
            while ( getline (file,line) ) {
                content.push_back(line);
            }
            file.close();
        }
        return content;
    }

//    void SaveModel(Model model) {
//
//
//    }
//
//    Model GetModel(vector<string> lines) {
//
//        vector<vector<vector<vector<double>>>> model(kIMAGE_SIZE,vector<vector<vector<double>>>
//                (kIMAGE_SIZE, vector<vector<double>>(kNUM_CLASSES, vector<double>(kShade, 0.0))));
//        for()
//    }
}
