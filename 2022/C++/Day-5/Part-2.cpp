#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

using std::vector, std::deque, std::string;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    string answer, line;
    std::getline(inputFile, line);
    inputFile.seekg(0);
    
    int line_length = line.length();
    int stack_n = (line_length + 1) / 4;
    vector<deque<char>> crates(stack_n);

    while (std::getline(inputFile, line) && !line.empty())
        for (int i = 0; i < line_length; ++i)
            if (std::isupper(line[i])) crates[(i - 1) / 4].push_front(line[i]);

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        int n, source, target;
        {
            std::string temp;
            ss >> temp >> n >> temp >> source >> temp >> target;
            --source;
            --target;
        }
        deque<char> auxiliary;
        for (int i = 0; i < n; ++i) {
            auxiliary.push_back(crates[source].back());
            crates[source].pop_back();
        }
        for (int i = 0; i < n; ++i) {
            crates[target].push_back(auxiliary.back());
            auxiliary.pop_back();
        }
    }

    for (const auto &dq : crates) answer += dq.back();
    std::cout << answer << '\n';
    //-------------------------------------
    return 0;
}