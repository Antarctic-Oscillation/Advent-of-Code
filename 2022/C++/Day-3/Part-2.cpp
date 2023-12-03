#include <set>
#include <string>
#include <fstream>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int priority_sum (0);

    std::string line1, line2, line3;
    while (std::getline(inputFile, line1) && !line1.empty()) {
           std::getline(inputFile, line2);
           std::getline(inputFile, line3);

        std::set<char> line1Set(line1.begin(), line1.end());
        std::set<char> line2Set(line2.begin(), line2.end());
        std::set<char> line3Set(line3.begin(), line3.end());

        for (char ch : line1Set) {
            if (line2Set.count(ch) && line3Set.count(ch)) {
                priority_sum += (isupper(ch) ? (ch - 38) : (ch - 96));
                break;
            }
        }
    }

    std::cout << priority_sum << "\n";
    //-------------------------------------
    return 0;
}