//
// Created by Biancalani, M. (Massimo) on 02/12/2023.
//

#ifndef ADVENT_2023_CUBECONUNDRUM_H
#define ADVENT_2023_CUBECONUNDRUM_H
#include <string>

class CubeConundrum {
public:
    static unsigned int solution(const std::string & file_name);
private:
    static unsigned int get_game_index(const std::string& string);
    static unsigned int get_number_of_bags(const std::string& string, const std::string& color);
};

#endif //ADVENT_2023_CUBECONUNDRUM_H
