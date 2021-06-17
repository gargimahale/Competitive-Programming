#include <bits/stdc++.h>

using namespace std;

bool confusingNumber(int N) {
    unordered_map<int, int> map = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
    int num = 0;
    int source = N;
    while (N > 0) {
        if (map.find(N % 10) == map.end()) {
            return false;
        }
        else {
            num = num * 10 + map[N % 10];
        }
        N /= 10;
    }
    return num != source;
}

int main(void) {
    cout << confusingNumber(89) << "\n";
}