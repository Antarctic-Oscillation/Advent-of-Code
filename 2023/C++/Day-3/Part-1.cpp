#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<char>> grid;
const vector<pair<int, int>> DIRECTIONS = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

const bool is_grid_symbol(int i, int j, int& n, int& m) {
    if (!(0 <= i && i < n && 0 <= j && j < m)) return false;
    return grid[i][j] != '.' && !isdigit(grid[i][j]);
}

const bool is_symbol_adjacent(int& i, int& j, int& n, int& m) {
    for (auto& dir : DIRECTIONS) {
        if (is_grid_symbol(i + dir.first, j + dir.second, n, m)) return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0);
    {
        std::string line;
        while (std::getline(inputFile, line)) {
            vector<char> chars;
            for (char& ch : line) {
                chars.emplace_back(ch);
            }
            grid.emplace_back(chars);
        }
    }
    for (int i = 0, n = grid.size(); i < n; ++i) {
        for (int j = 0, m = grid[0].size(); j < m; ++j) {
            string number;
            bool condition = false;
            while (isdigit(grid[i][j])) {
                number += grid[i][j];
                condition = condition || is_symbol_adjacent(i, j, n, m);
                ++j;
            }
            if (condition) answer += stoi(number);
        }
    }
    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}
