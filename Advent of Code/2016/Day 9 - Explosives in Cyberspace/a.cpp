#include <bits/stdc++.h>
using namespace std;

int main() {
    const regex re{"\\((\\d+)x(\\d+)\\)"};
    smatch m;

    ifstream myFile("input.txt");

    string s; getline(myFile, s);
    size_t n = 0;
    for (auto c = s.cbegin(); c != s.cend(); /**/) {
        if (*c == '(') {
            regex_search(c, s.cend(), m, re);
            c += m.length();
            auto datalength  = static_cast<size_t>(stoi(m[1]));
            auto repetitions = static_cast<size_t>(stoi(m[2]));
            n += repetitions * datalength;
            c += datalength;
        } else {
            ++n;
            ++c;
        }
    }
    cout << "Count: " << n << endl;
    return 0;
}
