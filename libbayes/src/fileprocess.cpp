#include "fileprocess.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace fileprocess {

    vector<string> GetFileNames(){

        string input;
        cout << "Please enter file names." << endl;
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
        for(int line = 0; line < content.size(); line += kImageSize){
            Image *image = new Image();
            for(int row = 0; row < kImageSize; row++){
                for(int col = 0; col < kImageSize; col++){
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

    void SaveModel(Model model) {

        ofstream file("model.txt");
        if (file.is_open()) {
            file << model;
            file.close();
        }else {
            cout << "Unable to save file" << endl;
        }
    }

}
