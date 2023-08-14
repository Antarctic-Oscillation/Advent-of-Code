#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define check(var, row, col, height) if (grid[row][col] >= height) {var++; break;} else var++

int scenic_score(std::vector<std::vector<int>>& grid, int& row, int& col, int& n, int& m) {
    int height = grid[row][col];
    int up = 0, down = 0, left = 0, right = 0;

    for (int i = col - 1; i >= 0; --i) check(left, row, i, height);
    for (int i = col + 1; i < m; ++i) check(right, row, i, height);
    for (int i = row - 1; i >= 0; --i) check(up, i, col, height);
    for (int i = row + 1; i < n; ++i) check(down, i, col, height);
    
    return up * down * left * right;
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
            answer = std::max(answer, scenic_score(grid, row, col, n, m));

    std::cout << answer << "\n";
    //-------------------------------------
    return 0;
}