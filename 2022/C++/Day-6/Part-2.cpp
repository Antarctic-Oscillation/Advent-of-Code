#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set>

constexpr int MARKER_LENGTH = 14;

bool hasUniqueElements(const std::string& str) {
    std::unordered_set<char> encounteredElements;
    for (char c : str) {
        if (encounteredElements.count(c)) {
            return false;
        }
        encounteredElements.insert(c);
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(MARKER_LENGTH);

    std::string line;
    std::getline(inputFile, line);
    std::string subStr = line.substr(0, MARKER_LENGTH);

    if (!hasUniqueElements(subStr)) {
        for (int i = MARKER_LENGTH, n = line.length(); i < n; ++i) {
            subStr = subStr.substr(1) + line[i];
            if (hasUniqueElements(subStr)) {
                answer = i + 1;
                break;
            }
        }
    }

    std::cout << answer << "\n";
    //-------------------------------------
    return 0;
}