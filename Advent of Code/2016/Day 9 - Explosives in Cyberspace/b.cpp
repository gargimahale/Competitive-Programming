#include <bits/stdc++.h>
using namespace std;

size_t expand(string::const_iterator c, size_t len) {
    static const regex re{"\\((\\d+)x(\\d+)\\)"};
    smatch m;
    size_t n = 0;
    auto cend = c + len;
    while (c != cend) {
        if (*c == '(') {
            regex_search(c, cend, m, re);
            c += m.length();
            auto datalength  = static_cast<size_t>(stoi(m[1]));
            auto repetitions = static_cast<size_t>(stoi(m[2]));
            n += repetitions * expand(c, datalength);
            c += datalength;
        } else {
            ++n;
            ++c;
        }
    }
    return n;
}

int main() {
    ifstream myFile("input.txt");
    string line; getline(myFile, line);
    cout << "Count: " << expand(line.cbegin(), line.size()) << endl;
    return 0;
}