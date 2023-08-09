#include <set>
#include <string>
#include <fstream>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int priority_sum(0);

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) break;
        int mid = (line.length() / 2);

        std::set prefix(line.begin(), line.begin() + mid);
        std::set suffix(line.begin() + mid, line.end());

        for (char ch : prefix) {
            if (suffix.count(ch)) {
                priority_sum += (isupper(ch)) ? (ch - 38) : (ch - 96);
                break;
            }
        }
    }

    std::cout << priority_sum << "\n";
    //-------------------------------------
    return 0;
}