#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int score(0);
    {
        std::unordered_map<std::string, int> outcomes = {
            {"A X", 3}, {"B X", 0}, {"C X", 6},
            {"A Y", 6}, {"B Y", 3}, {"C Y", 0},
            {"A Z", 0}, {"B Z", 6}, {"C Z", 3}
        };
        
        std::string round;
        while (std::getline(inputFile, round)) {
            if (round.empty()) break;
            switch (round.at(2)) {
                case 'X': score += 1; break;
                case 'Y': score += 2; break;
                case 'Z': score += 3; break;
            }
            score += outcomes[round];
        }
    }
    std::cout << score;
    //-------------------------------------
    return 0;
}