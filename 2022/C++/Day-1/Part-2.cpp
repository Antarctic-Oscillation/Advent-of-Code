#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    //-------------------------------------
    int first(0), second(0), third(0);
    {
        std::string line;
        int sum(0);
        while (std::getline(inputFile, line)) {
            if (!line.empty()) {
                sum += std::stoi(line);
            } else {
                if (sum > first) {
                    third = second;
                    second = first;
                    first = sum;
                } else if (sum > second) {
                    third = second;
                    second = sum;
                } else if (sum > third) {
                    third = sum;
                }

                sum = 0;
            }
        }
        first = std::max(first, sum);
    }

    outputFile << first + second + third;
    //-------------------------------------
    return 0;
}