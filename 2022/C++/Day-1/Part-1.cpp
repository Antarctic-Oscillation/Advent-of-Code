#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    //-------------------------------------
    int max_sum(0);
    {
        std::string line;
        int sum(0);
        while (std::getline(inputFile, line)) {
            if (!line.empty()) {
                sum += std::stoi(line);
            } else {
                max_sum = std::max(max_sum, sum);
                sum = 0;
            }
        }
        max_sum = std::max(max_sum, sum);
    }

    outputFile << max_sum;
    //-------------------------------------
    return 0;
}