#ifndef ADVENT_OF_CODE2023_COMMON_H
#define ADVENT_OF_CODE2023_COMMON_H

#include <iostream>
#include <fstream>
#include <string>

std::fstream openFile(const std::string &filename) {
    std::fstream file{filename};

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
    }

    return file;
}

#endif //ADVENT_OF_CODE2023_COMMON_H
