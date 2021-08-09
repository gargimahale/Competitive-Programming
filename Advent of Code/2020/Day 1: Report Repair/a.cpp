#include <bits/stdc++.h>
using namespace std;

// 2-Sum

int main() {
    ifstream myfile("inp.txt");
    unordered_map<int, bool> U;
    int target = 2020;
    int input;
    while (myfile >> input) {
        if (U.find(target - input) != U.end()) {
            cout << input << " " << target - input << "\n";
            break;
        } else {
            U[input] = 1;
        }
    }
    return 0;
}