#include <bits/stdc++.h>
using namespace std;

pair<string, string> split(string line, string del) {
    // string del = " -> ";
    int end_1 = line.find(del);
    int begin_2 = end_1 + del.size();
    string first = line.substr(0, end_1);
    string second = line.substr(begin_2, line.size()-begin_2);
    // cout << first << " " << second;
    pair<string, string> p = make_pair(first, second);
    return p;
}

void print_vector(vector<int> v) {
    for (auto& n: v) 
        cout << n << " ";
    cout << "\n";
}

void print_table(vector<vector<int>> table) {
    for (auto& v: table) 
        print_vector(v);
    cout << "\n";
}

int main(void) {
    string line;
    ifstream iss("input.txt");
    vector<vector<int>> grid;
    int limit = 1000;
    for (int i = 0; i < limit; i++) {
        vector<int> tmp;
        for (int j = 0; j < limit; j++) {
            tmp.push_back(0);
        }
        grid.push_back(tmp);
    }
    while (getline(iss, line)) {
        pair<string, string> p = split(line, " -> ");
        pair<string, string> left, right;
        left = split(p.first, ",");
        right = split(p.second, ",");
        int a_x = atoi(left.first.c_str());
        int a_y = atoi(left.second.c_str());
        int b_x = atoi(right.first.c_str());
        int b_y = atoi(right.second.c_str());
        // cout << a_x << " " << a_y << " " << b_x << " " << b_y << "\n";

        if (a_x == b_x) {
           int start = a_y < b_y ? a_y : b_y;
           int end = a_y > b_y ? a_y : b_y;
           for (int i = start; i <= end; i++) {
               grid[i][a_x] += 1;
           }
        }
        else if (a_y == b_y) {
           int start = a_x < b_x ? a_x : b_x;
           int end = a_x > b_x ? a_x : b_x;
           for (int i = start; i <= end; i++) {
               grid[a_y][i] += 1;
           }
        }
        else {
            int step_x = a_x < b_x ? 1 : -1;
            int step_y = a_y < b_y ? 1 : -1;
            int i = a_x, j = a_y;
            while (true) {
                grid[j][i]++;
                if (i == b_x) break;
                i += step_x;
                j += step_y;
            }
        }
    }

    int sum = 0;
    for (auto& line: grid) {
        for (auto& n: line) {
            if (n > 1) {
                sum++;
            }
        }
    }
    cout << sum << "\n";
}