#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ios_base::sync_with_stdio(false);
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

    std::cout << max_sum;
    //-------------------------------------
    return 0;
}