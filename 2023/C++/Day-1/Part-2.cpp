#include <iostream>

char left(std::string& line, int& length) {
    for (int i = 0; i < length; ++i) {
        if (std::isdigit(line[i])) return line[i];
        switch (line[i]) {
            case 'o': {
                if (line.substr(i, 3) == "one") return '1';
            } break;
            case 't': {
                if (line.substr(i, 3) == "two") return '2';
                if (line.substr(i, 5) == "three") return '3';
            } break;
            case 'f': {
                if (line.substr(i, 4) == "four") return '4';
                if (line.substr(i, 4) == "five") return '5';
            } break;
            case 's': {
                if (line.substr(i, 3) == "six") return '6';
                if (line.substr(i, 5) == "seven") return '7';
            } break;
            case 'e': {
                if (line.substr(i, 5) == "eight") return '8';
            } break;
            case 'n': {
                if (line.substr(i, 4) == "nine") return '9';
            } break;
        }
    }
    return ' ';
}

char right(std::string& line, int& length) {
    for (int n = length; n > 0; --n) {
        if (std::isdigit(line[n - 1])) return line[n - 1];
        switch (line[n - 1]) {
            case 'e':
                if (n - 3 >= 0 && line.substr(n - 3, 3) == "one") return '1';
                if (n - 5 >= 0 && line.substr(n - 5, 5) == "three") return '3';
                if (n - 4 >= 0 && line.substr(n - 4, 4) == "five") return '5';
                if (n - 4 >= 0 && line.substr(n - 4, 4) == "nine") return '9';
                break;
            case 'o':
                if (n - 3 >= 0 && line.substr(n - 3, 3) == "two") return '2';
                break;
            case 'r':
                if (n - 4 >= 0 && line.substr(n - 4, 4) == "four") return '4';
                break;
            case 'x':
                if (n - 3 >= 0 && line.substr(n - 3, 3) == "six") return '6';
                break;
            case 'n':
                if (n - 5 >= 0 && line.substr(n - 5, 5) == "seven") return '7';
                break;
            case 't':
                if (n - 5 >= 0 && line.substr(n - 5, 5) == "eight") return '8';
                break;
        }
    }
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