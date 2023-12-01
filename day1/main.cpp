#include <iostream>
#include <string>
#include <array>
#include "common.h"

int part1();

int part2();

std::string findNumber(const std::string_view &str, const std::array<std::string, 9> &arr);

int main() {
    int sum = part1();
    int sum2 = part2();

    std::cout << "Sum part 1: " << sum << " Sum part 2: " << sum2 << std::endl;
    return 0;
}

// Part 1
int part1() {
    int sum{0};
    auto file = openFile("..\\day1\\input.txt");

    std::string line;
    while (std::getline(file, line)) {
        std::string firstDigit{};
        std::string lastDigit{};

        for (char ch: line) {
            if (std::isdigit(ch)) {
                if (firstDigit.empty()) {
                    firstDigit = ch;
                }
                lastDigit = ch;
            }
        }
        std::string number{firstDigit + lastDigit};
        int result{std::stoi(number)};
        sum += result;
    }

    return sum;
}

// Part 2
int part2() {
    std::array<std::string, 9> numbers{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int sum{0};
    auto file = openFile("..\\day1\\input.txt");

    std::string line;
    while (std::getline(file, line)) {
        std::string firstDigit{};
        std::string lastDigit{};
        std::string cumulativeDigit{};

        for (char ch: line) {
            if (std::isdigit(ch)) {
                if (firstDigit.empty()) {
                    firstDigit = ch;
                }
                lastDigit = ch;
                cumulativeDigit.clear();
            } else {
                cumulativeDigit += ch;
                std::string foundIndex = findNumber(cumulativeDigit, numbers);
                if (!foundIndex.empty()) {
                    if (firstDigit.empty()) {
                        firstDigit = foundIndex;
                    }
                    lastDigit = foundIndex;
                    cumulativeDigit.clear();
                }
            }
        }


        std::string number{firstDigit + lastDigit};
        int result{std::stoi(number)};
        sum += result;
    }

    return sum;
}

std::string findNumber(const std::string_view &str, const std::array<std::string, 9> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t found = str.find(arr[i]);
        if (found != std::string::npos) {
            return std::to_string(i + 1);
        }
    }

    return "";
}
