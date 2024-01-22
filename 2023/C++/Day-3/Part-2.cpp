#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<vector<char>> grid;
const vector<pair<int, int>> DIRECTIONS = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

bool is_grid_digit(int& i, int& j, int& n, int& m) {
    if (!(0 <= i && i < n && 0 <= j && j < m)) {
        return false;
    }
    return isdigit(grid[i][j]);
}

vector<int> get_adjacent_numbers(int& i, int& j, int& n, int& m) {
    map<pair<int, int>, bool> is_visited;
    for (auto& dir : DIRECTIONS)
        is_visited[make_pair(i + dir.first, j + dir.second)] = false;

    vector<int> result;
    for (auto& dir : DIRECTIONS) {
        string number;
        int di = i + dir.first;
        int dj = j + dir.second;
        bool valid = true;
        if (is_grid_digit(di, dj, n, m)) {
            is_visited[make_pair(di, dj)] = true;
            number += grid[di][dj];
            
            int temp = dj;
            while (is_grid_digit(di, --temp, n, m) && valid) {
                if (is_visited[make_pair(di, temp)]) valid = false;
                number = grid[di][temp] + number;
            }
            
            temp = dj;
            while (is_grid_digit(di, ++temp, n, m) && valid) {
                if (is_visited[make_pair(di, temp)]) valid = false;
                number += grid[di][temp];
            }
            
        }
        if (valid && !number.empty()) result.emplace_back(stoi(number));
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer = 0;
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
            if (grid[i][j] == '*') {
                vector<int> adjacent_numbers = get_adjacent_numbers(i, j, n, m);
                if (adjacent_numbers.size() == 2) {
                    answer += adjacent_numbers[0] * adjacent_numbers[1];
                }
            }
        }
    }
    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}
