//
// Created by Biancalani, M. (Massimo) on 01/12/2023.
//

#ifndef ADVENT_2023_CALIBRATIONVALUE_H
#define ADVENT_2023_CALIBRATIONVALUE_H

#include <string>
class CalibrationValue {
public:
    static unsigned int solution_part1(const std::string& input_file);

    static unsigned int solution_part2(const std::string& input_file);
private:
    static unsigned int get_number(const std::string &basicString);

    static unsigned int get_number_with_letter(const std::string &basicString);

    static bool get_number_by_letter(const std::string &basicString, size_t index, unsigned int& value);

};


#endif //ADVENT_2023_CALIBRATIONVALUE_H
