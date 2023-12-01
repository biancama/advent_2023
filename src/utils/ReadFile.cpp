//
// Created by Biancalani, M. (Massimo) on 01/12/2023.
//

#include "ReadFile.h"
#include <fstream>
#include <iostream>
using namespace std;
vector <string> ReadFile::read_input_file(const string& absolute_file_name) {
    vector<string> result;
    ifstream file;
    string line;
    file.open(absolute_file_name, ios_base::in);
    if (file.is_open()) {
        while ( getline(file, line) ) {
            result.push_back(line);
        }
    }
    file.close();
    return result;
}
