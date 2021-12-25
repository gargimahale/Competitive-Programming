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

    vector<vector<int>>left(R, vector<int> (C, 0));
    vector<vector<int>>right(R, vector<int> (C, 0));
    vector<vector<int>>up(R, vector<int> (C, 0));
    vector<vector<int>>down(R, vector<int> (C, 0));

    for (int r = 0; r < R; ++r){
        for(int c = 0; c < C; ++c){
            left[r][c] = grid[r][c] == '1' ? (c > 0 ? left[r][c-1]: 0) + 1: 0;
            up[r][c] = grid[r][c] == '1' ? (r > 0 ? up[r-1][c] : 0) + 1: 0;
        }
    }

    for (int r = R-1; r >= 0; --r){
        for (int c = C-1; c >= 0; --c){
            right[r][c] = grid[r][c] == '1' ? (c < C-1 ? right[r][c+1] : 0) + 1: 0;
            down[r][c] = grid[r][c] == '1' ? (r < R-1 ? down[r+1][c] : 0) + 1: 0; 
        }
    }

    int64_t total = 0;

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            total += max(min(left[r][c], up[r][c] / 2) - 1, 0);
            total += max(min(up[r][c], right[r][c] / 2) - 1, 0);
            total += max(min(right[r][c], down[r][c] / 2) - 1, 0);
            total += max(min(down[r][c], left[r][c] / 2) - 1, 0);

            total += max(min(up[r][c], left[r][c] / 2) - 1, 0);
            total += max(min(right[r][c], up[r][c] / 2) - 1, 0);
            total += max(min(down[r][c], right[r][c] / 2) - 1, 0);
            total += max(min(left[r][c], down[r][c] / 2) - 1, 0);
        }

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
