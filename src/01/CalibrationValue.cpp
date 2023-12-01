//
// Created by Biancalani, M. (Massimo) on 01/12/2023.
//
#include "../utils/ReadFile.h"
#include "CalibrationValue.h"
using namespace std;
unsigned int  CalibrationValue::solution_part1(const std::string &input_file) {
    vector<string> lines = ReadFile::read_input_file(input_file);
    unsigned int res = 0;
    for (const auto& line:lines) {
        unsigned int num = get_number(line);
        res += num;
    }
    return res;
}

unsigned int CalibrationValue::get_number(const string &in) {
    unsigned int res = 0;
    for (char i : in) {
        if (isdigit(i)) {
            res += (i - '0')*10;
            break;
        }
    }

    for (int i = in.length() - 1; i >= 0 ; --i) {
        if (isdigit(in[i])) {
            res +=(in[i] - '0');
            break;
        }
    }

    return res;
}

unsigned int CalibrationValue::solution_part2(const string &input_file) {
    vector<string> lines = ReadFile::read_input_file(input_file);
    unsigned int res = 0;
    for (const auto& line:lines) {
       res += CalibrationValue::get_number_with_letter(line);
    }

    return res;
}

unsigned int CalibrationValue::get_number_with_letter(const string &in) {
    unsigned int res = 0;
    unsigned int temp_value;
    for (int i = 0; i < in.length(); ++i) {
        if (isdigit(in[i])) {
            res += (in[i] - '0')*10;
            break;
        } else if (CalibrationValue::get_number_by_letter(in, i, temp_value)) {
            res += temp_value*10;
            break;
        }
    }


    for (int i = in.length() - 1; i >= 0 ; --i) {
        if (isdigit(in[i])) {
            res +=(in[i] - '0');
            break;
        } else if (CalibrationValue::get_number_by_letter(in, i, temp_value)) {
            res += temp_value;
            break;
        }
    }

    return res;
}

bool CalibrationValue::get_number_by_letter(const string &in, size_t index, unsigned int &value) {
    if (in.substr(index, 3) == "one") {
        value = 1;
        return true;
    } else if (in.substr(index, 3) == "two") {
        value = 2;
        return true;
    } else if (in.substr(index, 5) == "three") {
        value = 3;
        return true;
    } else if (in.substr(index, 4) == "four") {
        value = 4;
        return true;
    } else if (in.substr(index, 4) == "five") {
        value = 5;
        return true;
    } else if (in.substr(index, 3) == "six") {
        value = 6;
        return true;
    } else if (in.substr(index, 5) == "seven") {
        value = 7;
        return true;
    } else if (in.substr(index, 5) == "eight") {
        value = 8;
        return true;
    } else if (in.substr(index, 4) == "nine") {
        value = 9;
        return true;
    }
    return false;
}
