#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s, string del) {
    int start = 0;
    int end = s.find(del);
    vector<int> tokens;
    while (end != -1) {
        tokens.push_back(atoi(s.substr(start, end - start).c_str()));
        start = end + del.size();
        end = s.find(del, start);
    }
    tokens.push_back(atoi(s.substr(start, end - start).c_str()));
    return tokens;
}

int main(void) {
    string line;
    ifstream iss("input.txt");
    getline(iss, line);
    vector<int> positions = split(line, ",");
    int start = *min_element(positions.begin(), positions.end());
    int end = *max_element(positions.begin(), positions.end());
    // cout << start << " " << end << endl;
    int min_fuel = INT_MAX;
    for (int i = start; i <= end; ++i) {
        int fuel = 0;
        for (auto& n : positions)
            fuel += abs(n - i);
        if (fuel < min_fuel)
            min_fuel = fuel;
    }

    cout << min_fuel << endl;
}