#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0);

    std::string line;
    while (std::getline(inputFile, line)) {
        stringstream ss(line);
        string input;
        ss >> input;
        ss >> input;

        int points = 0;
        unordered_set<int> winning_cards;

        while (ss >> input && input != "|") winning_cards.insert(stoi(input));
        while (ss >> input) {
            if (winning_cards.count(stoi(input)))
                points = (points == 0) ? points + 1 : points * 2;
        }
        answer += points;
    }

    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}