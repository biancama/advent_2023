//
// Created by Biancalani, M. (Massimo) on 02/12/2023.
//

#include "CubeConundrum.h"
#include "../utils/ReadFile.h"
#include <regex>
#include <cstdio>
#include <iostream>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;
unsigned int CubeConundrum::solution(const std::string& file_name) {
    unsigned int res = 0;
    auto lines = ReadFile::read_input_file(file_name);
    char_separator<char> sep(";");
    for(const auto& line: lines) {
        tokenizer< char_separator<char> > tok(line, sep);
        bool isOk = true;
        for(auto beg= tok.begin(); beg != tok.end(); ++beg) {
            if (get_number_of_bags(*beg, "red") > 12 || get_number_of_bags(*beg, "green") > 13 || get_number_of_bags(*beg, "blue") > 14) {
                isOk = false;
                break;
            }
        }
            //
        // check for red
        if (isOk) {
            cout << "Line " << line << endl;
            res += get_game_index(line);
        }
    }
    return res;
}

unsigned int CubeConundrum::get_game_index(const std::string &in) {
    std::regex e ("^Game (\\d*).*$");
    std::smatch sm;
    std::regex_match (in.cbegin(), in.cend(), sm, e);
    return stoi(sm.str(1));
}

unsigned int CubeConundrum::get_number_of_bags(const string &in, const string& color) {
    unsigned int result = 0;
    auto fmt = "(([0-9]+ %s))";
    int sz = std::snprintf(nullptr, 0, fmt, color.c_str());
    vector<char> buf(sz + 1);
    sprintf(buf.data(), fmt, color.c_str());
    string regex_str(buf.begin(), buf.end() - 1);
    //string s ("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");
    regex rgx {regex_str};
    //regex e_t ("(.*)");

    smatch matches;
    string str(in);
    //auto t = regex_match (s, sm, e_t);
    while (std::regex_search(str, matches, rgx)) {
        string single_match = matches.str(1);
        str = matches.suffix();
        regex regex_str_for_number{"([0-9]+).*"};
        smatch sm_for_number;
        regex_match (single_match, sm_for_number, regex_str_for_number);
        result += stoi(sm_for_number.str(1));
    }

    return result;
}
