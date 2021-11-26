#include <bits/stdc++.h>
using namespace std;

void P1(istream& input);
pair<uint32_t, uint32_t> parse(istream& input);
uint32_t coord2num(uint32_t row, uint32_t col);
uint64_t getnum(pair<uint32_t, uint32_t> target);

int main() {
    istringstream test1(R"(To continue, please consult the code grid in the manual.  Enter the code at row 3, column 2.)"); // p1: 8057251

    ifstream infile("input.txt");

    P1(infile);
}

void P1(istream& input) {

    auto target = parse(input);

    cout << "Code: " << getnum(target) << " for " << target.first << "," << target.second << endl;
}

pair<uint32_t, uint32_t> parse(istream& input) {

    regex re("row (\\d+), column (\\d+).$");
    smatch matches;

    string line;
    getline(input, line);

    if (!regex_search(line, matches, re)) {
        cout << "Failed on: " << line << endl;
        exit(1);
    }

    uint32_t row = stoi(matches[1].str());
    uint32_t column = stoi(matches[2].str());

    return make_pair(row, column);
}

uint64_t getnum(pair<uint32_t, uint32_t> target) {

    uint64_t value = 20151125;
    uint64_t mul = 252533;
    uint64_t div = 33554393;

    uint32_t loops = coord2num(target.first, target.second);

    while (--loops) {
        value = (value * mul) % div;
    }

    return value;
}

uint32_t coord2num(uint32_t row, uint32_t col) {

    return (col+row - 1) * (col+row - 2) / 2 + col;

    // return (col*(col+1) + (row-1)*(row-2)) / 2 + col*(row-1);

    // uint32_t result = 0;

    // for (uint32_t i = 1; i <= col; i++) {
    //     result += i;
    // }

    // for (uint32_t i = 0; i < row-1; i++) {
    //     result += col + i;
    // }

    // return result;
}