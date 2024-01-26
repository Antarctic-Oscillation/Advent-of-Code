#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int answer(0);
    
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) break;
    }
    
    std::cout << answer << std::endl;
    //-------------------------------------
    return 0;
}