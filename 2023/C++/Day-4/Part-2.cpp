#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int estimate_size(string file_name) {
    std::ifstream file(file_name);
    string line;
    std::getline(file, line);
    file.seekg(0, std::ios::end);
    return (static_cast<double>(file.tellg()) / line.length());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0);

    vector<int> master_array(estimate_size("input.txt") + 10, 1);
    std::string line;
    while (std::getline(inputFile, line)) {
        stringstream ss(line);
        string input;
        ss >> input;
        ss >> input;

        int index = stoi(input.substr(0, input.length() - 1)) - 1;
        int matches = 0;
        unordered_set<int> winning_cards;

        while (ss >> input && input != "|") winning_cards.insert(stoi(input));
        while (ss >> input)
            if (winning_cards.count(stoi(input))) ++matches;

        for (int _ = 0; _ < master_array[index]; ++_) {
            for (int i = 1; i <= matches; ++i) {
                master_array[index + i]++;
            }
        }
        answer += master_array[index];
    }

    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}