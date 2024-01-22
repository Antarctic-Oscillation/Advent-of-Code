#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0);

    std::string line;
    while (std::getline(inputFile, line)) {
        unordered_map<string, int> table{{"red", 0}, {"blue", 0}, {"green", 0}};

        stringstream ss(line);
        string str;
        ss >> str >> str;
        while (ss >> str) {
            int num = stoi(str);

            string cube_color;
            ss >> cube_color;
            if (!isalpha(cube_color[cube_color.length() - 1])) {
                cube_color = cube_color.substr(0, cube_color.length() - 1);
            }

            table[cube_color] = (table[cube_color] > num) ? table[cube_color] : num;
        }
        answer += std::accumulate(
            table.begin(), table.end(), 1,
            [](int accumulator, const pair<string, int>& element) {
                return accumulator * element.second;
            });
    }

    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}