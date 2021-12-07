#include <bits/stdc++.h>
using namespace std;

vector<uint64_t> split(string s, string del= " ") {
    vector<uint64_t> v;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        v.push_back(atoi(s.substr(start, end-start).c_str()));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back((uint64_t)atoi(s.substr(start, end-start).c_str()));
    return v;
}  

int main (void) {
    ifstream iss("input.txt");
    string line;
    vector<uint64_t> histogram(9,0);
    while (getline(iss, line)) {
        for (auto& n: split(line, ",")) {
            histogram[n]++;
        }
    }
    int days = 80;
    for (int i = 0; i < days; i++) {
        vector<uint64_t> tmp(histogram.begin() + 1, histogram.end());
        tmp[6] += histogram[0];
        tmp.push_back(histogram[0]);
        histogram = tmp;
    }

    uint64_t sum=0;
    cout << accumulate(histogram.begin(), histogram.end(), sum) << "\n";
}