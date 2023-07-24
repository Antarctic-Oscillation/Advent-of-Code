#include <map>
#include <array>
#include <fstream>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int score(0);
    {
        std::map<std::string, int> outcomes = {
            {"A X", 3}, {"A Y", 6}, {"A Z", 0},
            {"B X", 0}, {"B Y", 3}, {"B Z", 6},
            {"C X", 6}, {"C Y", 0}, {"C Z", 3}
        };
        std::map<char, std::array<char, 3>> choices = {
            {'A', {'Y', 'X', 'Z'}}, 
            {'B', {'Z', 'Y', 'X'}}, 
            {'C', {'X', 'Z', 'Y'}} 
        };
        std::map<char, int> scores = {{'X', 1}, {'Y', 2}, {'Z', 3}};

        std::string round;
        while (std::getline(inputFile, round)) {
            if (round.empty()) break;
            switch (round[2]) {
                case 'X': round[2] = choices[round[0]][2]; break;
                case 'Y': round[2] = choices[round[0]][1]; break;
                case 'Z': round[2] = choices[round[0]][0]; break;
            }
            score += scores[round[2]] + outcomes[round];
        }
    }
    std::cout << score;
    //-------------------------------------
    return 0;
}