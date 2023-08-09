#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Elf {
    std::string self;
    std::pair<int, int> interval;

    void setInterval() {
        std::size_t pos = self.find("-");
        interval.first = std::stoi(self.substr(0, pos));
        interval.second = std::stoi(self.substr(pos + 1));
    }
};

bool one_contains_other(const std::pair<int, int>& A,
                        const std::pair<int, int>& B) {
    if (B.first >= A.first && B.second <= A.second) {
        return true;
    } else if (A.first >= B.first && A.second <= B.second) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream inputFile("input.txt");
    //-------------------------------------
    int score(0);

    Elf elf1, elf2;
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) break;
        std::istringstream iss(line);
        std::getline(iss, elf1.self, ',');
        std::getline(iss, elf2.self);

        elf1.setInterval();
        elf2.setInterval();

        if (one_contains_other(elf1.interval, elf2.interval)) score++;
    }

    std::cout << score << std::endl;
    //-------------------------------------
    return 0;
}