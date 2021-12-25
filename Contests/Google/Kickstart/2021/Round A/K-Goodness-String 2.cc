#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;


void run_case(int test_case) {
    int N, K;
    cin >> N >> K;
    string str;
    cin >> str;

    int diff = 0;
    for (int i = 0; i < N/2; ++i){
    	diff += (str[i] != str[N-i-1]);
    }
    cout << "Case #" << test_case << ": " << abs(K-diff) << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i){
    	run_case(i);
    }
    return 0;
}
