#include <vector>
using namespace std;

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
#include <string>
#include <vector>
using namespace std;


void run_case(int test_case) {
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for(auto& row: grid){
        for (int i = 0; i < C; ++i){
            string cell;
            cin >> cell;
            row += cell;
        }
    }

    int64_t total = 0;

    cout << "Case #" << test_case << ": " << total << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i){
    	run_case(i);
    }
    return 0;
}
