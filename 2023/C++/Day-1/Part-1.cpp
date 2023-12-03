#include <iostream>

char left(std::string& line, int& length) {
    for (int i = 0; i < length; ++i) 
        if (std::isdigit(line[i])) return line[i];
    return ' ';
}

char right(std::string& line, int& length) {
    for (int n = length - 1; n >= 0; --n) 
        if (std::isdigit(line[n])) return line[n];
    return ' ';
}

int find_calibration(std::string& line) {
    int length = line.length();
    std::string result(2, ' ');
    result[0] = left(line, length);
    result[1] = right(line, length);
    return std::stoi(result);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::freopen("input.txt", "r", stdin);
    //-------------------------------------
    int sum(0);
    std::string line;
    while (std::getline(std::cin, line)) {
        sum += find_calibration(line);
    }
    std::cout << sum << "\n";
    //-------------------------------------
    return 0;
}