#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> table{{"red", 12}, {"blue", 14}, {"green", 13}};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0);

    std::string line;
    while (std::getline(inputFile, line)) {
        bool condition = true;

        stringstream ss(line);
        string str;
        ss >> str >> str;
        int id = stoi(str.substr(0, str.length() - 1));

        while (ss >> str) {
            int num = stoi(str);

            string cube_color;
            ss >> cube_color;
            if (!isalpha(cube_color[cube_color.length() - 1])) {
                cube_color = cube_color.substr(0, cube_color.length() - 1);
            }
            
            if (table[cube_color] < num) {
                condition = false;
                break;
            }
        }
        if (condition) answer += id;
    }

    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}