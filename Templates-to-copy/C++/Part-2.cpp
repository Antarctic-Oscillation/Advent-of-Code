#include <string>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ios_base::sync_with_stdio(false);
    //-------------------------------------
    int answer(0);
    {
        std::string line;
        while (std::getline(inputFile, line)) {
            if (line.empty()) break;
        }
    }
    std::cout << answer;
    //-------------------------------------
    return 0;
}