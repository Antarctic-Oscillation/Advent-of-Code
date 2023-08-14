#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool scenic_score(std::vector<std::vector<int>>& grid, int& row, int& col, int& n, int& m) {
    int height = grid[row][col];
    bool left(false), right(false), up(false), down(false);

    for (int i = col - 1; i >= 0 && !left; --i)
        if (grid[row][i] >= height) left = true;

    for (int i = col + 1; i < m && !right; ++i)
        if (grid[row][i] >= height) right = true;

    for (int i = row - 1; i >= 0 && !up; --i)
        if (grid[i][col] >= height) up = true;

    for (int i = row + 1; i < n && !down; ++i)
        if (grid[i][col] >= height) down = true;

    return left && right && up && down;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0), n(0);
    std::string line;
    std::vector<std::vector<int>> grid;
    while (getline(inputFile, line) && !line.empty()) {
        grid.emplace_back(line.length());
        transform(line.begin(), line.end(), grid[n++].begin(),
                  [](char c) { return int(c - '0'); });
    }
    for (int row = 0; row < n; row++)
        for (int col = 0, m = grid[0].size(); col < m; col++)
            if (!scenic_score(grid, row, col, n, m)) answer++;

    std::cout << answer << "\n";
    //-------------------------------------
    return 0;
}